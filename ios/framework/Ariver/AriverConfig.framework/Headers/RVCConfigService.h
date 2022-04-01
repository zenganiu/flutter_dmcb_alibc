//
//  RVCConfigService.h
//  AriverConfig
//
//  Created by theone on 2019/4/24.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>
#import <AriverKernel/RVKPage.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

NS_ASSUME_NONNULL_BEGIN

// App的rootViewController启动时的展示方式
typedef NS_ENUM(NSInteger, RVCDTMicroApplicationLaunchMode) {
        kRVCDTMicroApplicationLaunchModeClearTop,              // 保留定义，暂时不支持。
        kRVCDTMicroApplicationLaunchModePushWithAnimation,     // 有动画的Push方式展示。
        kRVCDTMicroApplicationLaunchModePushNoAnimation,       // 无动画的Push方式展示。
        kRVCDTMicroApplicationLaunchModePresentWithAnimation,  // 有动画的Present方式展示。
        kRVCDTMicroApplicationLaunchModePresentNoAnimation,    // 无动画的Present方式展示。
        kRVCDTMicroApplicationLaunchModeFlipFromLeft,          // 左侧弹出的Push方式展示。
        kRVCDTMicroApplicationLaunchModeFlipFromRight,         // 右侧弹出的Push方式展示。
};

//解除对于开关的耦合，将相应的开关配置协议写到这里，各个接入端，可以各自实现
@protocol RVCConfigService <RVAServiceProtocol>
@required
-(NSArray *)internalAPIWhiteList;       //[[[H5Configs sharedConfigs] internalAPIWhiteList] containsObject:method]
@optional
-(void)startApplication:(NSString *)appId
                 params:(NSDictionary *)mParams
             launchMode:(RVCDTMicroApplicationLaunchMode )launchMode
               sourceId:(NSString *)sourceId;
-(NSDictionary *)acAppForId:(NSString *)appId stageCode:(NSString *)stageCode;
-(BOOL)enableFilterRepeatSubpackageTask;

//权限相关开关
- (BOOL)downgradeJsApiPermissionCheck;
- (BOOL)downgradePermissionCheck;
- (NSArray *)webviewSudoList;
- (NSArray *)webviewJsapiWhiteList;
- (NSArray *)globleApiWhiteList;
- (BOOL)shouldGoSpdy;
- (NSArray *)forceGoSpdyBlackList;
- (NSArray *)ta_http_domain_blacklist;
- (NSArray *)ta_comp_permission_check_appid_whitelist;
- (NSArray *)ta_comp_permission_check_type_list;
- (NSArray *)ta_embedwebview_white_domain_list;
- (NSArray *)ta_embedwebview_white_domain_list_with_nb;
- (NSArray *)ta_embedwebview_white_appid_list_with_nb;
- (NSArray *)ta_embedwebview_inner_appId_black_list;
- (NSArray *)ta_close_webviewschemawhitelist;
- (NSArray *)ta_render_jsapi_blacklist;
- (NSString *)ta_ssl_app_id;
- (NSArray *)ta_use_tls_whitelist;
- (BOOL)ta_embedwebview_domain_newregex;
- (NSDictionary *)ta_webview_open_appidlist;
- (NSDictionary *)ta_common_storage:(NSString *)querykey;
- (BOOL )taLimitControl:(NSString*)appId;
- (NSArray *)taRequestProxylist;
- (NSDictionary *)taBanmpExtSchemelist;
- (BOOL)taRequestRequestHTTPBody;
// checkJSAPI 开关
- (BOOL)ignoreCheckResult:(RVKScene *)page;
- (NSArray *)debugJsApiDomainWhitelist;
// 淘侧获取动态配置API
- (id)configByGroupName:(NSString *)groupName key:(NSString *)key defaultConfig:(id)defaultConfig isDefault:(nullable BOOL *)isDefault;

//ali相关域名白名单
- (NSArray *)aliWhitelist;
- (NSArray *)alipayWhitelist;
- (NSArray *)seriousAliWhitelist;

//JSC相关
//jsapi回调给前端时参数是否能支持nsdata->arraybuffer
- (BOOL)jsApiEnableArrayBuffer:(NSString *)jsApiName;
//给前端发puh消息时参数是否能支持nsdata->arraybuffer
- (BOOL)jsEventEnableArrayBuffer:(NSString *)jsEventName;
//js->native是否使用新的通道以支持arraybuffer->nadata
- (BOOL)jsApiEnableOptimizedChannel;

//! 传递给appx前，对启动参数做修改
- (void)handleStartupParamsBeforeGiveToAppx:(NSMutableDictionary *)mOptionsDict session:(RVKSession*)session;
//透传native的config至appx启动参数
- (NSArray *)appxStartupParamConfigKeys;

- (NSDictionary *)pluginPermission;

//是否需要强制设置window的Interaction状态规避input问题建议返回NO
- (BOOL)shouldSetInteractionWithWaitRender:(double)wateRender;
//二方组件是否配置了止血版本
- (NSString *)addPkgResStricklyMatchVersion:(NSString *)appId;

//只给worker发的js事件是否需要发invocationStartEvent
- (BOOL)workerOnlyEventNeedDispatch;

//通用的配置获取方法
- (NSString *)configForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
