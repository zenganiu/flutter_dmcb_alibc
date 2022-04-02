//
// AppMonitorMeasure.h
// 
// UserTrack 
// 开发团队：数据通道团队 
// UT答疑群：11791581(钉钉) 
// UT埋点平台答疑群：11779226(钉钉) 
// 
// Copyright (c) 2014-2017 Taobao. All rights reserved. 
//

#import <Foundation/Foundation.h>
#import "AppMonitorMeasureValue.h"

/**
 * 监控指标项
 *
 */
@interface AppMonitorMeasure : NSObject<NSCoding>

@property (nonatomic, copy) NSString    *name;
@property (nonatomic, strong) NSNumber  *constantValue;
@property (nonatomic, strong) NSNumber  *min;
@property (nonatomic, strong) NSNumber  *max;
@property (nonatomic, copy) NSArray     *bounds;

- (instancetype)initWithName:(NSString *)name;

- (instancetype)initWithName:(NSString *)name constantValue:(NSNumber *)constantValue;

- (instancetype)initWithName:(NSString *)name constantValue:(NSNumber *)constantValue min:(NSNumber *)min max:(NSNumber *)max;

- (instancetype)initWithName:(NSString *)name constantValue:(NSNumber *)constantValue bounds:(NSArray *)bounds;

- (void)setRangeWithMin:(NSNumber *)min max:(NSNumber *)max;

- (BOOL)valid:(AppMonitorMeasureValue *)measureValue;
@end
