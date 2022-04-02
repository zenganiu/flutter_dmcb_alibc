//
//  RVKPluginMgr.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKPluginConfig;
@protocol RVKPluginProtocol;

//插件管理类
@interface RVKPluginManager : NSObject

@property(nonatomic, weak) RVKKernel    *target;
@property(nonatomic, copy) NSString     *scope;

/**
 *  @brief 注册默认的已经配置的插件
 *
 *  @date 2014-08-11
 *
 *  @return 无
 */
- (void)registerDefaultPlugins;

/**
 *  @brief 注册一个插件配置对象
 *
 *  @date 2014-08-20
 *
 *  @param pluginCfg 插件配置对象
 *
 *  @return 无
 */
- (void)registerPlugin:(RVKPluginConfig *)pluginCfg groupId:(NSString *)groupId;
- (void)registerPlugin:(RVKPluginConfig *)pluginCfg;

/**
 *  @brief 注册一组插件配置对象
 *
 *  @date 2014-08-11
 *
 *  @param pluginCfgs 插件配置对象数组，类型是RVKPluginConfig
 *
 *  @return 无
 */
- (void)registerPlugins:(NSArray *)pluginCfgs groupId:(NSString *)groupId;
- (void)registerPlugins:(NSArray *)pluginCfgs;

- (void)unregisterPlugin:(RVKPluginConfig *)pluginCfg groupId:(NSString *)groupId;
- (void)unregisterPlugin:(RVKPluginConfig *)pluginCfg;

- (void)unregisterPluginName:(NSString *)pluginName groupId:(NSString *)groupId;
- (void)unregisterPluginName:(NSString *)pluginName;

- (void)unregisterPlugins:(NSString *)groupId;
- (void)unregisterPlugins;

- (NSArray *)plugins:(NSString *)groupId;
- (NSArray *)plugins;

- (id<RVKPluginProtocol>)plugin:(NSString *)name groupId:(NSString *)groupId;
- (id<RVKPluginProtocol>)plugin:(NSString *)name;

@end
