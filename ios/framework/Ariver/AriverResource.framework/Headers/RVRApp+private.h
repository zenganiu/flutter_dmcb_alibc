//
//  NXRApp+private.h
//  AriverResource
//
//  Created by nico on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "RVRApp.h"
NS_ASSUME_NONNULL_BEGIN

@interface RVRApp (Private)
@property (nonatomic, assign, readonly) NSTimeInterval lastRefreshTime;   // 上次更新时间
@property (nonatomic, assign, readonly) BOOL limiting;                    // 异步请求被限流
@property (nonatomic, assign, readonly) BOOL strictlimiting;              // 强制请求被限流
/**
 *  更新上次请求时间
 *
 *  @param time    时间
 *  @param limited 是否被限流
 */
- (void)refresh:(NSTimeInterval)time limited:(BOOL)limited strict:(BOOL)strict;
@end

NS_ASSUME_NONNULL_END
