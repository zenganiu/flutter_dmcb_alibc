//
//  RVAWebPageProfile.h
//  AriverApp
//
//  Created by chenwenhong on 15/10/8.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>
#import <WebKit/WebKit.h>

#define kReportErrorRequest     @"errorRequest"
#define kReportErrorResponse    @"errorResponse"
#define kReportLongRender       @"longRender"
#define kReportErrorRender      @"errorRender"
#define kReportByUser           @"userReport"
#define kReportByJS             @"jsReport"

#pragma mark - Page状态定义
///
typedef enum {
    RVAContentViewPageProfileState_INITIAL = 0,
    RVAContentViewPageProfileState_START,
    RVAContentViewPageProfileState_COMPLETE,
    RVAContentViewPageProfileState_END,
} RVAContentViewPageProfileState;

@interface RVAContentViewPageProfile : NSObject

@property(nonatomic, copy) NSString *url;
@property(nonatomic, weak) RVKPage *psdPage;
@property(nonatomic, copy) NSString                     *performanceId; // nbl_id
@property(nonatomic, strong) NSURLRequest               *baseRequest; // webView请求的对象
@property(nonatomic, strong) NSURLRequest               *finalRequest;//webView最终的请求对象
@property(nonatomic, strong) NSURLRequest               *request; // 当前请求对象
@property(nonatomic, assign) WKNavigationType    navigationType; // 跳转类型
@property(nonatomic, readonly) RVAContentViewPageProfileState    state;
@property(nonatomic, copy) NSString                     *title; // 页面标题
@property(nonatomic, strong) NSError                    *error; // 错误
@property(nonatomic, copy) NSString                     *referer;
@property(nonatomic, assign) BOOL                       visible;
@property(nonatomic, assign) BOOL                       isLast;
@property(nonatomic, copy) NSString                     *pushingURLString;//pushwindow传递过来的url作为refer

@property(nonatomic, strong) NSDate                     *createDate;
@property(nonatomic, strong) NSDate                     *startDate; // 请求加载时间
@property(nonatomic, assign) NSTimeInterval startTime; // 开始请求时间
@property(nonatomic, assign) NSTimeInterval             firstAsyncRequestTime; // 统计页面第一个异步请求花费时间（验证服务器性能）
@property(nonatomic, strong) NSDate                     *renderDate; // webview改变contentSize的时间点，这个时间点开始渲染界面，由此大概推测首屏时间（非缓存页面一般是+0.4s，否则使用MIN(finishLoad的时间，该时间））
@property(nonatomic, strong) NSDate                     *firstScreenDate; // 最后一次稳定不变化时间（暂时为0）
@property(nonatomic, assign) NSTimeInterval             domReadyTime; // DOM ready时间（js配合统计），从startDate偏移的时间
@property(nonatomic, assign) NSTimeInterval             pageLoadTime; // page onload时间时间（js配合统计），从startDate偏移的时间
@property(nonatomic, strong) NSDate                     *completeDate; // 请求完成时间
@property(nonatomic, strong) NSDate                     *endDate; // 页面结束时间（返回、关闭）
@property(nonatomic, strong) NSDate                     *stopLoadingDate; // page onload之后，网络请求在一定时间内（2s内）不再发送，用于监测异步页面的性能
@property(nonatomic, strong) NSDate                     *didFinishedLoadDate;
@property(nonatomic, assign) NSTimeInterval             dnsTime; // timingAPI指标相关，不一定能统计到，需要看
@property(nonatomic, assign) float                      resourceCacheRate; // timingAPI的支持度，通过js注入统计
@property(nonatomic, assign) int                        jsErrorNumber; // 异常监控指标相关，js error监控
@property(nonatomic, readonly) RVKConnectionProfile     *profile;
@property(nonatomic, copy) NSString                     *telMCC;
@property(nonatomic, copy) NSString                     *telMNC;

@property(nonatomic, assign) int jsApiNum; // JSAPI调用数量
@property(nonatomic, copy)   NSString *jsApiNames; // JSAPI名称，格式是xxx|xxx|xxx
@property(nonatomic, assign)   NSTimeInterval containerVisibleTime; // 当前VC 第一次didAppear的时间


@property(nonatomic, strong) NSMutableDictionary        *extraJSReport;
@property(nonatomic, assign) BOOL                         isLocal;
@property(nonatomic, assign) BOOL                       fromHrefChange;            //href切换
@property(nonatomic, assign) BOOL                       didPreRender;              //经过预渲染标识
@property(nonatomic, assign) BOOL                       forceEnd;                  //因wk crash强制结束

@property(nonatomic, assign) BOOL canReportProfile;

@property(nonatomic, assign) BOOL isReport;
@property(nonatomic, copy)       NSString *fromType; // 页面打开类型　startApp/pushWindow/hrefChange


//PageLoad后统计
@property(nonatomic) int    cssLoadNum;
@property(nonatomic) int    jsLoadNum;
@property(nonatomic) int    imgLoadNum;
@property(nonatomic) int    otherLoadNum;
@property(nonatomic) int    requestLoadNum;
@property(nonatomic) float  mainDocHtmlLoadSize;
@property(nonatomic) float  cssLoadSize;
@property(nonatomic) float  jsLoadSize;
@property(nonatomic) float  imgLoadSize;
@property(nonatomic) float  otherLoadSize;
@property(nonatomic) float  pageLoadSize;
@property(nonatomic) int    sizeLoadLimit50;
@property(nonatomic) int    sizeLoadLimit200;
@property(nonatomic) int    imageSizeLoadLimit60;

- (BOOL)setState:(RVAContentViewPageProfileState)state;

- (void)mergeProfile:(RVKConnectionProfile *)profile;

- (void)reportJSMonitor:(NSArray *)monitorData;
- (void)reportJSReport:(NSArray *)monitorData;

- (void)reportValue:(id)value forKey:(NSString *) key;
- (id)getValueForKey:(NSString *) key;


// 由SDK内部在页面离开时上报
- (void)reportPerformance;
- (void)reportPageAbnormal;
- (void)reportPageAbnormalWithErrorType:(NSString *)errorType andErrorCode:(NSString *)errorCode;
- (void)reportPageAbnormalWithErrorType:(NSString *)errorType errorCode:(NSString *)errorCode errorMsg:(NSString *)errorMsg;
- (void)reportPageAbnormalWithErrorType:(NSString *)errorType withError:(NSError *)error;

@end
