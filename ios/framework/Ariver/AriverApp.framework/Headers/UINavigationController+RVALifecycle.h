//
//  UINavigationController+RVALifecycle.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol RVAUINavigationControllerProtocol <NSObject>
- (void)rva_willShowViewController:(UIViewController *)viewController;

- (void)rva_didShowViewController:(UIViewController *)viewController;

- (void)rva_setViewControllers:(NSArray<UIViewController *> *)viewControllers animated:(BOOL)animated;

- (void)rva_setViewControllers:(NSArray<UIViewController *> *)viewControllers;

- (void)rva_popToViewController:(UIViewController *)viewController animated:(BOOL)animated;

- (void)rva_popViewControllerAnimated:(BOOL)animated;

- (void)rva_popToRootViewControllerAnimated:(BOOL)animated;
@end

@interface UINavigationController (RVALifecycle)<RVAUINavigationControllerProtocol>

@end
