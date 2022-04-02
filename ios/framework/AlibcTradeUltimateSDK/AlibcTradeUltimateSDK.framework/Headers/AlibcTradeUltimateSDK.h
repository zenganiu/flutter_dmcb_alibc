/*
 * AlibcTradeUltimateSDK.h
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeUltimateSDK
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "AlibcTradeUltimateSDKService.h"
#import "AlibcTradeUltimateLoginService.h"
#import <AlibcTradeUltimateBizSDK/AlibcTradeTaokeParams.h>

NS_ASSUME_NONNULL_BEGIN

@class UIApplication;
@interface AlibcTradeUltimateSDK : NSObject

/**
 *  AlibcTradeUltimateSDK 的单例对象
 */
+ (instancetype)sharedInstance;

/**
 *  初始化函数,初始化成功后方可正常使用SDK中的功能
 *  @param success 初始化成功的回调
 *  @param failure 初始化失败的回调
 */

- (void)asyncInitWithSuccess:(void (^)(void))success
                     failure:(void (^)(NSError *error))failure;

/**
 * App 回跳处理, 适用于 iOS 9 起的回调接口
 
 @param url url
 @param options options
 @return handled or nor
 */
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<NSString *, id> *)options;

/**
 获取service对象,该对象包含大部分Trade相关的方法
 */
- (id<AlibcTradeUltimateSDKService>)tradeService;

/// @brief 获取登录服务
- (id<AlibcTradeUltimateLoginService>)loginService;

@end

@interface AlibcTradeUltimateSDK (DevSetting)

#pragma mark - 开发配置
- (void)setDebugLogOpen:(BOOL)isDebugLogOpen;

/// @brief 是否关闭自检工具（默认开启）
- (void)enableLocalDebug:(BOOL)enable;

/// @brief 是否开启自动显示自检工具入口（默认关闭）
- (void)enableAutoShowDebug:(BOOL)enable;

/// @brief 手动显示自检工具
- (void)showLocalDebugTool:(UIViewController *)parentViewController;

@end

@interface AlibcTradeUltimateSDK (BizSetting)

#pragma mark - 业务参数

/**
 *  设置App标识字段,和isvcode同义,可用于区分使用本SDK的具体三方App
 *
 *  @param code isv code 字段
 */
- (void)setISVCode:(NSString *)code;

/**
 *  设置渠道信息,渠道专享价专用.
 *
 *  @param type 渠道类型，必须由数字和字母组成，否则无效
 *  @param name 渠道名，必须由数字和字母组成，否则无效
 */
- (void)setChannel:(NSString *)type name:(NSString *)name;

/**
 *  开启接口免授权模式,
 *  请不要随便设置,没有在后台申请相关的权限的,开启后会导致网络请求失败
 *
 */
- (void)enableAuthVipMode;

@end

NS_ASSUME_NONNULL_END
