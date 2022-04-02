/*
 * AlibcTradeUltimateSDKService.h
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeUltimateSDK
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

#import <AlibcTradeUltimateBizSDK/AlibcTradeShowParams.h>
#import <AlibcTradeUltimateBizSDK/AlibcTradeTaokeParams.h>
#import <AlibcTradeUltimateBizSDK/AlibcTradeUrlParams.h>

/*
 * trackParam 参数key说明
 */
#define track_scm @"scm"
#define track_pvid @"pvid"
#define track_isv_code @"isv_code"

extern NSString * const kAlibcTradeEventNotificaion;
extern NSString * const kAlibcTradeEventNotificaionName; // notificaion userInfo 事件名字
extern NSString * const kAlibcTradeEventNotificaionContent; // notificaion userInfo 事件内容

@protocol AlibcTradeUltimateSDKService <NSObject>

/**
 @param url 电商页面地址
 @param parentController 父视图
 @param showParams 页面打开方式自定义参数
 @param taoKeParams 淘客参数
 @param trackParam  链路跟踪参数
 @param openUrlCallBack 打开页面事件回调
 */

- (void)openTradeUrl:(NSString *)url
    parentController:(UIViewController *)parentController
          showParams:(AlibcTradeShowParams *)showParams
         taoKeParams:(AlibcTradeTaokeParams *)taoKeParams
          trackParam:(NSDictionary *)trackParam
     openUrlCallBack:(void (^)(NSError *error,NSDictionary *result))openUrlCallBack;

/**
 @param code 电商套件code
 @param parentController 父视图
 @param urlParams 电商套件业务传参
 @param showParams 页面打开方式自定义参数
 @param taoKeParams 淘客参数
 @param trackParam  链路跟踪参数
 @param openUrlCallBack 打开页面事件回调
 */

- (void)openTradePageByCode:(NSString *)code
           parentController:(UIViewController *)parentController
                  urlParams:(AlibcTradeUrlParams *)urlParams
                 showParams:(AlibcTradeShowParams *)showParams
                taoKeParams:(AlibcTradeTaokeParams *)taoKeParams
                 trackParam:(NSDictionary *)trackParam
            openUrlCallBack:(void (^)(NSError *error,NSDictionary *result))openUrlCallBack;

/**
 @brief TOP 授权。
 @param appKey 要授权的appKey,可选参数，默认会取当前应用的appkey
 @param appName 授权给当前客户端的名字
 @param appLogo 授权给当前客户端的图标
 @param currentVC 授权页面显示的当前VC (当前页面在tabbar上最好用tabbarController)
 @param callBack 授权信息回调 expires 单位秒
*/
- (void)authorize4AppKey:(NSString *)appKey
                 appName:(NSString *)appName
                  appLogo:(UIImage *)appLogo
                currentVC:(UIViewController *)currentVC
                 callBack:(void (^)(NSError *error,NSString *accessToken,NSString *expire))callBack;


@end
