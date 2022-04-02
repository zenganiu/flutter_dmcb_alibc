//
//  TRVAppRootViewController+Outer.h
//  Triver
//
//  Created by zhongweitao on 2019/4/8.
//

#import "TRVAppRootViewController.h"

@interface UIViewController (TRVNavigation)

- (UINavigationController *)trv_navigationController;

- (UIView *)trv_getNavBar;

- (void)trv_setNavBarHidden:(BOOL)hidden;

- (BOOL)trv_isPresented;

@end
