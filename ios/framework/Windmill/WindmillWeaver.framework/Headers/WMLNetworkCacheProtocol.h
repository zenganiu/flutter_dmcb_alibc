//
//  WMLNetworkCacheProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/8/22.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 表示网络请求缓存的接口。
 */
@protocol WMLNetworkCacheProtocol <NSObject>

@required

/**
 处理指定请求，并返回缓存的响应和数据。
 
 @param request 要处理的 URL。
 @param userInfo 额外信息。
 
 @return 如果当前处理接口能够处理当前缓存请求，则返回被缓存的响应；否则返回 nil。
 */
- (NSCachedURLResponse * _Nullable)cachedResponseForRequest:(NSURLRequest * _Nonnull)request userInfo:(NSDictionary * _Nullable)userInfo;

@end
