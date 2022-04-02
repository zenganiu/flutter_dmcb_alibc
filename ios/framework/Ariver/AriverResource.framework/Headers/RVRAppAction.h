//
//  NXRAppAction.h
//  NebulaResource
//
//  Created by 扶瑶 on 16/3/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVRLogContext.h"
#import "RVRApp.h"
#import "RVRProtocol.h"

@interface RVRAppAction : NSObject

/**
 *  准备应用
 *
 *  @param appId   应用id
 *  @param version 应用版本号
 *  @param process 过程回调 异步请求包信息+异步下载+解压
 *  @param finish  完成回调
 */
+ (void)prepareApp:(NSString *)appId
           version:(NSString *)version
            params:(NSDictionary *)params
           process:(NXRAppPrepareProcess)process
            finish:(NXRAppPrepareFinish)finish;


/**
 *  定制准备应用方式，可自行设置同步、异步策略
 *
 *  @param appId        应用id
 *  @param version      应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param params       参数, 现支持: NXRREQ_PARAMKEY_SCENE, NXRREQ_PARAMKEY_DEBUG
 *  @param reqType      请求方式: 同步更新、异步更新
 *  @param offlineType  离线方式: 同步离线、异步离线
 *  @param finish       完成结果回调
 */
+ (void)prepareApp:(NSString *)appId
           version:(NSString *)version
           reqType:(NXRActionReqType)reqType
       offlineType:(NXRActionOfflineType)offlineType
            finish:(NXRAppPrepareFinish)finish;


/**
 *  定制准备应用方式，可自行设置同步、异步策略
 *
 *  @param appId        应用id
 *  @param version      应用版本号, 支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param params       参数, 现支持: NXRREQ_PARAMKEY_SCENE, NXRREQ_PARAMKEY_DEBUG
 *  @param reqType      请求方式: 同步更新、异步更新
 *  @param offlineType  离线方式: 同步离线、异步离线
 *  @param finish       完成结果回调
 */
+ (void)prepareApp:(NSString *)appId
           version:(NSString *)version
            params:(NSDictionary *)params
           reqType:(NXRActionReqType)reqType
       offlineType:(NXRActionOfflineType)offlineType
            finish:(NXRAppPrepareFinish)finish;


/**
 *  准备插件信息
 *
 *  @param appId   插件宿主id
 *  @param pluginId 插件id
 *  @param requireVersison   插件的依赖版本
 *  @param process 过程回调 异步请求包信息+异步下载+解压
 *  @param finish  完成回调
 */
+ (void)prepareApp:(NSString *)appId
          pluginId:(NSString *)pluginId
   requireVersison:(NSString *)requireVersison
            finish:(NXRAppPrepareFinish)finish;
/**
 *  获取应用状态
 *
 *  @param app 应用对象
 *
 *  @return 应用状态枚举值
 */
+ (NXRAppStatus)appStatus:(RVRApp *)app;


/**
 *  安装应用
 *
 *  注意: 这里的下载不区分下载环境, 强制下载
 *
 *  @param app     应用对象
 *  @param process 过程回调 下载+下载后自动解压
 *  @param finish  完成回调
 */
+ (void)mountPkg:(RVRApp *)app
           process:(NXRAppInstallProcess)process
            finish:(NXRAppInstallFinish)finish;
+ (void)mountPkg:(RVRApp *)app
            params:(NSDictionary *)params
           process:(NXRAppInstallProcess)process
            finish:(NXRAppInstallFinish)finish;


/**
 *  单个下载应用 - 不区分网络环境
 *
 *  @param app     应用对象
 *  @param process 过程回调
 *  @param finish  完成回调
 */
+ (void)download:(RVRApp *)app
             params:(NSDictionary *)params
            process:(NXRDownloadProcess)process
             finish:(NXRDownloadFinish)finish;


/**
 *  解压应用
 *
 *  @param app     应用对象
 *  @param process 过程回调 包含:解压+更新已安装信息+删除老tar包
 *  @param finish  成功回调
 */
+ (void)extractPkg:(RVRApp *)app
         process:(NXRZipArchiveProcess)process
          finish:(NXRZipArchiveFinish)finish;
+ (void)extractPkg:(RVRApp *)app
          params:(NSDictionary *)params
         process:(NXRZipArchiveProcess)process
          finish:(NXRZipArchiveFinish)finish;

/**
 * 批量解压
 *
 * @param 需要解压对象数组 [NXRApp, ...]
 */
+ (void)extractPkgs:(NSArray *)arrApps;

/**
 *  全量请求
 *
 *  @param param        参数, 暂时无用可传nil
 *  @param autoDownload 是否自动下载
 *  @param finish       完成回调
 */
+ (void)requestAllApps:(NSDictionary *)param
          autoDownload:(BOOL)autoDownload
                finish:(NXRRequestFinish)finish;


/**
 *  单个请求
 *
 *  @param apps         请求列表 格式:{appid:version} 不指定version时传@"",默认取最高版本
 *  @param autoDownload 请求完成后是否自动下载
 *  @param param        参数, 暂时无用可传nil
 *  @param finish       完成回调
 */
+ (void)requestApps:(NSDictionary *)apps
       autoDownload:(BOOL)autoDownload
              param:(NSDictionary *)param
             finish:(NXRRequestFinish)finish;

+ (NXRAppPrepareStep)prepareStep:(NXRAppInstallStep)installStep;

@end
