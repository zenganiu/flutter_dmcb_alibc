//
//  RVRDataSourceManager+Load.h
//  NebulaResource
//
//  Created by fuyao on 2018/8/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVRDataSourceManager.h"

@interface RVRDataSourceManager (Load)

@property (nonatomic, strong) NSMutableArray *appDataSources;
@property (nonatomic, strong) NSMutableArray *loadedAppInfo;
@property (nonatomic, strong) RVRDataSource *mainDataSource;

- (void)loadDataSource;

/**
 *  @brief 根据nbl_id加载离线app
 *
 *  @date 2015-09-21
 *
 *  @param nbl_id     离线app的id
 *  @param needVerify 是否需要验签
 *
 *  @return 返回是否验签成功（加载成功）
 */
- (BOOL)loadAppData:(RVRApp *)app needVerify:(BOOL)needVerify;
/**
 *  @param plugins 需要加载的插件资源
 *
 *  @return 加载插件资源，并与当前主引用关联(如果插件未安装，有补偿机制)
 */
-(void)loadDataSourceForPlugins:(NSArray *)plugins;
/**
 *  @brief 批量加载指定App
 *
 *  @param  [appId, ...]指定appId数组
 */
- (void)loadDataSourceForApps:(NSArray *)arrApps;

/**
 *  @brief 返回当前资源管理中指定appId的应用实例
 *
 *  @return 应用实例
 */
- (RVRApp *)loadedAppInfoForAppId:(NSString *)appId;

/**
 *  @brief 卸载app数据
 *
 *  @date 2015-10-08
 *
 *  @return 无
 */
- (void)unloadAppData;


-(RVRDataSource *)fetchLatestLoadedDataSource:(NSString *)appId;
@end
