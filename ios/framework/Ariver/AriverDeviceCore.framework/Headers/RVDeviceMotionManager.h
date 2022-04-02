//
//  RVDeviceMotionManager.h
//  AriverDeviceCore
//
//  Created by ZQP on 2019/4/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RVDeviceMotionResultCallback)(id data);

@interface RVDeviceMotionManager : NSObject

@property (nonatomic, readonly) CMMotionManager  *motionManager;

- (void)startDeviceMotionWithInterval:(NSTimeInterval)interval callback:(RVDeviceMotionResultCallback)callback;
- (void)stopDeviceMotion;

@end

NS_ASSUME_NONNULL_END
