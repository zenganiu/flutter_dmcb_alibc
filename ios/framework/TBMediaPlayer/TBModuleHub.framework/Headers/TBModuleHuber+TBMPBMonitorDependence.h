//
//  TBModuleHuber+TBMPBMonitorDependence.h
//  TBModuleHub
//
//  Created by qiufu on 12/5/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <TBModuleHub/TBModuleHub.h>

@interface TBModuleHuber (TBMPBMonitorDependence)

/*!
 * @abstract 接收性能式埋点数据并发送给埋点数据处理模块。
 *
 * @param data 性能埋点数据。性能埋点数据格式：
 * - module：模块名(NSString *)。根据接入方在使用 TBMPBPlayerView 时传入的 businessId 拼接而成，比如当 businessId = @"xxx" 时，对应的 module 为 @"TBMediaPlayerBundle-xxx"。
 * - point：监测点名字(NSString *)。
 * - type：监控点类型(NSNumber *)->(int32_t)。与 point 是一一映射的。
 * - dimension：性能埋点维度信息(NSDictionary *)。维度信息的具体格式参加具体埋点。
 * - performance：性能埋点指标信息(NSDictionary *)。指标信息的具体格式参加具体埋点。
 *
 */
- (void)TBModuleHuber_TBMPBMonitorDependence_commitPerformanceData:(NSDictionary *)data;

/*!
 * @abstract 接收告警式埋点数据并发送给埋点数据处理模块。
 *
 * @param data 告警埋点数据。告警埋点数据格式：
 * - module：模块名(NSString *)。根据接入方在使用 TBMPBPlayerView 时传入的 businessId 拼接而成，比如当 businessId = @"xxx" 时，对应的 module 为 @"TBMediaPlayerBundle-xxx"。
 * - point：监测点名字(NSString *)。
 * - type：监控点类型(NSNumber *)->(int32_t)。与 point 是一一映射的。
 * - status：告警状态(NSNumber *)->(int32_t)。0：失败；1：成功。
 * - arg：说明信息(NSString *)。
 * - errorCode：错误码(NSString *)。当上报失败状态时附带的错误码。
 * - errorMessage：错误信息(NSString *)。当上报失败状态时附带的错误信息。
 *
 */
- (void)TBModuleHuber_TBMPBMonitorDependence_commitAlarmData:(NSDictionary *)data;

@end
