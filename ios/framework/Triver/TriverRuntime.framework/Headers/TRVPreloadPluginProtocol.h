//
//  TRVPreloadPluginProtocol.h
//  Runtime
//
//  Created by 岚遥 on 2020/3/3.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverResource/RVRApp.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVPreloadPluginProtocol <NSObject>

/**
 @return 返回当前插件版本是否匹配
 */
- (BOOL)matchPluginsVersion;

/**
 @param pluginId  比较的插件id
 @return 根据插件id返回数据
 */
- (NSString *)pluginDataWithPluginId:(NSString *)pluginId;

/**
 @return 获取官方插件idlist
 */
- (NSSet *)officialPluginList;

/**
 @return 获取已加载插件列表
 */
- (NSSet *)loadedPluginList;

/**
 @param pluginList 设置已加载的插件列表
 */
- (void)setLoadedPluginList:(NSSet * _Nullable)pluginList;

/**
 @param app 当前app信息
 */
- (void)loadPluginDataWithApp:(RVRApp * _Nonnull)app;

/**
 配置预渲染插件数据
 */
- (void)configPluginsData;

@end

NS_ASSUME_NONNULL_END
