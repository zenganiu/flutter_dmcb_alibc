//
//  TRVCustomizeDomainPermissionManager.h
//  AppContainer
//
//  Created by 岚遥 on 2019/12/4.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverResource/RVRApp.h>

extern NSString * _Nonnull const TRVCustomizeDomainPermissionPluginsAll;

typedef NS_ENUM(NSUInteger, TRVCustomizeDomainType) {
    TRVCustomizeDomainTypeA,    // A类域名白名单（官方域名白名单）
    TRVCustomizeDomainTypeB,    // B类域名白名单（自定义白名单）
    TRVCustomizeDomainTypeC     // 多媒体域名白名单 A+B
};

NS_ASSUME_NONNULL_BEGIN

// 通用自定义白名单鉴权
@interface TRVCustomizeDomainPermissionManager : NSObject

/**
 根据 app 实例返回当前域名管控实例
 @param app              当前小程序宿主 app 对象
 */
- (instancetype)initWithApp:(RVRApp *)app;

/**
 @param pluginId 设置当前调用的插件id
 */
- (void)setCurrentPluginId:(NSString *)pluginId;

/**
 返回域名白名单
 */
- (NSSet *)domainWhiteListWithType:(TRVCustomizeDomainType)type;

/**
 判断域名是否在白名单中
 */
- (BOOL)domainIsInWhiteListWithUrlString:(NSString *)urlString
                              domainType:(TRVCustomizeDomainType)type;

/**
 返回鉴权后的多媒体src地址
 */
- (NSString *)permissionDomainMediaSourceStringFromOriginSource:(NSString *)srcUrl;

/**
 清理域名白名单
 */
- (void)clearWhiteList;

@end

NS_ASSUME_NONNULL_END
