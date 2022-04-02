//
//  AlibcTradeUltimateLoginService.h
//  AlibcTradeUltimateSDK
//
//  Created by zhongweitao on 2020/7/29.
//  Copyright © 2020 shan yi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AlibcTradeUltimateBizSDK/AlibcTradeLoginBridge.h>

/// @brief 登录通知
extern NSString *const ALBCTradeNotificationUserLoggedIn;
/// @brief 登出通知
extern NSString *const ALBCTradeNotificationUserLoggedOut;

typedef void (^AlibcLoginSuccess)(AlibcUser *user);
typedef void (^AlibcLoginFailure)(NSError *error);

@protocol AlibcTradeUltimateLoginService <NSObject>

/// @brief 是否登录
- (BOOL)isLogin;

/// @brief 登录
- (void)auth:(UIViewController *)parentController success:(AlibcLoginSuccess)success failure:(AlibcLoginFailure)failture;

/// @brief 退出登录
- (void)logout;

- (void)setH5Only:(BOOL)h5Only;

/// @brief 获取登录用户信息
- (AlibcUser *)getUser;

@end
