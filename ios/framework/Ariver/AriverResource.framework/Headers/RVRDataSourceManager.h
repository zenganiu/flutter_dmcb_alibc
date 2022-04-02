//
//  NXRResourceController.h
//  NebulaResource
//
//  Created by fuyao on 18/08/22.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVRDataSource.h"
#import "RVRDataSourceManagerLogProtocol.h"

#define kNXRDegradedApp         @"kNXRDegradedApp"     // degrade
#define kNXRLockDataSource      @"kNXRLockDataSource"

typedef void(^RVRDataSourceManagerDeallocComplete)(NSDictionary *result);

@interface RVRDataSourceManager : NSObject<RVRDataSourceManagerLogProtocol>
{
@protected
    NSDictionary *_mergedLaunchParams;
    BOOL _enableAppxNG;
    dispatch_once_t _onceToken;
}

@property (nonatomic, readonly, strong) NSString *appid;
// 主离线app
@property (nonatomic, readonly, strong) RVRApp *mainApp;
@property (nonatomic, readonly, weak) id curSession;
// 实例被销毁时的回调，外部设置
@property (nonatomic, copy) RVRDataSourceManagerDeallocComplete deallocComplete;
-(RVRApp *)app;

/**
 *  NBAppDataSourceManager 初始化方法
 *
 *  @date 2018-03-29
 *
 *  @param appid     离线app的id
 *  @param version   版本号
 *  @param session   当前session
 *
 *  @return 返回是否验签成功（加载成功）
 */
 - (instancetype)initWithAppid:(NSString *)appid
                       version:(NSString *)version
                       session:(id)nbSession;

/**
 *  @brief 获取主入口url
 *
 *  @date 2015-12-23
 *
 *  @return 返回主入口url
 */
- (NSString *)mainUrlString:(NSString *)urlString;

/**
 *  @brief 返回当前app的权限控制对象
 *
 *  @date 2016-12-12
 *
 *  @return 返回授权数据
 */
- (NSDictionary *)readPermissionConfig;

/**
 *  @brief 返回当前app配置数据源
 *
 *  @date 2017-03-06
 *
 *  @return 返回配置数据
 */
- (NSDictionary *)readAppConfig;

/**
 *  @brief 返回当前app tabbar配置数据源
 *
 *  @date 2019-06-19
 *
 *  @return 返回tabbar数据
 */
- (NSDictionary *)readTabBarConfig;

/**
 *  @brief 返回当前资源管理中指定url的离线缓存
 *
 *  @date 2017-03-06
 *
 *  @return 自定义离线数据源
 */
- (RVRAppResponse *)appResponseForUrl:(NSString *)url;

/**
 *  @brief 返回当前app的fallback 地址
 *
 *  @date 2019-12-10
 *
 *  @return 返回fallback之后的地址
 */
- (NSString *)getFallbackUrlWithApp:(RVRApp *)app url:(NSURL *)url;

- (void)addEventListener;
- (void)removeEventListener;
@end
