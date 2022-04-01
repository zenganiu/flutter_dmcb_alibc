//
//  RVKConfigMgr.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKPluginConfig;
@class RVKJsApiConfig;

@protocol RVKExtensionConfigManagerProtocol
@optional
- (BOOL)shouldLoadConfigMod:(NSString *)mod;
- (void)setExtraPermissionConfig:(NSDictionary *)config
                         apiName:(NSString *)apiName;
@end

//配置管理类
@interface RVKConfigManager : NSObject

@property(nonatomic, weak)       id<RVKExtensionConfigManagerProtocol> configDelegate;

+ (instancetype)sharedInstance;

- (void)loadAllConfigs;

// 动态注册配置模块
- (void)registerConfigMod:(NSString *)mod;


/**
 *  @brief 所有插件配置对象列表
 *
 *  @date 2014-08-11
 *
 *  @return 返回插件配置对象列表
 */
- (NSArray *)allPluginCfgs:(NSString *)scope; // RVKPluginConfig

/**
 *  @brief 所有JsApi配置对象列表
 *
 *  @date 2014-08-20
 *
 *  @return 返回JsApi配置对象列表
 */
- (NSArray *)allJsApiCfgs:(NSString *)scope; // RVKJsApiConfig

- (void)registerPluginCfg:(RVKPluginConfig *)pluginCfg;

- (void)unRegisterPluginCfg:(RVKPluginConfig *)pluginCfg;

- (void)registerJsApiCfg:(RVKJsApiConfig *)jsApiCfg;

- (void)unRegisterJsApiCfg:(RVKJsApiConfig *)jsApiCfg;

- (void)registerComponentWithName:(NSString *)name clsName:(NSString *)clsName;
- (void)unRegisterComponentWithName:(NSString *)name;
- (NSDictionary *)components;

- (void)loadPluginsWithConfig:(NSDictionary *)config;

- (void)loadJsApisWithConfig:(NSDictionary *)config;

- (void)loadComponents:(NSArray *)components;

@end
