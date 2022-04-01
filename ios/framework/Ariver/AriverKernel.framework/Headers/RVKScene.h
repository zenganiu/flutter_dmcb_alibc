//
//  RVKScene.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKKernel.h"
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class RVKSceneParam;
@class RVKSession;
@class RVKView;

//Scene类：类似一个ViewController。
@interface RVKScene : RVKKernel

@property(nonatomic, strong) RVKView *rvkView;

- (RVKSceneParam *)createParam;

- (UIViewController *)viewController;

- (NSArray *)dyJsUrls;

- (NSString *)startupParamsJs;

- (NSString *)codeSnippets4InsertAlipayJsBridgeFile;

- (NSArray<WKUserScript *> *)independenceUserScripts;

- (NSArray *)relayOnAlipayJsBridgeUserScripts;

- (void)injctIndependenceJs; // 注入单独的JS文件

- (void)injctJsRelyOnAlipayJsBridge; // 依赖于AlipayJSBridge
/**
 *  @brief 给定一个sceneParam参数，创建一个Scene对象，该Scene对象包含一个View对象
 *
 *  @date 2014-08-08
 *
 *  @param sceneParam 要创建所需要的参数，不能为nil
 *
 *  @return 返回Scene对象
 */
+ (instancetype)sceneWithSceneParam:(RVKSceneParam *)sceneParam parentObject:(RVKKernel *)parentObject;

@end


/**
 *  @brief 创建Scene的参数类
 *
 *  @date 2014-08-08
 *
 *  @return 无
 */
@interface RVKSceneParam : NSObject

@property(nonatomic, strong) Class          viewControllerCls; // default is RVKViewController
@property(nonatomic, strong) Class          contentViewCls; // default is RVKWebVeiw
@property(nonatomic, copy) NSString         *url;
@property(nonatomic, strong) NSDictionary   *expandParams;

@end
