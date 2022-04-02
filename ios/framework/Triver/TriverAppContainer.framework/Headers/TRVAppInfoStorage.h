//
//  TRVAppInfoStorage.h
//  Triver
//
//  Created by zhongweitao on 2019/4/1.
//

#import <Foundation/Foundation.h>
#import "TRVApp.h"

@interface TRVAppInfoStorage : NSObject

#pragma mark - 小程序
/// @brief 批量添加和删除 TRVApp
- (void)saveApps:(NSArray<TRVApp *> *)apps;
- (void)removeApps:(NSArray<TRVApp *> *)apps;
- (void)removeAppIds:(NSArray<NSString *> *)appIds;

/// @brief 添加和删除 RVRApp
- (void)saveApp:(TRVApp *)trvApp;
- (void)removeApp:(TRVApp *)trvApp;

/// @brief 根据appId查询 RVRApp
- (TRVApp *)getAppByAppId:(NSString *)appId version:(NSString *)version;

/// @brief app数量
- (NSUInteger)appCount;

/// @brief 更新
- (void)updateLastUseTimeForAppId:(NSString *)appId timestamp:(double)timestamp;

/// @brief 批量清理过期数据
- (void)clearAppInfoByMinTimestamp:(double)minTimestamp specialIds:(NSArray<NSString *> *)specialIds;

/// @brief 清理所有缓存数据
- (void)clearAllAppInfoExcept:(NSArray<NSString *> *)specialIds;

#pragma mark - 插件
/// @brief 批量添加和删除 TRVPlugin
- (void)savePlugins:(NSArray<TRVPlugin *> *)plugins;

/// @brief 根据appId查询 TRVPlugin
- (TRVPlugin *)getPluginByPluginId:(NSString *)pluginId version:(NSString *)version;

/// @brief 清理过期插件
- (void)clearPluginByMinTimestamp:(double)minTimestamp;

/// @brief 清理所有缓存数据
- (void)clearAllPluginInfo;

@end


