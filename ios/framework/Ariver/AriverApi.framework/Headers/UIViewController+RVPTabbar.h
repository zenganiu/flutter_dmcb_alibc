//
//  UIViewController+RVPTabbar.h
//  AriverApi
//
//  Created by hua.lu on 2019/5/30.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class RVPTabBarManager;
@interface UIViewController (RVPTabbar)

@property (nonatomic, strong) RVPTabBarManager *rvpTabBarManager;

@end

NS_ASSUME_NONNULL_END
