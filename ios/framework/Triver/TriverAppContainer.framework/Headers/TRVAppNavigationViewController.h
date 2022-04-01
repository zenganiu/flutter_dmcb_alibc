//
//  TRVAppNavigationViewController.h
//  Triver
//
//  Created by zhongweitao on 2019/4/8.
//

#import <UIKit/UIKit.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>

@class TRVAppContainer;
@interface TRVAppNavigationViewController : UINavigationController


@property (nonatomic, weak) TRVAppContainer *appContainer;

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController appContainer:(TRVAppContainer *)appContainer;

/**
 设置自定义事件手势是否生效
 */
- (void)setCustomPanGestureEnable:(BOOL)enable;

@end
