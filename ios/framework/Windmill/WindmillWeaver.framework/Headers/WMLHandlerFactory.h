//
//  WMLHandlerFactory.h
//  Weaver
//
//  Created by lianyu on 2018/4/6.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Handler 的工厂，相同 Protocol 的 Handler 只允许注册一个。
 */
@interface WMLHandlerFactory : NSObject

/**
 注册指定的 Handler。
 */
+ (void)registerHandler:(id _Nonnull)handler withProtocol:(Protocol * _Nonnull)protocol;

/**
 注册指定的 Handler 类。
 
 @param singleton 是否是单例。如果为 YES，会将首次调用创建的实例保存起来；如果为 NO，会每次返回一个新实例。
 */
+ (void)registerHandlerClass:(Class _Nonnull)handlerClass isSingleton:(BOOL)singleton withProtocol:(Protocol * _Nonnull)protocol;

/**
 移除指定 Protocol 的 Handler。
 */
+ (void)unregisterHandlerWithProtocol:(Protocol * _Nonnull)protocol;

/**
 获取与指定 Protocol 关联的 Handler。
 */
+ (id _Nullable)handlerForProtocol:(Protocol * _Nonnull)protocol;

@end
