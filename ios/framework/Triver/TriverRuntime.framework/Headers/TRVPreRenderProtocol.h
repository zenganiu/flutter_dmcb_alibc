//
//  TRVPreRenderProtocol.h
//  Runtime
//
//  Created by 岚遥 on 2020/1/20.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVRuntime.h"
#import <AriverKernel/RVKScene.h>
#import <AriverResource/RVRApp.h>

@protocol TRVPreRenderProtocol <NSObject>

@property (nonatomic, strong) TRVWebView *preRenderWebView; // 预渲染创建的 webView

/**
 @return 是否开启 render 预渲染开关
 */
- (BOOL)enableWebviewPreRender;

/**
 开始预渲染
 @param fromLaunch 是否为手淘启动的预渲染
 */
- (void)startPreRenderWebViewFromLaunch:(NSNumber *)fromLaunch;

/**
 获取已经完成资源预加载的预渲染 webView
 */
- (TRVWebView *)fetchPreloadWebview;

/**
 设置 url 的 hash
 @param preRenderUrlString   webView的完整 URL 字符串
 @param shopPrefetchData       店铺prefetch数据
 */
- (void)setupPreRenderUrlString:(NSString *)preRenderUrlString
               shopPrefetchData:(NSString *)shopPrefetchData;

/**
 设置是否使用了预渲染的 webView
 @param usePreRender 是否使用
 */
- (void)usingPreRenderWebView:(BOOL)usePreRender;

/**
 @return 判断是否使用了预渲染的 webView
 */
- (BOOL)usedPreRenderWebView;

/**
 @return 是否可以阻止第一次request
 */
- (BOOL)enablePreventFirstRequest;

/**
 清除无用 webView
 */
- (void)clearUnusedWebView;

/**
 设置webView不可使用
 */
- (void)countDownResource;

/**
 注入启动参数js
 @param scene 当前 view 的 parentObject
 */
- (void)configJSWithRVKScene:(RVKScene *)scene;

@end


// 预渲染 templateSnapshot html 资源下载
@protocol TRVPreRenderHTMLDownloadProtocol <NSObject>

/**
 手淘初始化加载 html 数据
 */
- (void)loadCachedData;

/**
 打开小程序时刷新 html 数据
 */
- (void)fetchHTMLData;

/**
 @return 预渲染 html数据字符串
 */
- (NSString *)preRenderHTMLDataString;

/**
 @return 返回当前预渲染的html版本号
 */
- (NSString *)currentTemplateSnapshotHTMLVersion;

/**
 @return 返回当前预加载 js 数据
 */
- (NSString *)preRenderTemplateJSDataString;

@end

@protocol TRVHTTPRequestCommitProtocol <NSObject>

- (void)commitPrefetchPageDataSuccessWithApp:(RVRApp *)app url:(NSString *)url;

- (void)commitFetchPageDataWithApp:(RVRApp *)app url:(NSString *)url timeCost:(NSNumber *)timeCost;

@end
