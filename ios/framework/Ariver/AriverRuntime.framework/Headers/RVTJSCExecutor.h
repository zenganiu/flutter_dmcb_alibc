//
//  RVTJSCExecutor.h
//  AriverRuntime
//
//  Created by theone on 2017/12/18.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "RVTDefine.h"
@class RVTJSCBridge;

NS_ASSUME_NONNULL_BEGIN
#define kRVTJSCExecutorAppxContext  @"kRVTJSCExecutorMainContext"
#define kRVTJSCExecutorBizContext   @"kRVTJSCExecutorBizContext"


@interface RVTJSCExecutor : NSObject
@property(nonatomic, assign)   BOOL  canRunIsolateContext;

- (instancetype)initWithBridge:(RVTJSCBridge *)bridge;
//从外部给javascrpt执行一段js
- (void)executeJavaScript:(NSString *)javaScript
				sourceURL:(NSURL *)sourceURL
			   onComplete:(RVTJavaScriptCallback)onComplete;

- (void)executeJavaScript:(NSString *)javaScript
                sourceURL:(NSURL *)sourceURL
               onComplete:(RVTJavaScriptCallback)onComplete
                contextId:(NSString *)contextId;

- (void)executeBlockOnJavaScriptQueue:(dispatch_block_t)block;

- (void)executeAsyncBlockOnJavaScriptQueue:(dispatch_block_t)block;

- (void)setUp;

- (void)executeBizJavaScript:(NSString *)javaScript
                sourceURL:(NSURL *)sourceURL
               onComplete:(RVTJavaScriptCallback)onComplete;

- (void)loadPluginsWithConfig:(NSArray *)config
                   onComplete:(dispatch_block_t)onComplete;

- (BOOL)isPluginInstalled:(NSString *)appId;

- (void)dispatchMessage:(NSDictionary *)message;

@end

NS_ASSUME_NONNULL_END
