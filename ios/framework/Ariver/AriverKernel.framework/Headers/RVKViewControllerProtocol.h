//
//  RVKViewControllerProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14-9-3.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class RVKSceneParam;
@class RVKView;
@class RVKScene;
@class RVKSession;
@class RVKContentView;
@class WKUserScript;

@protocol RVKViewControllerDelegate;

@protocol RVKViewControllerProtocol <NSObject>

@optional

- (NSArray *)dyJsUrls; // 动态注入js数组

- (NSString *)startupParamsJs; // 启动参数js

- (NSString *)codeSnippets4InsertAlipayJsBridgeFile; // 动态插入js片段；该方法是在插入js之前修改js文件

- (void)startFirstLoadRequest:(NSURL *)url; // 如果实现了该方法，需要自己loadRequest；该方法是第一次进入页面发起的请求

- (NSArray<WKUserScript *> *)independenceUserScripts; // RVKWebViewUserScript

- (NSArray *)relayOnAlipayJsBridgeUserScripts; // RVKWebViewUserScript

- (void)injctIndependenceJs; // 注入单独的JS文件

- (void)injctJsRelyOnAlipayJsBridge; // 依赖于AlipayJSBridge

- (BOOL)shouldSkipHandleLoadWithRequest:(NSURLRequest *)request navigationType:(__unused WKNavigationType)navigationType;

- (void)associateWeakScene:(RVKScene *)scene sceneParam:(RVKSceneParam *)sceneParam; // scene请用weak引用

- (void)initUI:(RVKView *)contentView delegate:(id<RVKViewControllerDelegate>)delegate;

- (RVKScene *)rvkScene;

- (RVKSession *)rvkSession;

- (RVKView *)rvkView;

- (RVKContentView *)rvkContentView;

- (UIViewController *)viewController;

- (void)callHandler:(NSString *)handlerName
             data:(id)data
 responseCallback:(void(^)(id responseData))callback;

- (void)callHandler:(NSString *)handlerName
             data:(id)data
callbackImmediatelyIfJSBridgeNotReady:(BOOL)callbackImmediatelyIfJSBridgeNotReady
 responseCallback:(void (^)(id responseData))callback;

//lifecycle
- (void)rvk_loadView;

- (void)rvk_viewDidLoad;

- (void)rvk_viewWillAppear:(BOOL)animated;

- (void)rvk_viewDidAppear:(BOOL)animated;

- (void)rvk_viewWillDisappear:(BOOL)animated;

- (void)rvk_viewDidDisappear:(BOOL)animated;

- (void)rvk_viewDidLayoutSubviews;

- (void)rvk_dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion;

- (void)rvk_presentViewController:(UIViewController *)viewController animated:(BOOL)flag completion:(void (^)(void))completion;

- (UINavigationController *)rvk_customNavigationController;

- (UIView *)rvk_customNavigationBar;

@end

//VC类代理接口
@protocol RVKViewControllerDelegate <NSObject>

- (void)viewController:(UIViewController *)vc loadView:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidLoad:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidUnLoad:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewWillAppear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidAppear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidLayoutSubviews:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewWillDisappear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewDidDisappear:(BOOL)_;

- (void)viewController:(UIViewController *)vc viewWillDestroy:(BOOL)_;

@end
