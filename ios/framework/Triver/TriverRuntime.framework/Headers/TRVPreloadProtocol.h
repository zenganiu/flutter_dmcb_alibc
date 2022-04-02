//
//  TRVPreloadProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/8/16.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TRVPTypeMtop    @"mtop"
#define TRVPTypeHttp    @"http"
#define TRVPTypeImage   @"image"
#define TRVPTypeCloudFc @"cloudFunc"

#define TRVPTypeKey    @"type"
#define TRVPParamsKey  @"params"
#define TRVPExtParamsKey @"extParams"

#define TRVAppContainerKey @"TRVAppContainerKey"

typedef void(^TRVPreloadComplete)(NSDictionary *result, NSError *error);
typedef void(^TRVMtopCompletion)(BOOL success, id response);

@protocol TRVPreloadProtocol <NSObject>

@required

/**
 触发预加载

 @param config 预加载配置
 @param appId 当前AppId
 @param extInfo 拓展信息
 */
- (void)startPreloadWithConfig:(NSArray<NSDictionary*>*)config forApp:(NSString *)appId extInfo:(NSDictionary *)extInfo;


@optional

/**
 触发插件预加载

 @param config 预加载配置
 @param appId 当前AppId
 @param requestAppKey 插件appKey
 @param extInfo 拓展信息
*/
- (void)startPreloadWithConfig:(NSArray<NSDictionary*>*)config forApp:(NSString *)appId requestAppKey:(NSString *)requestAppKey extInfo:(NSDictionary *)extInfo;

/**
 获取MTOP预取数据

 @param mtopRequest 当前mtop骑牛
 @param completion 缓存命中的回调
 @param extInfo 拓展信息
 @return 是否命中缓存
*/
- (BOOL)getMtopPrefeth4Request:(id)mtopRequest completion:(TRVMtopCompletion)completion  extInfo:(NSDictionary *)extInfo;

/**
 触发AppX预加载
 
 #param completion 回调
 */
- (void)startPreloadAppX:(TRVPreloadComplete)completion;

/**
更新预加载缓存的AppX
*/
- (void)updatePreloadedAppXInfo:(TRVPreloadComplete)completion;

/**
 获取预加载的Tar包内容

 @param appId appId
 @return 内容
 */
- (id)preloadedTarDataForApp:(NSString *)appId;

/**
 获取HTTP请求预加载的缓存结果

 @param params HTTP任务请求参数
 @return 缓存数据
 */
- (id)prefetchedHttpResponseWithParams:(NSDictionary *)params;

/**
 从Orange中动态获取配置

 @param appId 对应的AppId
 @return 配置
 */
- (id)preloadConfigFromRemoteForAppId:(NSString *)appId;

@end
