//
//  WMLMonitorAlarm.h
//  Weaver
//
//  Created by lianyu on 2018/4/23.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 表示告警埋点的信息。
 如果没有 errorCode，则认为是成功；否则认为失败。
 */
@interface WMLMonitorAlarm : NSObject

/**
 告警埋点的模块名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * monitorModule;

/**
 告警埋点的监控点名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * monitorPoint;

/**
 告警埋点的额外信息。
 */
@property (nonatomic, copy, nullable) NSString * arg;

/**
 告警埋点的错误码。
 */
@property (nonatomic, copy, nullable) NSString * errorCode;

/**
 告警埋点的错误信息。
 */
@property (nonatomic, copy, nullable) NSString * errorMsg;

/**
 使用指定的埋点名称创建告警埋点。
 
 @param name 埋点名称，使用 模块名.监控点名 的格式。
 */
+ (instancetype _Nullable)alarmWithName:(NSString * _Nonnull)name;

/**
 使用指定的监控点名称和错误信息创建告警埋点。
 
 @param name 埋点名称，使用 模块名.监控点名 的格式。
 @param error 错误信息。
 */
+ (instancetype _Nullable)alarmWithName:(NSString * _Nonnull)name error:(NSError * _Nullable)error;

/**
 使用指定的监控点名称和错误信息创建告警埋点。
 
 @param name 埋点名称，使用 模块名.监控点名 的格式。
 @param errorCode 错误码。
 @param errorMsg 错误消息。
 */
+ (instancetype _Nullable)alarmWithName:(NSString * _Nonnull)name errorCode:(NSString * _Nullable)errorCode errorMsg:(NSString * _Nullable)errorMsg;

@end
