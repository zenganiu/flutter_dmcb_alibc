//
//  RVTJSCTiming.h
//  AriverRuntime
//
//  Created by theone on 2017/12/18.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVTJSCBridge;

NS_ASSUME_NONNULL_BEGIN

@interface RVTJSCTiming : NSObject

@property(nonatomic, assign) BOOL paused;
@property (nonatomic, copy) dispatch_block_t pauseCallback;
- (void)invalidate;
- (instancetype)initWithBridge:(RVTJSCBridge *)bridge;
- (void)didUpdateFrame;
- (void)createTimer:(nonnull NSNumber *)callbackID
		   duration:(NSTimeInterval)jsDuration
   jsSchedulingTime:(NSDate *)jsSchedulingTime
			repeats:(BOOL)repeats
          contextId:(NSString *)contextId;

- (void)deleteTimer:(nonnull NSNumber *)timerID
          contextId:(NSString *)contextId;

@end

NS_ASSUME_NONNULL_END
