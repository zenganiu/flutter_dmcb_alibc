////
////  TBARVAppInfoConfigManager.h
////  AriverDemo
////
////  Created by zhongweitao on 2019/3/27.
////  Copyright © 2019 alipay.com. All rights reserved.
////
//
//#import <Foundation/Foundation.h>
//
//static NSString *const kTopAppConfigStrategySyncLoad = @"syncLoad";
//static NSString *const kTopAppConfigStrategyAsyncLoad = @"asyncLoad";
//
//@interface TRVAppInfoConfigItem : NSObject
//
//@property (nonatomic, strong) NSString *appId;
//@property (nonatomic, assign) NSTimeInterval timestamp;
//@property (nonatomic, strong) NSString *strategy; // @"syncLoad" / @"asyncLoad"
//
//@property (nonatomic, assign) BOOL expired;
//
//@end
//
//@interface TRVAppInfoConfigManager : NSObject
//
//+ (TRVAppInfoConfigManager *)sharedInstance;
//
//- (void)registerConfigUpdateListener;
//
//- (NSArray<NSString *> *)expiredConfigAppIds;
//
//- (NSArray<NSString *> *)allConfigAppIds;
//
///// @brief 根据appId获取配置项，没有返回空
//- (TRVAppInfoConfigItem *)configItemForAppId:(NSString *)appId;
//
///// @brief 重置对应的appId配置为不过期，内部会判断appId是否是top app
//- (void)resetExpiredForAppId:(NSString *)appId;
//
///// @brief 批量重置对应的appId配置为不过期，内部会判断appId是否是top app
//- (void)resetExpiredForAppIds:(NSArray<NSString *> *)appIds;
//
//@end
//
