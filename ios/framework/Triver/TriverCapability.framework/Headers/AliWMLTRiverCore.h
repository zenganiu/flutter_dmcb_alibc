//
//  AliWMLTRiverCore.h
//  TRiverCore
//
//  Created by AllenHan on 2019/4/10.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface AliWMLTRiverCore : NSObject

+ (void)setup;

+ (void)setupAfterRegisterHandler;

+ (void)setAppGroup:(NSString *)appGroup
            appName:(NSString *)appName
         appVersion:(NSString *)appVersion;

/**
 *  inside 应用唤起支付宝 app 操作之后，返回回去的 app scheme，具体场景比如收银台唤起支付宝支付，支付成功后返回
 */
+ (void)setAppScheme:(NSString *)appShceme;

+ (void)setDebugModeEnabled:(BOOL)enabled;

/// @brief 开启三方MTOP
+ (void)setOpenMtopEnable:(BOOL)enable;

/// @brief 设置是否是三方APP
+ (void)setIsAliApp:(BOOL)aliApp;

/// @brief 设置自定义UA
+ (void)setCustomUserAgent:(NSString *)customUserAgent;

/// @brief 设置自定义全局UT参数
+ (void)setCustomUTParams:(NSDictionary *)customUTParams;

/// @brief 设置自定义AppMonitor埋点page
+ (void)setCustomMonitorPage:(NSString *)page;

/// @brief 预加载小程序资源
+ (void)preLoadAppResource4AppUrls:(NSArray<NSString *> *)minAppUrls;

/// @brief 为目标小程序预加载动态插件资源
/// @param plugins 动态插件信息：@[@{@"pluginId":pluginId,@"requireVersion":requireVersison?:@"*"}]
/// @param appId 目标小程序
+ (void)preloadDynamicPlugins:(NSArray<NSDictionary *> *)plugins forApp:(NSString *)appId scene:(NSString *)scene completion:(void(^)(NSError *error))completion;

/// @brief 异步更新动态插件资源
/// @param plugins 动态插件信息：@[@{@"pluginId":pluginId,@"requireVersion":requireVersison?:@"*"}]
/// @param appId 目标小程序
+ (void)updateDynamicPlugins:(NSArray<NSDictionary *> *)plugins forApp:(NSString *)appId completion:(void(^)(NSError *error))completion;

@end

