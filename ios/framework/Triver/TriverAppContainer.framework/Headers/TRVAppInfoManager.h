//
//  TBARVAppInfoManager.h
//  AriverDemo
//
//  Created by zhongweitao on 2019/3/27.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverResource/RVRApp.h>

typedef NS_ENUM(NSInteger, TRVCacheExpiredType) {
    TRVCacheExpiredTypeNoCache = 0,  //无缓存
    TRVCacheExpiredTypeNone = 1,     //缓存有效
    TRVCacheExpiredTypeAsync = 2,    //需要异步更新
    TRVCacheExpiredTypeSync = 3,     //需要同步更新
};

typedef void(^TRVAppInfoCompletion)(NSDictionary *dataDic, NSError *error);


@interface TRVAppInfoManager : NSObject

/// @brief 采用内置AppX后忽略缓存有效期，标志需要异步更新
@property (nonatomic,assign) BOOL needUpdateAppx;

+ (TRVAppInfoManager *)sharedInstance;

#pragma mark - Request

/// @brief 批量请求AppInfo
- (void)requestAppInfoForMainApp:(NSDictionary<NSString *,NSString *> *)mainAppDic
                   mainAppParams:(NSDictionary *)params
                         appsDic:(NSDictionary<NSString *,NSString *> *)appsDic
                      completion:(TRVAppInfoCompletion)completion;

/// @brief 批量请求动态插件
- (void)requestPlugins:(NSDictionary *)plugins
          pluginParams:(NSDictionary *)params
            completion:(TRVAppInfoCompletion)completion;

/// @brief 批量请求TOP缓存失效应用
- (void)updateTopExpiredAppInfo;

#pragma mark - Cache

/// @brief 批量添加和删除 RVRApp
- (void)addApps:(NSArray<RVRApp *> *)apps;
- (void)removeApps:(NSArray<RVRApp *> *)apps;
- (void)removeAppIds:(NSArray<NSString *> *)appIds;

/// @brief 删除指定appIds的appInfo
- (void)removeAppInfo4AppIds:(NSArray<NSString *> *)appIds;

/// @brief 添加和删除 RVRApp
- (void)addApp:(RVRApp *)app;
- (void)removeApp:(RVRApp *)app;

/// @brief 清理所有appinfo缓存
- (void)clearAllAppInfoCache;

/// @brief 根据appId查询 RVRApp
- (RVRApp *)getAppByAppId:(NSString *)appId version:(NSString *)version;

/// @brief 缓存清理
- (void)clearOutOfDateCacheData;

/// @brief app数量
- (NSUInteger)appCount;

/// @brief 检查appId对应的AppInfo是否需要异步更新
- (void)checkAsyncUpdateAppInfoForAppId:(NSString *)appId version:(NSString *)version params:(NSDictionary *)params;

/// @brief 检查appId对应的AppInfo缓存状态
- (TRVCacheExpiredType)checkSyncUpdateAppInfoForAppId:(NSString *)appId version:(NSString *)version;

/// @brief 异步更新appinfo和包
- (void)asyncUpdateAppForAppId:(NSString *)appId params:(NSDictionary *)params;

/// @brief 获取预置的appx的appinfo
- (RVRApp *)getPresetAppx;

/// @brief 预加载指定appid对应的appinfo和包数据
- (void)preLoadResourceForAppIds:(NSArray<NSString *> *)appIds;

#pragma mark - 插件
/// @brief 根据pluginId查询 RVRApp
- (RVRApp *)getPluginByPluginId:(NSString *)pluginId version:(NSString *)version;

- (RVRApp *)getLocalPluginByPluginId:(NSString *)pluginId version:(NSString *)version;

/// @brief 批量添加插件
- (void)addPlugins:(NSArray<RVRApp *> *)apps;

/// @brief 根据pluginId 查询存在订阅关系的插件RVRApp
- (RVRApp *)getPluginByPluginId:(NSString *)pluginId version:(NSString *)version mainAppId:(NSString *)mainAppId;

/// @brief 更新插件的订阅关系
- (void)updateRelationshipWithPluginId:(NSString *)pluginId mainAppId:(NSString *)mainAppId isExist:(BOOL)exist;

#pragma mark - 百川特供

/// @brief 根据pluginId 查询存在订阅关系的插件RVRApp 会判断缓存是否有效
- (RVRApp *)bcGetPluginByPluginId:(NSString *)pluginId version:(NSString *)version mainAppId:(NSString *)mainAppId;

@end
