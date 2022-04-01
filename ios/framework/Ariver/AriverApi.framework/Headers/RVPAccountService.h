//
//  RVPAccountService.h
//  AriverApi
//
//  Created by nico on 2019/5/29.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RVPAccountService <NSObject>

@optional

/**
 * 当前登录用户 token
 */
- (NSString *)currentUserToken;

/**
 * 当前登录 session id。用于 tradePay 中，淘系中从 [[ALBBLoginCenter sharedInstance] currentSession]; 中获取
 */
- (NSString *)currentSessionId;

@end

NS_ASSUME_NONNULL_END
