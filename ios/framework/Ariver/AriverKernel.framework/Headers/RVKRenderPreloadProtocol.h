//
//  RVKRenderPreloadProtocol.h
//  AriverKernel
//
//  Created by 岚遥 on 2019/12/24.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKContentView;
@class RVKView;
@class RVKSession;
@class RVKScene;
@protocol RVKRenderPreloadProtocol <NSObject>

@required

/**
 判断预渲染资源是否加载完成，以及预渲染 webView 是否可用
 @param appId 当前小程序 appId
*/
- (BOOL)checkAvailableForAppId:(NSString *)appId;

/**
 设置 render 与 native 的通信 messageHandler
 @param view 当前 webView 的容器 view
 */
- (void)configMessageHandlerWithRVKView:(RVKView *)view;

/**
 注入启动参数js
 @param scene 当前 view 的 parentObject
 */
- (void)configJSWithRVKScene:(RVKScene *)scene;

/**
 设置小程序的正确路径
 @param urlString 小程序当前page的url
 */
- (void)setupPreRenderWithCurrentSession:(RVKSession *)session urlString:(NSString *)urlString;

/**
 设置是否使用了预渲染的 webView
 @param needUse 是否使用
 */
- (void)usingPreRenderWebView:(BOOL)needUse;

/**
 @return 是否预渲染完成并且使用
 */
- (BOOL)usedPreRenderWebView;

/**
 @return 返回使用的是为只预创建的webView
 */
- (BOOL)isOnlyForPreCreate;

@end
