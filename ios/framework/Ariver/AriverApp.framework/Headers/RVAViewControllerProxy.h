//
//  RVAViewControllerLifecycleDispatcher.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVAOptions.h"
#import "RVANavigationTitleViewProtocol.h"
#import "RVAPVReporter.h"

@class RVAViewControllerStatus;

typedef void(^RVADelayCallback)();


@interface RVAViewControllerProxy : NSObject <RVKViewControllerProtocol, RVKExpandoProtocol>

// 通用属性
@property(nonatomic, readonly, strong) id<RVANavigationTitleViewProtocol>  navigationTitleView;
@property(nonatomic, readonly, strong) id<RVAOptionsProtocol>              options;
@property(nonatomic, readonly, copy) NSString                             *channelId;
@property(nonatomic, readonly, copy) NSString                             *customUserAgent;
@property(nonatomic, readonly, strong) RVAViewControllerStatus             *myFlags;
@property(nonatomic, strong) RVAPVReporter                       *pvReporter;

- (instancetype)initWithTarget:(UIViewController *)target;

- (void)back;

- (void)clearAndBack;

- (void)close;

- (void)popToViewController:(UIViewController *)vc animated:(BOOL)animated;

- (void)popToWindowOfIndex:(NSInteger)indexPopTo;

- (void)popViewControllerAnimated:(BOOL)animated;

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;

- (void)addDelayCallback:(RVADelayCallback)callback;

- (void)showCloseItemIfNeeded;

- (void)doShowCloseItemIfNeeded:(BOOL)needed;

/**
 *  重新设置整个options,业务谨慎使用
 *
 *  @date 2017-06-07
 *
 */
- (void)resetOptions:(id<RVAOptionsProtocol>)options;

/**
 设置MainTitle的事件

 @param mainTitle 
 @param subtitle 
 */
- (void)sendSetMainTitleEvent:(NSString *)mainTitle subtitle:(NSString *)subtitle;

/**
 重置返回状态
 
 */
- (void)resetBackStatus;

@end
