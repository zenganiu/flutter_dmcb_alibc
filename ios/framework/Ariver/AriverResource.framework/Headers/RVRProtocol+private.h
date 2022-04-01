//
//  RVRProtocol+private.h
//  Pods
//
//  Created by nico on 2019/4/21.
//
#import "RVRApp.h"
#import "RVRLogContext.h"

@protocol RVRConfigManagerDelegate <NSObject>
- (void)updateConfig:(NSDictionary *)config;
//公共资源包AppId列表;
-(NSArray *)commonAppList;
-(BOOL)callbackInHighPriorityAfterUnzip;
- (NSTimeInterval)resMainDocInvalidTime;
- (NSTimeInterval)limitReqRate;
- (NSTimeInterval)updateReqRate;
-(BOOL)shouldLogResponse;//默认YES;
-(BOOL)shouldUseConditionalResponse;//默认NO
-(BOOL)shouldWKWebViewForceFreshResponse;//默认NO
/**
 *  离线资源匹配附加功能开关，如publicUrls匹配
 */
- (NSDictionary *)resManifestSwitchers;

-(NSDictionary *)tinyAppPublicURL;

-(BOOL)cacheReqTime;
-(NSString *)presetAppPackagePath;
-(NSString *)unzipRootPath;
-(NSString *)downloadRootPath;
-(NSString *)templateConfigRootPath;
// 业务方指定的验证包签名的公钥
-(NSString *)signPublicKey;
/**
 *  获取通过代理过滤过的公共资源列表
 *
 *  可通过代理函数:supportNebulaApp配置是否支持为NebulaApp,如果为配置该协议默认返回配置的公共列表
 *  @return 过滤后的公共应用id及对应版本号, e.g. {'20000196':'1.0.0'}
 */
- (NSDictionary *)filteredCommonApplist;
/*是否需要验签*/
- (BOOL)isNeed2VerifyApp;
/**
 *  模版小程序总开关
 */
- (BOOL)enableTemplateApp;

/**
 *  模版小程序配置信息等待时间
 */
- (NSTimeInterval)preferConfigWaitTime;

/**
 是否转发
 */
- (BOOL)enableUseAppxHtml;

/**
 是否允许appxng切流
 */
- (BOOL)enableUseAppxNG;
- (NSString *)appxngAppId;

/**
 是否将fallback资源返回头和离线包返回头保持一致
*/
- (BOOL)enableRemoveFallbackHeaders;

/**
 fallback资源返回头透回给内核的白名单
*/
- (NSArray *)fallbackHeadersWhitelist;

@optional
- (NSTimeInterval)pluginExpireTime;
@end

@protocol RVRMonitorDelegate <NSObject>
-(void)logWithLogId:(NSString *)trackId params:(NSDictionary *)params;
-(void)logWithLogId:(NSString *)trackId params:(NSDictionary *)params targetPage:(id )psdPage;
-(void)logWithLogId:(NSString *)trackId params:(NSDictionary *)params targetApp:(RVRApp *)app;
@end

@protocol RVRLogManagerDelegate <NSObject>
-(void)log:(RVRLogContext *)context;
@optional
-(void)logWithOptions:(NSDictionary *)options inSession:(id)session;
@end

@class RVRRequestManager;
@protocol RVRRequestCenterDelegate <NSObject>
- (RVRRequestManager *)requestManagerForKey:(NSString *)key;
- (BOOL)fullDoseRequestExpired;
- (void)refreshFullDoseReqTimeWithLimited:(BOOL)limited;
- (void)removeUnavailablelist:(NSArray *)list;

@optional
-(void)removeRequestManagerForKey:(NSString *)key;
@end

//以下代理有默认实现
@protocol RVRAppInterfaceDelegate <NSObject>
/**
 *  获取应用场景
 *  注: 仅钱包内调试模式使用
 */
- (NSString *)sceneForApp:(NSString *)appId;
/**
 *  定制应用对象
 */
- (RVRApp *)findApp:(NSString *)appid version:(NSString *)version;
- (BOOL)isNebulaApp:(NSString *)appId nebulaVersion:(NSString **)nebulaVersion;
- (BOOL)supportNebulaApp:(NSString *)appid version:(NSString *)version nebulaVersion:(NSString **)nebulaVersion;
- (BOOL)enableLoadPubAppId:(NSString *)appid contextApp:(RVRApp *)contextApp version:(NSString **)version;
- (BOOL)enableLoadPkgResApps:(NSNumber **)numLimit;
- (BOOL)isResApp:(NSString *)appId;
- (BOOL)enableCommonResourceDegrade:(NSString *)appId;
- (BOOL)enableStableReq;
- (NSDictionary *)presetAmrApps;
-(BOOL)enableSyncUnzipPresetAmr;
@end


@protocol RVRAppPoolOptionalProtocol <NSObject>

/**
 * 删除回滚的包信息
 */
- (void)removeDiscardApp:(NSString *)appId versions:(NSArray *)versions;
/**
 *  获取应用池中所有'需要上报的'应用ID及版本信息
 *
 *  @param preferApps 期望获取的应用本地版本
 *  @return {appId:version} 本地需要上报的版本+期望获取的应用版本
 */
- (NSDictionary *)allLocalReportApps:(NSArray *)preferApps;
/**
 *  获取已过期应用列表
 *
 *  @param list 待筛选列表, 格式{appid:version}
 *
 *  @return 列表字典, 格式{appid:version}
 */
- (NSDictionary *)expiredApps:(NSDictionary *)list;

- (NSDictionary *)installedAppVersions:(NSDictionary *)list;
/**
 *  获取指定应用本地已有资源的版本
 *
 *  逻辑: 查找 已安装版本 -> 预置版本 -> 业务方定制的应用版本
 *  现应用场景: 加载公共资源包资源时,如果本地离线包未安装,会触发加载本地已安装的版本(因降级受包特性影响, 只有纯资源并且和版本无关的应用类型才支持降级。SDK降级开关默认:关, 业务方如需配置请联系@扶瑶, 其他场景勿用)。
 */
-(RVRApp *)resourcesPreparedApp:(NSString *)appId;

/**
 *  更新应用请求时间,并标记是否被限流
 *
 *  @param list         应用列表, 格式{appid:version}
 *  @param limited      是否被限流
 *  @param forceRequest 是否为强制请求
 */
- (void)refreshTime:(NSDictionary *)list limited:(BOOL)limited forceRequest:(BOOL)forceRequest;
@end
