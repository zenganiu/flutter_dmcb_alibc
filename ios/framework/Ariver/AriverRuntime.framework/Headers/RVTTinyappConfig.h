//
//  RVTTinyappConfiguration.h
//  AriverRuntime
//
//  Created by xuyouyang on 2019/3/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVTDefine.h"
#import <AriverKernel/AriverKernel.h>
#import <AriverResource/RVRApp.h>

#pragma mark - RVTTinyappConfigDelegate
@protocol RVTTinyappConfigDelegate <NSObject>

/**
 是否需要把事件同步到Worker
 
 @param eventName 事件名
 @param appId 所属appId
 @return YES,同步到Worker
 */
- (BOOL)shouldEventThroughWorker:(NSString *)eventName appId:(NSString *)appId;

/**
 ServiceWork UserAgent
 @return NSString
 */
- (NSString *)RVTSWUserAgent;

/**
 小程序框架资源的fallback地址
 @param url 小程序框架资源的url
 @return fallback地址
 */
- (NSURL *)getAppexFrameworkFallbackUrl:(NSString *)url;
- (NSURL *)getAppexFrameworkFallbackUrl:(NSString *)url session:(RVKSession *)session;

/**
 通过appId来查找一个RVRApp
 
 @param appid 小程序appId
 @return NAMApp 对象
 */
- (RVRApp *)findApp:(NSString *)appid;


/**
 可以通过某个key来查找已经持久化存储过的对象
 
 @param key 查询的key
 @param business 业务标识
 @return 持久化存储过的对象
 */
- (NSData *)getSavedDataWithKey:(NSString*)key business:(NSString*)business;
@end

#pragma mark - RVTTinyappDownLoadDelegate
@protocol RVTTinyDownLoadDelegate <NSObject>

/**
 传入一个包含url的字典来下载某个资源，回调资源的的本地路径
 @param data 下载的具体信息 @{@"url": targetUrl, @"appId": @"20000067"}
 @param callback 回调的结果 @{@"tempFilePath": tempFilePath}
 */
- (void)downLoadWithData:(NSDictionary *)data callback:(RVTDownloadCallback)callback;
@end

#pragma mark - RVTTinyappCustomFileManagerDelegate
@protocol RVTTinyappCustomFileManagerDelegate <NSObject>
/**
 按照AppId来清除小程序存储过的资源
 
 @param appId 当前小程序的appId
 */
- (void)clearAppTempFilesWithAppId:(NSString *)appId;
@end

#pragma mark - RVTTinyappRemoteDebugerDelegate
@protocol RVTTinyappRemoteDebugerDelegate <NSObject>
@required
/**
 远程执行JS
 
 @param javaScript 需要执行的js
 @param sourceURL 当前js关联的sourceURL
 @param onComplete js执行callback
 */
- (void)executeJavaScriptOnRemoteAgent:(NSString *)javaScript
							 sourceURL:(NSURL *)sourceURL
							onComplete:(RVTJavaScriptCallback)onComplete;


/**
 是否要开启调试模式
 
 @param session 当前session
 @return 是否要开启远程调试
 */
- (BOOL)shouldStartRemoteDebugerWithSession:(RVKSession *)session;
@end

@protocol RVTTinyappDebugDelegate <NSObject>
//同步jsapi调用超时时间，用于新的调试模式
- (NSTimeInterval)syncJsapiTimeoutValue:(NSDictionary *)params;
@end

@protocol RVTTinyappChInfoDelegate <NSObject>
- (void)configStartupParams:(NSDictionary *)params withAppId:(NSString *)appId;
@end

@protocol RVTTinyappCanvasDelegate <NSObject>
- (void)configStartupParams:(NSDictionary *)params withAppId:(NSString *)appId;
@end


@interface RVTTinyappConfig : NSObject

@property(nonatomic, weak)      id<RVTTinyappConfigDelegate>                 tinyappConfigDelegate;
@property(nonatomic, weak)      id<RVTTinyDownLoadDelegate>                  tinyDownLoadDelegate;
@property(nonatomic, weak)      id<RVTTinyappCustomFileManagerDelegate>      tinyappCustomFileManagerDelegate;
@property(nonatomic, weak)      id<RVTTinyappRemoteDebugerDelegate>          tinyappRemoteDebugerDelegate;
@property(nonatomic, weak)      id<RVTTinyappDebugDelegate>                  tinyappDebugDelegate;
@property (nonatomic, weak)     id<RVTTinyappChInfoDelegate>                 tinyappChInfoDelegate;
@property (nonatomic, weak)     id<RVTTinyappCanvasDelegate>                 tinyappCanvasDelegate;
@property(nonatomic, copy)      NSString                                    *JSCBridgeFilePath;// 默认值为：AriverRuntime.bundle/H5JSCBridge.js
@property(nonatomic)            Class                                       tinyappViewControllerCls; // 容器的 VC

//10.1.35是否启用同层渲染
@property(nonatomic, assign)    BOOL                                        tinyappShouldUseInpageRender;
//10.1.35是否启用同层渲染的类型
@property(nonatomic, copy)    NSArray                                       *tinyappUseInpageRenderTypes;
//10.1.35同层渲染appId
@property(nonatomic, copy)    NSArray                                       *tinyappUseInpageRenderappIds;
//10.1.38同层渲染黑名单
@property(nonatomic, copy)    NSArray                                       *tinyappUseInpageRenderBlackList;
//10.1.38同层渲染组件黑名单
@property(nonatomic, copy)    NSArray                                       *tinyappInpageRenderComponentBlackList;
@property(nonatomic, copy)    NSArray                                       *tinyInpageRenderGesViewCls;
@property(nonatomic, copy)    NSDictionary                                  *tinyEventThroughWorkerConfig;
//10.1.55为了兼容Swiper闪的问题，直接同层的appId列表
@property(nonatomic, copy)    NSArray                                   *tinyInpageRenderDirectRenderList;
@property(nonatomic, assign)  NSInteger  workerLimitCount;
@property(nonatomic, assign)  BOOL                                          syncJsapiSupportTimeout;
//10.1.80注入插件context的一些额外JS,可用来修复bug
@property(nonatomic, copy)    NSString                                      *extraJSForPluginContext;
//10.1.80注入主context的一些额外JS,可用来修复插件bug
@property(nonatomic, copy)    NSString                                      *extraJSForMainContext;
//10.1.82额外的一些对象暴露给其他Context
@property(nonatomic, copy)    NSArray<NSString *>                           *extraImportNames;
//10.1.92woker是否同步释放
@property(nonatomic, assign)  BOOL                                          shouldWorkerDeallocSync;
@end


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	
	RVTTinyappConfig * RVTTinyappConfigGet();
	
#ifdef __cplusplus
}
#endif // __cplusplus

