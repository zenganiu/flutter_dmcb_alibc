//
//  TRVUTUtil+Shop.h
//  Runtime
//
//  Created by xuyouyang on 2020/3/31.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import "TRVUTUtil.h"

NS_ASSUME_NONNULL_BEGIN

@interface TRVUTUtil (Shop)

#pragma mark - 页面性能
/// @brief 店铺页面渲染性能埋点
/// https://yuque.antfin-inc.com/cross_platform/dwrts1/vmu4wr#WWpnX
+ (void)commitShopPageRenderFinished:(RVRApp *)app
								 url:(NSString *)url
							  tabKey:(NSString *)tabKey
						  renderType:(NSString *)renderType
				  shopPageRenderTime:(NSNumber *)renderTime;

/// @brief 店铺 render 预渲染
+ (void)commitShopRenderPreload:(RVRApp *)app
					  isSuccess:(BOOL)isSuccess;

/// @brief 店铺 template snapshot & 数据
+ (void)commitShopTemplateSnapshotRender:(RVRApp *)app
							   isSuccess:(BOOL)isSuccess;

#pragma mark - 网络请求
/// @brief 店铺 shopfetch 预取命中率
+ (void)commitShopPreFetch:(RVRApp *)app
				 isSuccess:(BOOL)isSuccess;

/// @brief 店铺 shopfetch 预取耗时(ms)
+ (void)commitShopPreFetchWithAppId:(NSString *)appId
							 shopId:(NSString *)shopId
						   timeCost:(NSNumber *)timeCost;

/// @brief 店铺 pagedata 预取命中率
+ (void)commitShopPrePageData:(RVRApp *)app
					isSuccess:(BOOL)isSuccess;

/// @brief 店铺 pagedata 预取耗时(ms)
+ (void)commitShopPrePageData:(RVRApp *)app
					 timeCost:(NSNumber *)timeCost;

@end

NS_ASSUME_NONNULL_END
