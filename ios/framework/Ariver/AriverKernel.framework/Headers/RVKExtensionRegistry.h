//
//  RVKExtensionRegistry.h
//  NebulaKernel
//
//  Created by theone on 2018/8/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVKRegisteyScopeProtocol.h"

@class RVKExtension;

// 未支持scope时，此对象维护了全局注册的extension实例集合
// 支持scope后，此对象做为全局静态注册表，只维护各scope域上的注册的Point->ExtensionClasses数据
@interface RVKExtensionRegistry : NSObject

+ (instancetype)defaultRegistry;

- (BOOL)useNewRegistry;

- (void)setScopeDelegate:(id<RVKRegisteyScopeProtocol>)delegate;

- (void)registerDefaultExtensions:(NSArray<NSDictionary *> *)extensions;

// 返回extension类数组
- (NSArray *)findExtensionsClassWithPoint:(Protocol *)point;
// 返回extension类数组
- (NSArray *)findExtensionsClassWithPoint:(Protocol *)point scope:(NSString *)scope;

// 返回extension实例数组
- (NSArray *)legacyLoadExtensionsWithPoint:(Protocol *)point;

- (RVKExtension *)loadJsapiExtensionWithCls:(NSString *)clsName point:(Protocol *)point;

- (void)registerExtensionsWithConfig:(NSDictionary *)config;

- (void)unregisterExtension:(NSString *)extension;
@end
