//
//  TRVRuntime.h
//  Runtime
//
//  Created by xuyouyang on 2019/4/16.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindMix/WindMix.h>
#import <WindVaneCore/WindVaneCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface TRVWebView : WVWKWebView
@end 

@interface TRVRuntime : NSObject

/**
 * SDK 初始化时执行
 */
+ (void)setup;

/**
 * 设置是否支持 WKWebView 的 NSURLProtocol 拦截。
 */
+ (void)setSupportWKURLProtocol:(BOOL)supportWKURLProtocol;

@end

NS_ASSUME_NONNULL_END
