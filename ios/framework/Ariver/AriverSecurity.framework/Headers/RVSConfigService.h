//
//  RVSConfigService.h
//  AriverSecurity
//
//  Created by theone on 2019/4/9.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>
#import <AriverKernel/RVKEvent.h>
#import <AriverResource/RVRApp.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^RVSConfigServiceInterceptCallback)(NSDictionary *result, NSError *error);


@protocol RVSConfigService <RVAServiceProtocol>


@optional

// 判断是否是内部小程序
// 对内部小程序做权限特殊处理时，会用到
- (BOOL)isInnerTinyApp:(NSString *)string;

// 判断是否是官方插件
- (BOOL)isOfficialPlugin:(NSString *)pluginId mainApp:(RVRApp *)mainApp;

- (NSData *)permissionDataWithQueryKey:(NSString *)querykey;

- (void)requestLimitControlDataWithParams:(NSDictionary *)params
                                 callback:(RVSConfigServiceInterceptCallback)callback
                                  timeout:(NSTimeInterval)timeout;

- (void)requestProxyDataWithParams:(NSDictionary *)params
                          callback:(RVSConfigServiceInterceptCallback)callback
                           timeout:(NSTimeInterval)timeout;

- (BOOL)shouldSkipPermissonJudgeWithWebviewUrl:(NSString *)urlStr config:(NSDictionary *)config;

/**
 展示特定的错误页面
 */
- (void)showWebViewErrorPageWithEvent:(RVKEvent *)event;

/**
 特定错误页面的地址
 */
- (NSString *)errorPageUrl;

- (NSDictionary *)getPermissionWithAppId:(NSString *)appId;
@end

NS_ASSUME_NONNULL_END
