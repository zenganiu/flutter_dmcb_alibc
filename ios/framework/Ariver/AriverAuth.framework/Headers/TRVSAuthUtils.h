//
//  TRVSAuthUtils.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/23.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVSAuthContext.h"
#import <AriverResource/RVRApp.h>

#pragma mark - Monitor
#define TRVS_PageName                 @"Triver"
#define TRVS_MonitorPoint_Auth        @"auth"
#define TRVS_MonitorPoint_AuthInfo    @"auth_info"
#define TRVS_MonitorPoint_AuthToken   @"auth_token"
#define TRVS_MonitorMsg_Server_Error  @"服务端返回格式出错"

@class TRVSScopeModel;
@interface TRVSAuthUtils : NSObject

#pragma mark - UserID
+ (NSString *)getCurrentUserId;

#pragma mark - AccessToken
+ (NSString *)getValidAccessTokenWithAppKey:(NSString *)appKey;
+ (TRVSAuthStatus)getScopeAuthStatuWithContext:(TRVSAuthContext *)context;
+ (NSString *)buildNewAccessTokenInfo:(NSString *)accessToken period:(NSString *)period;
+ (NSString *)getAuthTokenSavedKeyWithAppKey:(NSString *)appKey;
+ (NSString *)getValidAccessToken:(NSString *)accessTokenInfo;
+ (void)removeAccessTokenWithAppKey:(NSString *)appKey;

#pragma mark - Scope;
+ (void)updateScope:(TRVSScopeModel *)scope appKey:(NSString *)appKey;
+ (void)saveScopes:(NSArray<TRVSScopeModel *> *)scopes appKey:(NSString *)appKey;
+ (NSArray<NSDictionary*> *)getSavedScopeModelsForAppKey:(NSString *)appKey userId:(NSString *)userId authRange:(TRVSAuthRange)authRange;

#pragma mark - Permission
+ (BOOL)needAuthForApp:(RVRApp *)app pluginId:(NSString *)pluginId;
/// @brief 判断是否是官方小程序
+ (BOOL)offical4App:(RVRApp *)app pluginId:(NSString *)pluginId;
/// @brief 判断是否需要静默授权
+ (BOOL)needSilenceAuth4App:(RVRApp *)app pluginId:(NSString *)pluginId;

#pragma mark - downgrade
+ (BOOL)downgradePluginInfo;

@end

