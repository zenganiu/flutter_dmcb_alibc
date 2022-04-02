//
//  RVRService.h
//  AriverResource
//
//  Created by nico on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVRApp.h"

typedef void (^RVAppPrepareFinish)(RVRApp *app, NSError *error);                       // prepare finished


@interface RVRService : NSObject
+(instancetype)sharedInstace;

- (NSInteger)compareVersions:(NSString *)version1 withVersion:(NSString *)version2;
/*
 * 通过包信息中的publicURL列表匹配appId
 */
- (NSString *)findAppIdByURL:(NSString *)URLString;
/*
 * 通过publicURL匹配主文档的开关
  */
- (BOOL)enableMatchMainURLByPublicURL;
/*
 *通过header.json匹配header的开关
 */
- (BOOL)enableMatchHeaders;

/**
 *  查找指定id和版本号的应用信息
 *
 *  @param appId   应用id
 *  @param version 应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *
 *  @return 返回某个appid指定版本号应用对象
 *
 *  注意:
 *      1. 不区分应用上下线 (即下线的应用也会通过该接口返回)
 *      2. 函数内通过NAMAppInterface协议判断是否支持NebulaApp, 并且在未找到应用的情况下通过协议函数:findApp查找.
 *      NAMAppInterface协议可通过 NAMConfigurationGet().appInterface 指定
 */
- (RVRApp *)findApp:(NSString *)appId version:(NSString *)version;

/**
 *  查找指定id和版本号的可用应用信息
 *
 *  注意: 过滤已下线应用
 */
- (RVRApp *)findAvailableApp:(NSString *)appId version:(NSString *)version;
/**
 *  安装应用
 *
 *  @param app     应用对象
 *  @param process 安装过程回调, 过程包含: 异步下载离线包->解压离线包
 *  @param finish  完成回调
 */
- (void)mountPkg:(RVRApp *)app
           process:(NXRAppInstallProcess)process
            finish:(NXRAppInstallFinish)finish;

/**
 *  获取指定应用本地已有资源的版本
 *
 *  逻辑: 查找 已安装版本 -> 预置版本 -> 业务方定制的应用版本
 *  现应用场景: 加载公共资源包资源时,如果本地离线包未安装,会触发加载本地已安装的版本(因降级受包特性影响, 只有纯资源并且和版本无关的应用类型才支持降级。SDK降级开关默认:关, 业务方如需配置请联系@扶瑶, 其他场景勿用)。
 */
- (RVRApp *)findResourcesPreparedApp:(NSString *)appId;


- (void)prepareApp:(NSString *)appId
           version:(NSString *)version
            params:(NSDictionary *)params
           reqType:(NXRActionReqType)reqType
       offlineType:(NXRActionOfflineType)offlineType
            finish:(NXRAppPrepareFinish)finish;

- (void)prepareApp:(NSString *)appId
          pluginId:(NSString *)pluginId
   requireVersison:(NSString *)pluginVersion
            finish:(NXRAppPrepareFinish)finish;

-(void)checkMinSDKVersion:(NSString *)appId
                   finish:(NXRAppXFinishBlock)finish;

- (NSDictionary *)presetAppDics;

@end


#ifdef __cplusplus
extern "C" {
#endif
    RVRService * _Nonnull  RVRServiceGet(void);
#ifdef __cplusplus
}
#endif
