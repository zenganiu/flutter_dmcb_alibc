//
//  WMLNetworkProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/7/17.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import "WMLRequestTask.h"
#import <Foundation/Foundation.h>

/**
 表示网络请求的接口。
 */
@protocol WMLNetworkProtocol <NSObject>

@required

/**
 发送指定的请求。
 
 @param task 要发送的请求。
 @param userInfo 额外信息。
 */
- (void)startRequestTask:(id<WMLRequestTask> _Nonnull)task userInfo:(NSDictionary * _Nullable)userInfo;

/**
 停止指定的请求。
 
 @param task 要停止的请求。
 @param userInfo 额外信息。
 */
- (void)stopRequestTask:(id<WMLRequestTask> _Nonnull)task userInfo:(NSDictionary * _Nullable)userInfo;

@end
