//
//  TBARVAppInfoCache.h
//  AriverDemo
//
//  Created by zhongweitao on 2019/3/27.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVApp.h"

@interface TRVAppInfoCache : NSObject

@property (nonatomic, assign) NSUInteger maxMemoryCountLimit;
@property (nonatomic, assign) NSUInteger maxMemoryTotalCostLimit;

+ (TRVAppInfoCache *)sharedInstance;

#pragma mark - 小程序
/// @brief 批量添加和删除 TRVApp
- (void)addApps:(NSArray<TRVApp *> *)apps;
- (void)removeApps:(NSArray<TRVApp *> *)apps;
- (void)removeAppIds:(NSArray<NSString *> *)appIds;

/// @brief 添加和删除 RVRApp
- (void)addApp:(TRVApp *)app;
- (void)removeApp:(TRVApp *)app;

/// @brief 根据appId查询 RVRApp
- (TRVApp *)getAppByAppId:(NSString *)appId version:(NSString *)version;

/// @brief app数量
- (NSUInteger)appCount;

/// @brief 更新最后使用的时间戳
- (void)updateLastUseTimeForAppId:(NSString *)appId timestamp:(double)timestamp;

/// @brief 缓存清理
- (void)clearAppInfoByMinTimestamp:(double)minTimestamp specialIds:(NSArray<NSString *> *)specialIds;

/// @brief 清理所有缓存
- (void)clearAllAppInfoExcept:(NSArray<NSString *> *)specialIds;

#pragma mark - 插件
/// @brief 批量添加和删除 TRVApp
- (void)addPlugins:(NSArray<TRVPlugin *> *)plugins;

/// @brief 根据appId查询 RVRApp
- (TRVPlugin *)getPluginByPluginId:(NSString *)pluginId version:(NSString *)version;

/// @brief 清理过期插件
- (void)clearPluginByMinTimestamp:(double)minTimestamp;

/// @brief 清理所有插件缓存
- (void)clearAllPluginInfo;

/// @brief 判断是否有插件缓存
- (BOOL)existCache4PluginId:(NSString *)pluginId;

@end
