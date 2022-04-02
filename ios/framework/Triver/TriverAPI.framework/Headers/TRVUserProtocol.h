//
//  TRVUserProtocol.h
//  API
//
//  Created by xuyouyang on 2019/5/29.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVUserProtocol <NSObject>

@required
// 用户唯一标识，如，[ALBBAccountLogin sharedInstance].getUserId
- (NSString *)userId;

// 用户的昵称，如，[ALBBAccountLogin sharedInstance].getUserNick
- (NSString *)getUserNick;

// 用户的头像链接，如，[ALBBAccountLogin sharedInstance].getUserHeadPicLink
- (NSString *)getUserHeadPicLink;

// 用于 tradePay 中，从 [[[ALBBLoginCenter sharedInstance] currentSession] objectForKey:@"sid"]; 中获取
- (NSString *)sessionId;

@end

NS_ASSUME_NONNULL_END
