//
//  RVRProtocol.h
//  AriverResource
//
//  Created by nico on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//
#import "RVRApp.h"
#import "RVRProtocol+private.h"
#ifndef RVRProtocol_h
#define RVRProtocol_h

#pragma mark - Request
extern NSString *NXRREQ_PARAMKEY_INSTALLED_APPS;
extern NSString *NXRREQ_PARAMKEY_LOCAL_APPS;
extern NSString *NXRREQ_PARAMKEY_SCENE;
extern NSString *NXRREQ_PARAMKEY_FORCE;             // 强制请求,忽略请求频率
extern NSString *NXRREQ_PARAMKEY_REQTYPE;           // 请求类型 异步async/同步尝试synctry/同步强制syncforce
extern NSString *NXRREQ_PARAMKEY_RESAPP;            // 请求的资源应用Id [appId, ...]
extern NSString *NXRREQ_PARAMKEY_STABLE;            // 强大rpc标记
extern NSString *NXRREQ_PARAMKEY_REQ_NUM_LIMIT;     // rpc个数是否限制
extern NSString *NXRREQ_PARAMKEY_TRIGGER_SOURCE;    // 请求触发来源 (默认:normal, 网关全网化:sideMgw)

extern NSString *NXRREQ_RESPONSEKEY_DATA;
extern NSString *NXRREQ_RESPONSEKEY_CONFIG;
extern NSString *NXRREQ_RESPONSEKEY_REMOVELIST;
extern NSString *NXRREQ_RESPONSEKEY_SCENE;
extern NSString *NXRREQ_RESPONSEKEY_DISCARDDATA;

#pragma mark - Log

extern NSString *const NXRLogParamApp;     // NXRApp对象key
extern NSString *const NXRLogParamAppId;   // 应用id
extern NSString *const NXRLogParamVersion; // 应用版本号
extern NSString *const NXRLogParamCustom;  // 自定义
extern NSString *const NXRLogParamBizType; // 业务标识

#endif /* RVRProtocol_h */

// params
extern NSString *const NXRDOWN_PARAM_KEY_FORCE;
extern NSString *const NXRDOWN_PARAM_KEY_APP;       // NXRApp object

extern NSString * const NXRLogParamBizTypeWebstat;

@protocol RVRDownloadManagerDelegate <NSObject>
-(void)download:(RVRApp *)app
            params:(NSDictionary *)params
           process:(NXRDownloadProcess)process
            finish:(NXRDownloadFinish)finish;
- (BOOL)isDownloadingApp:(RVRApp *)app;
- (void)cancelAllDownloadTask;
@optional
- (void)deletePackageForApp:(RVRApp *)app;
@end

@protocol RVRZipArchiveManagerDelegate <NSObject>
- (BOOL)isUnzipping:(RVRApp *)app;
- (void)extractPkg:(RVRApp *)app
         process:(NXRZipArchiveProcess)process
          finish:(NXRZipArchiveFinish)finish;
- (void)extractPkg:(RVRApp *)app
          params:(NSDictionary *)params
         process:(NXRZipArchiveProcess)process
          finish:(NXRZipArchiveFinish)finish;
@optional
-(NSString *)unzipPathForApp:(RVRApp *)app;
-(BOOL )isInstalledForApp:(RVRApp *)app;
// 是否需要强制cdn下载这个app资源
- (BOOL)needForceDownloadForApp:(RVRApp *)app;
@end



extern NSString *const NXRReqMgrKeyFullDose;
@protocol RVRRequestManagerDelegate <NSObject>
/**
 *  请求应用列表
 * 
 *  @param dicApps 应用列表{appid:version}
 *  @param params  参数
 *  @param finish  完成回调
 */
- (void)requestApps:(NSDictionary *)dicApps
             params:(NSDictionary *)params
             finish:(void (^)(id data, NSError *error))finish;
@optional
/**
 *  请求插件信息列表
 *
 *  @param dicApps 应用列表{appid:version}
 *  @param params  参数
 *  @param finish  完成回调
 */
- (void)requestPlugin:(NSDictionary *)plugin
               params:(NSDictionary *)params
               finish:(void (^)(id data, NSError *error))finish;
typedef void (^ResourceCallback)(NSData *data,NSError *error);
/*
 * 模板小程序能力相关
 */
- (void)getResourceWithUrl:(NSString *)url callback:(ResourceCallback)callback;
@end

#pragma mark - App Update Source

@protocol RVRAppPoolProtocol <RVRAppPoolOptionalProtocol>
/**
 *  添加应用
 *
 *  @param apps 待添加NXRApp应用数组
 *  @param source 更新来源
 */
-(void)addApps:(NSArray *)apps source:(NXRAppSource)source;
/**
 *  删除应用 (应用ID+版本维度删除)
 *
 *  @param apps 待删除NXRApp应用数组
 */
-(void)removeApps:(NSArray *)apps;
/**
 *  删除指定应用的包资源
 *
 *  删除应用amr、增量amr、tar包
 *
 *  @param app         应用对象
 *  @param updateCache 是否刷新缓存,用于是否变增量包为全量包
 */
-(void)removeResources:(RVRApp *)app
           updateCache:(BOOL)updateCache;
/**
 *  更新已安装应用(删除本地该应用的旧版本)
 *
 *  @param app 应用对象
 */
-(void)updateInstalledApp:(RVRApp *)app;
/**
 *  查找指定版本号的应用信息
 *
 *  @param appId   应用id
 *  @param version 应用版本号
 *
 *  @return NXRApp对象
 */
-(RVRApp *)findApp:(NSString *)appId version:(NSString *)version;
/**
 *  获取包信息池内当前应用数
 */
-(NSUInteger) appCount;
/**
 *  删除应用 (应用ID维度删除)
 *
 *  @param apps 待删除应用Id列表 [appId]
 *  @param source 更新来源
 */
- (void)removeAppIds:(NSArray *)apps source:(NXRAppSource)source;

/**
*  查找指定版本号的应用信息
*
*  @param appId   应用id
*  @param version 应用版本号(短版本，该版本应是开发者的发布版本)
*
*  @return NXRApp对象
*/
-(RVRApp *)findPluginApp:(NSString *)appId requreVersion:(NSString *)version;

/**
 *  查找指定版本号的插件信息（不考虑过期时间）
 *  @param appId   应用id
 *  @param version 应用版本号(短版本，该版本应是开发者的发布版本)
 */
-(RVRApp *)getLocalPlugin:(NSString *)appId requreVersion:(NSString *)version;

/**
 *  添加插件
 *
 *  @param apps 待添加NXRApp应用数组
 *  @param source 更新来源
 */
-(void)addPlugins:(NSArray *)apps source:(NXRAppSource)source;
/*
*  查找指定版本号的应用信息
*
*  @param appId   应用id
*  @param version 应用版本号(短版本，该版本应是开发者的发布版本)
*  @param mainAppId 同时检查订阅关系
*  @return NXRApp对象
*/
-(RVRApp *)findPluginApp:(NSString *)appId requreVersion:(NSString *)version inMainApp:(NSString *)mainAppId;

/**
 更新插件和主应用的订阅关系
 */
-(void)updateRelationshipWithPluginAppId:(NSString *)pluginId
                                 mainApp:(NSString *)mainAppId
                                 isExist:(BOOL)exist;
@end

@protocol RVRAppPoolProtocol;
@protocol RVRAppPoolManagerProtocol <NSObject>
-(id<RVRAppPoolProtocol>)appPool:(NXRAppAutoScene)scene;
-(id<RVRAppPoolProtocol>)appPool;
@end
