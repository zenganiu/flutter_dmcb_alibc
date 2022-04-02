//
//  NSTimer+TRVUtilities.h
//  API
//
//  Created by lanyao on 2019/4/8.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSTimer (TRVUtilities)

/**
 创建定时器
 
 @param interval 定时器时间周期
 @param block 定时器触发时的事件
 @param repeats 定时器是否循环计时
 */
+ (NSTimer *)trvScheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                         block:(void(^)(void))block
                                       repeats:(BOOL)repeats;
@end

NS_ASSUME_NONNULL_END
