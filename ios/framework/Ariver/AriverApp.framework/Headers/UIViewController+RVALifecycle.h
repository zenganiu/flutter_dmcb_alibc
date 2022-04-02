//
//  UIViewController+RVALifecycle.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UINavigationController+RVALifecycle.h"

@class RVAViewControllerProxy;
@class RVKScene;
@protocol RVKViewControllerProtocol;

@interface UIViewController (RVALifecycle) <RVKViewControllerProtocol,RVAUINavigationControllerProtocol>

/**
 *  @brief 得到proxy
 *
 *  @date 2015-12-14
 *
 *  @return 返回proxy
 */
- (RVAViewControllerProxy *)viewControllerProxy;

/**
 *  @brief Nebula的VC被创建
 *
 *  @date 2016-01-08
 *
 *  @return 无
 */
- (void)nbViewControllerInit;

/**
 *  @brief 自定义UA的后缀
 *
 *  @date 2016-01-08
 *
 *  @return 返回自定义的UA后缀
 */
- (NSString *)nbUserAgentSuffix;

/**
 *  @brief Nebula的View被加载，通常这里是您的初始化界面时机
 *
 *  @date 2015-12-14
 *
 *  @return 无
 */
- (void)nbViewDidLoad;

- (UINavigationController *)rva_navigationController;
- (UIView *)rva_navigationBar;

@end

