/*
 * AlibcTradeLoginBridge.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeUltimateBizSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AlibcTradeCommonSDK/AlibcConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcUser : NSObject

/** 昵称 */
@property (nonatomic, copy) NSString *nick;
/** 头像地址 */
@property (nonatomic, copy) NSString *avatarUrl;

@property (nonatomic, copy) NSString *openId;
@property (nonatomic, copy) NSString *openSid;

@property (nonatomic, copy) NSString *topAccessToken;
@property (nonatomic, copy) NSString *topAuthCode;

@end

/** 回调定义 */
typedef void (^AlibcLoginSuccessCallback)(NSString *userId,
                                          NSString *userNick,
                                          NSString *avatarUrl,
                                          NSString *topAccessToken,
                                          NSString *topAuthCode);
typedef void (^AlibcLoginFailureCallback)(NSError *error);

@interface AlibcTradeLoginBridge : NSObject

/**
 登录模块标准初始化接口
 */
+ (void)initLogin;

/**
 判断是否已经登录
 */
+ (BOOL)isLogin;

/**
 登录模块极简版初始化接口

 @brief 极简版没有依赖安全模块, 需要手动传入 Appkey

 @param appkey appkey
 */
+ (void)initLoginWithAppkey:(NSString *)appkey;

+ (BOOL)isLoginSvrAvaleable;

+ (void)showLogin:(UIViewController *)parentController
    successCallback:(AlibcLoginSuccessCallback)onSuccess
     failedCallback:(AlibcLoginFailureCallback)onFailure;

+ (NSDictionary *)getLoginUserInfo;

+ (void)logout;

+ (void)setEnvironment:(AlibcEnvironment)env;

/**
 是否是登陆URL
 */
+ (BOOL)isLoginURL:(NSString *)url;

/**
 是否是登出URL
 */
+ (BOOL)isLogoutUrl:(NSString *)url;

/**
 手淘跳转回来，拿到url调用
 */
+ (BOOL)loginByURL:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
