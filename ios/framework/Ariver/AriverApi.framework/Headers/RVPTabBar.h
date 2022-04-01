//
//  RVPTabBar.h
//  NebulaBiz
//
//  Created by lyusheng on 2018/11/26.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPTabBar : UITabBar
@property (nonatomic,copy) void(^tabbarShouldSelectItem)(RVPTabBar *tabBar,NSInteger idx, UITabBarItem *item);
@property (nonatomic, assign)BOOL needResetPosition;
@end

NS_ASSUME_NONNULL_END
