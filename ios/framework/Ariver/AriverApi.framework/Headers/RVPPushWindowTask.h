//
//  RVPPushWindowTask.h
//  AriverApi
//
//  Created by 张光宇 on 2019/4/24.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RVPPushWindowReq.h"
//NS_ASSUME_NONNULL_BEGIN
//NS_ASSUME_NONNULL_END
@class RVKScene;

@interface RVPPushWindowTask : NSObject

@property(nonatomic, strong) NSTimer                *timer;
@property(nonatomic, assign) double                 waitRender;
@property(nonatomic, assign) BOOL                   isFinished;
/**
 是否不需处理原有导航栈内容，只操作新VC
 */
@property(nonatomic, assign) BOOL                   isNormalPush;
@property(nonatomic, assign) BOOL                   transparent;
@property(nonatomic, strong) UIViewController    *currentVC;
@property(nonatomic, strong) RVKScene               *scene;
/**
 在VC切换操作时，导航栈中保留的VC数组(未包含新VC)
 */
@property(nonatomic, strong) NSMutableArray         *viewControllers;
@property(nonatomic, strong) UIWindow               *keyWindow;
@property(nonatomic, assign) RVPPushWindowAnimationType   animationType;

- (void)run;
@end
