//
//  RVDeviceCompass.h
//  AriverDeviceCore
//
//  Created by ZQP on 2019/4/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RVDeviceCompassCallback)(id data);

@interface RVDeviceCompass : NSObject

- (void)watchHeadingWithInterval:(CGFloat)interval callback:(RVDeviceCompassCallback)callback;

- (void)clear;

@end

NS_ASSUME_NONNULL_END
