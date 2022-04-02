//
//  RVAMonitor.h
//  AriverApp
//
//  Created by chenwenhong on 15/10/8.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>
#import <AriverResource/RVRProtocol+private.h>

//#define RVAMonitorParamsAppId @"appId"
//#define RVAMonitorParamsUrl @"url"
//#define RVAMonitorParamsVersion @"version"
//#define RVAMonitorParamsLogStr @"logStr"

@protocol RVKLoggerProtocol;

@protocol RVAMonitorDelegate;

@protocol RVRLogManagerDelegate;

@protocol RVALocalLogDelegate;

@interface RVAMonitor : NSObject <RVRLogManagerDelegate,RVKLoggerProtocol>

@property(nonatomic, weak) id<RVAMonitorDelegate> delegate;
@property(nonatomic, weak) id<RVALocalLogDelegate> localLogDelegate;

+ (instancetype)defaultMonitor;

// 上报给后台的埋点日志
- (void)logWithLogId:(NSString *)logId params:(NSDictionary *)params;
- (void)logWithLogId:(NSString *)logId params:(NSDictionary *)params target:(RVKKernel *)target;

// 写在本地的日志
- (void)localLog:(NSString *)logString;

//禁止创建实例
+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

@end

@protocol RVALocalLogDelegate <NSObject>
@optional
- (void)monitor:(RVAMonitor *)monitor localLog:(NSString *)logString;
@end


@protocol RVAMonitorDelegate <NSObject>

- (void)monitor:(RVAMonitor *)monitor logWithLogId:(NSString *)logId params:(NSDictionary *)params;

@optional
- (void)monitor:(RVAMonitor *)monitor logWithLogId:(NSString *)logId params:(NSDictionary *)params target:(RVKKernel *)target;


@end
