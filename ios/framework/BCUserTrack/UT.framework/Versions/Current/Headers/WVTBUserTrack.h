//
// WVTBUserTrack.h
// 
// UserTrack 
// 开发团队：数据通道团队 
// UT答疑群：11791581(钉钉) 
// UT埋点平台答疑群：11779226(钉钉) 
// 
// Copyright (c) 2014-2017 Taobao. All rights reserved. 
//
#ifdef nowv
#import <Foundation/Foundation.h>
#import <WindVane/WindVane.h>
//#import <WVPluginFramework/WVDynamicHandler.h>

@interface WVTBUserTrack : WVDynamicHandler

/**
 *  连接UT和H5的接口
 *
 *  @param data
 */
//+ (void)toUT:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

+ (void)toUT:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView<WVWebViewBasicProtocol> * ) webview withViewController:(UIViewController *) viewController;

+ (void)toUT2:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView<WVWebViewBasicProtocol> * ) webview withViewController:(UIViewController *) viewController;

/**
 *  运行时开始实时调试模式接口
 *
 *  @param data
 */
//+ (void)turnOnUTRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

/**
 *  运行时关闭实时调试模式接口
 *
 *  @param data
 */
//+ (void)turnOffUTRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

//+ (void)turnOnAppMonitorRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

//+ (void)turnOffAppMonitorRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

+ (void)turnOnRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;
+ (void)turnOnUTRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

+ (void)turnOffRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIView *) webview withViewController:(UIViewController *) viewController;

+ (NSDictionary *)GetPageUtparamToAplus;

+ (void)skipPage:(NSDictionary *)params withWVBridgeContext:(id<WVBridgeCallbackContext>)context;

@end

#endif
