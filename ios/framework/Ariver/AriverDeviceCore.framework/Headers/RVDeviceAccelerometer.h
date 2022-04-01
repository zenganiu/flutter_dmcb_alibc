//
//  RVDeviceAccelerometer.h
//  AriverDeviceCore
//
//  Created by ZQP on 2019/4/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

#define kExpandPropertyKey_Accelerometer         @"kExpandPropertyKey_Accelerometer"
#define kExpandPropertyKey_IsWatchShake          @"kExpandPropertyKey_IsWatchShake"
#define kExpandPropertyKey_WatchShakeCallback    @"kExpandPropertyKey_WatchShakeCallback"
#define kExpandPropertyKey_IsMonitorAccelerometer @"kExpandPropertyKey_IsMonitorAccelerometer"
#define kExpandPropertyKey_Compass               @"kExpandPropertyKey_Compass"
#define kExpandPropertyKey_IsWatchCompass        @"kExpandPropertyKey_IsWatchCompass"
#define kExpandPropertyKey_WatchCompassCallback  @"kExpandPropertyKey_WatchCompassCallback"
#define kExpandPropertyKey_Gyro                  @"kExpandPropertyKey_Gyro"
#define kExpandPropertyKey_IsWatchGyro           @"kExpandPropertyKey_IsWatchGyro"
#define kExpandPropertyKey_WatchGyroCallback     @"kExpandPropertyKey_WatchGyroCallback"

typedef void (^RVDAccelerometerCallback)(id _Nullable data);

NS_ASSUME_NONNULL_BEGIN

@interface RVDeviceAccelerometer : NSObject

- (void)watchAccelerationCompleteBlock:(RVDAccelerometerCallback)callback;

- (void)clearWatchAcceleration;

- (void)watchAccelerationWithInterval:(CGFloat)interval
                         shouldFilter:(BOOL)shouldFilter
                             callback:(CMAccelerometerHandler)callback;

@end

NS_ASSUME_NONNULL_END
