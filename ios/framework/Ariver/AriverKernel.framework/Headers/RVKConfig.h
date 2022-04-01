//
//  RVKConfig.h
//  NebulaPoseidon
//
//  Created by chenwenhong on 15/10/12.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RVKLoggerProtocol;
@class WKWebViewConfiguration;
@protocol RVKViewDelegate;
@protocol RVKRenderPreloadProtocol;

@interface RVKConfig : NSObject

@property(nonatomic, readonly, copy) NSString      *sdkVersion;
@property(nonatomic, copy) NSString      *pluginsBundleName;
@property(nonatomic, copy) NSString      *extraPluginsFilePath;
@property(nonatomic, weak) id<RVKLoggerProtocol> logger;
@property(nonatomic, strong) WKWebViewConfiguration *wkConfiguration;
@property(nonatomic, assign) BOOL        shouldUseJSCInjctJS;
@property(nonatomic, assign) BOOL        shouldSyncWKCookie;
//@property(nonatomic, assign) BOOL        enableJsApiReapair;
//@property(nonatomic, assign) BOOL        enableCheckReadPlist;
@property(nonatomic, assign) BOOL        shouldUseNewMethodSyncWKCookie;
@property(nonatomic, assign) NSUInteger  maxRouterUrlLogLength;
@property(nonatomic, assign) BOOL        shouldCallJSAPIWithToken;
@property(nonatomic, assign) BOOL        shouldCallJSAPIWithService;
@property(nonatomic, copy) NSString      *rewriteBridgeContent;
@property(nonatomic, strong) NSArray     *jsapiBlackList; //register jsapi black list
@property(nonatomic, strong) NSArray     *pluginsBlackList; //register plugins black list
@property(nonatomic, strong) NSArray     *extensionsBlackList; //register extensions black list
@property(nonatomic, assign) BOOL        shouldUseUrlSchemeHandler; //iOS11 scheme handler
@property (nonatomic, assign) BOOL       isAppDebugMode;// APP 是否为调试模式

@property (nonatomic, weak) NSThread   *customURLProtocolThread;  //CustomURLProtocol线程

@property(nonatomic, assign) BOOL        shouldCancelInjctJS;
@property(nonatomic, assign) BOOL        shouldThrowJSExcuteException;
@property(nonatomic, assign) BOOL        shouldRVKViewDeallocUseMainThread;
@property(nonatomic, assign) BOOL        forceKernelSubObjectMainThreadDealloc;
@property(nonatomic, strong) NSArray<NSString *> *subObjectMainThreadDeallocKernelNames;
@property(nonatomic, assign) BOOL        shouldRedirectHSTS;
@property(nonatomic, weak) id<RVKViewDelegate>  rvkViewDelegate;
@property(nonatomic)    Class            rvkViewCls;
@property(nonatomic, assign) BOOL        shouldCustomRunJavaScript;
@property(nonatomic, copy) NSString      *customManageCookieRegx;
@property (nonatomic, assign) BOOL       shouldLogInURLProtocol;
@property (nonatomic, assign) BOOL       shouldFixAlertCrash;

@property (nonatomic, strong) id<RVKRenderPreloadProtocol> preloadService;

+ (instancetype)defaultConfig;

//禁止创建实例
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    RVKConfig * RVKConfigGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
