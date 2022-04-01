//
//  TBModuleHuber+TBMPBConfigDependence.h
//  TBModuleHub
//
//  Created by qiufu on 4/11/17.
//  Copyright © 2017 CX. All rights reserved.
//

#import <TBModuleHub/TBModuleHub.h>

@interface TBModuleHuber (TBMPBConfigDependence)

/*!
 * @abstract 获取播放器 Orange 配置。
 */
- (NSDictionary *)TBModuleHuber_TBMPBConfigDependence_orangeConfig;

/*!
 * @abstract 获取当前网络状态。
 */
- (NSNumber *)TBModuleHuber_TBMPBConfigDependence_networkStatus;

/*!
 * @abstract 获取当前网络运营商 IMSI。
 */
- (NSString *)TBModuleHuber_TBMPBConfigDependence_networkIMSI;

/*!
 * @abstract 根据 host 获取指定 IP。
 */
- (NSString *)TBModuleHuber_TBMPBConfigDependence_policyIPWithParameters:(NSDictionary *)parameters;

/*!
 * @abstract 根据 host 和 protocal 获取指定IP组。
 */
- (NSArray *)TBModuleHuber_TBMPBConfigDependence_policyIPsWithParameters:(NSDictionary *)parameters;

/*!
 * @abstract 获取当前设备及网络状态等信息。
 */
- (NSDictionary *)TBModuleHuber_TBMPBConfigDependence_userAgentInfo;

/*!
 * @abstract 获取当前module和component对应的ABTest分桶信息。
 */
- (NSDictionary *)TBModuleHuber_TBMPBConfigDependence_ABTestBucketInfoWithParameters:(NSDictionary *)parameters;

/*!
 * @abstract 查看当前手淘环境下Macro是否定义，返回@(YES) or @(NO)
 */
- (NSNumber*)TBModuleHuber_TBMPBConfigDependence_DidMacroDefined:(NSDictionary *)parameters;

@end
