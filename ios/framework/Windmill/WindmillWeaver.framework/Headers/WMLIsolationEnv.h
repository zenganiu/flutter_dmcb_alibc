//
//  WMLIsolationEnv.h
//  Weaver
//
//  Created by lianyu on 2018/7/17.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import "WMLFileProtocol.h"
#import "WMLNetworkCacheProtocol.h"
#import "WMLNetworkProtocol.h"
#import <Foundation/Foundation.h>

/**
 表示一个隔离环境。
 */
@interface WMLIsolationEnv : NSObject

/**
 环境相关信息。
 */
@property (nonatomic, copy, nullable) NSDictionary * envInfo;

/**
 隔离环境的文件接口。
 */
@property (nonatomic, strong, readonly, nullable) id<WMLFileProtocol> files;

/**
 隔离环境的网络缓存接口。
 */
@property (nonatomic, strong, readonly, nullable) id<WMLNetworkCacheProtocol> cache;

/**
 隔离环境的网络请求接口。
 */
@property (nonatomic, strong, readonly, nullable) id<WMLNetworkProtocol> network;

/**
 使用指定的文件和网络接口初始化。
 */
- (instancetype _Nonnull)initWithFiles:(id<WMLFileProtocol> _Nullable)files network:(id<WMLNetworkProtocol> _Nullable)network cache:(id<WMLNetworkCacheProtocol> _Nullable)cache;

/**
 发送指定的请求，会先尝试命中缓存，失败后再发送网络请求。
 
 @param task 要发送的请求。
 */
- (void)startRequestTask:(id<WMLRequestTask> _Nonnull)task;

/**
 停止指定的请求。
 
 @param task 要停止的请求。
 */
- (void)stopRequestTask:(id<WMLRequestTask> _Nonnull)task;

@end
