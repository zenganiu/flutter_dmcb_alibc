//
//  RVDeviceGyro.h
//  AriverDeviceCore
//
//  Created by ZQP on 2019/4/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^H5GyroResultCallback)(id data);

/*
 *
 * @param alpha 设备绕 z 轴旋转方向，值从 0 到 360，单位是 °。
 * @param beta  设备绕 x 轴旋转方向，值从 -180 到 180，单位是 °。
 * @param gamma 设备绕 y 轴旋转方向，值从 -90 到 90，单位是 °。
 * @param compassHeading    指南针与正北方向的偏差角度。
 * @param compassAccuracy   设备的精确度（一般为10）。
 *
 * @result 如果当前回调是否仍然有效，则返回 YES；否则返回 NO，会移除当前回调。
 */
typedef BOOL (^H5GyroCallbackCallback)(double alpha, double beta, double gamma);

@interface RVDeviceGyro : NSObject

- (void)watchGyroWithInterval:(CGFloat)interval
                     callback:(H5GyroResultCallback)callback;

- (void)clearWatchGyro;


@end

NS_ASSUME_NONNULL_END
