//
//  RVPJSApiResGetUserInfo.h
//  AriverApi
//
//  Created by xuyouyang on 2019/5/10.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResGetUserInfo : RVKJSApiResponseBase

/**
 * 用户的avatar
 */
@property (nonatomic, strong) NSString *iconUrl;

/**
 * 用户的昵称
 */
@property (nonatomic, strong) NSString *nick;

/**
 * 用户id
 */
@property (nonatomic, strong) NSString *userId;

/**
 * 用户的脱敏登录账号
 */
@property (nonatomic, strong) NSString *loginId;

/**
 * 用户的脱敏真实姓名
 */
@property (nonatomic, strong) NSString *userName;

@end

NS_ASSUME_NONNULL_END
