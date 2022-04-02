//
//  TRVConfigCenter.h
//  Runtime
//
//  Created by xuyouyang on 2019/5/16.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TRVPageLoadedNotification @"TRVPageLoadedNotification"

NS_ASSUME_NONNULL_BEGIN

@interface TRVConfigCenter : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign) BOOL downgradeApiPermission;

/**
 * RPC 开关，Group Name: group_windmill_rpc_ios, 反射调用
 */
- (NSString *)fetchAlipayRPCCconfigWithKey:(NSString *)key;

/**
 强制 CDN 下载 APPX 的地址
 */
- (NSString *)forceCDNDownloadAppxURL;

/**
 店铺 appx render 的附加 js CDN 地址
 */
- (NSString *)trvRenderAppendCDNDownloadAppxURL;

/**
 *  小程序店铺的 二方组件js缓存 的最大时长（单位 s）
 */
- (NSInteger)trvShopRenderAppendJSCacheMaxAge;

/**
 * crash 时，提交小程序的相关信息
 */
- (BOOL)trvCommitCrashInfo;

/**
 * 全局 jsapi 白名单
 */
- (NSArray *)globalAPIWhiteList;

/**
 * 通过 internalAPI 来调用的 jsapi 白名单
 */
- (NSArray *)internalAPIWhiteList;

/**
 * <web-view> 组件中 jsapi 权限白名单， appId 的列表
 */
- (NSArray *)webviewSudoList;

/**
 * <web-view> 组件中可使用的 jsapi 名称列表
 */
- (NSArray *)webviewJsapiWhiteList;

/**
 * 多媒体源域名白名单
 */
- (NSArray *)mediaDomainWhiteList;

/**
 * 强制关闭线上真机调试
 */
- (BOOL)forceCloseRemoteDebug;

/**
 * 开启 “普通” save snapshot 的小程序白名单
 */
- (NSArray *)saveSnapshotWhiteList;

/**
 * 开启 “普通” save snapshot 的小程序模板白名单
 */
- (NSArray *)saveSnapshotTemplateWhiteList;

/**
* 开启 “模板” save snapshot 的小程序白名单
*/
- (NSArray *)saveTemplateSnapshotWhiteList;

/**
* 开启 “模板” save snapshot 的小程序模板白名单
*/
- (NSArray *)saveTemplateSnapshotTemplateWhiteList;

/**
* 读取 template snapshot js 结合数据预取
*/
- (NSArray *)readTemplateSnapshotJSWithDataWhiteList;

/**
* 开启 “模板” snapshot 文件夹清理功能
*/
- (BOOL)enableTemplateSnapshotDirectoryClean;

/**
 * snapshot 文件有效期，默认 3 天。
 */
- (NSTimeInterval)snapshotExpireDate;

/**
 * 关闭内嵌小程序上报自身舆情信息（旗舰店2.0）
 */
- (BOOL)disableEmbedTinyAppFeedback;

/**
 * 关闭内嵌小程序 Weex 的 ariver 组件可以回收
 */
- (BOOL)disableAriverComponentRecycle;

/**
 * 需要把事件同步到Worker的白名单
 */
- (NSDictionary *)eventThroughWorkerConfig;

/**
 * 关闭 URL 参数动态解析
 */
- (BOOL)disableURLHotParse;

/**
 * 是否开启多媒体源白名单
 */
- (BOOL)enableMediaDomainWhiteList;

/**
 禁止 weex-view 针对店铺分类页的滚动处理
 */
- (BOOL)disableShopCategoryScrollHanler;

/**
 禁止 weex-view 针对店铺 isv 自定义分类页的滚动处理
 */
- (BOOL)disableShopCustomCategoryScrollHanler;

/**
 同步释放 Worker 的 JSContext
 */
- (BOOL)enableWorkerDeallocSync;

#pragma mark - API
/**
 * 是否使用手淘 video
 */
- (BOOL)enableVideoEnhance;
/**
 * my.openLocation 打开的界面隐藏跳转 “高德” 的按钮。
 */
- (BOOL)openLocationHideAmapNav;

/**
 * 是否使用 native input 同层渲染组件
 */
- (BOOL)enableNativeInputComponent;

/**
 *  打开 nativeInput 的小程序白名单
 */
- (NSArray *)nativeInputWhiteList;

/**
 * 是否降级小程序框架mtop导购域名到默认域名
 */
- (BOOL)downgradeFrameworkMtopGuideHost;

/**
 真机调试网路请求域名白名单
 */
- (NSArray *)debugJsApiDomainWhitelist;

/**
 关闭 api 调用是的 tlog 日志
*/
- (BOOL)disableApiInvokeTLog;

/**
 是否打开iPadOS adaptivelayout 的开关
 */
- (BOOL)enableIPadAdaptivelayout;

/**
 关闭 <weex-view> 主动降级的能力
 */
- (BOOL)disableWeexComponentDowngrade;

/**
 是否开启插件存储功能
 */
- (BOOL)enablePluginTinyLocalStorage;

/**
 <ariver> finish load 后重新 layout 的时间, 单位 ms
 */
- (NSInteger)ariverComponentLayoutDispatchTime;

/**
 关闭文件系统插件隔离
*/
- (BOOL)disableFileSystemDistinguishPluginFile;

/**
 关闭文件系统插件隔离(插件列表)
*/
- (NSString *)disableFileSystemDistinguishPluginFilePluginIds;

/**
 开启 showLoading 自动隐藏
 */
- (BOOL)enableAutoDissmissForShowLoading;

/**
 * 网络请求预取域名白名单
 */
- (NSArray *)httpRequestPrefetchDomainWhiteList;

/**
* 关闭往 jscontext 中写 navigator.systemInfo 信息
*/
- (BOOL)disableNavigatorSystemInfo;

@end

NS_ASSUME_NONNULL_END
