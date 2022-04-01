//
//  TRVAppRootViewController.h
//  Triver
//
//  Created by zhongweitao on 2019/4/8.
//

#import <UIKit/UIKit.h>
#import "TRVAppNavigationViewController.h"
#import <AriverResource/RVRApp.h>
#import "RVRAppEnterInfo+TRVExtension.h"
#import "TRVAppPageViewController.h"
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>

@class TRVAppContainer;
typedef NS_ENUM(NSInteger, TRVOuterNavBarHiddenStatus) {
    TRVOuterNavBarHiddenStatusShow,
    TRVOuterNavBarHiddenStatusHidden
};

typedef NS_ENUM(NSUInteger, TRVAppOpenAnimate) {
    TRVAppOpenAnimatePush = 0,
    TRVAppOpenAnimatePresent = 1
};

@interface TRVAppRootViewController : UIViewController <TRVRootViewControllerProtocol>

@property (nonatomic, strong) UIView<TRVLoadingViewProtocol> *loadingView;
@property (nonatomic, strong) UIView *errorView;

@property (nonatomic, strong) TRVAppNavigationViewController *appNavigationController;
@property (nonatomic, assign) TRVOuterNavBarHiddenStatus outerNavBarStatus;
@property (nonatomic, assign) TRVAppOpenAnimate openAnimate;
@property (nonatomic, assign, readonly) BOOL oriOuterNavPanGestureEnable;//存储外部导航返回手势原始状态
@property (nonatomic, assign) BOOL enableOuterNavPanGesture;//设置外部导航返回手势是否可用

@property (nonatomic, weak, readonly) TRVAppContainer *appContainer;
@property (nonatomic, assign) BOOL isInPageStack; // 用于表示当前小程序页面是否在页面栈里。

- (instancetype)initWithAppContainer:(TRVAppContainer *)appContainer;
- (instancetype)initWithEmbedAppContainer:(TRVAppContainer *)appContainer;

- (void)showFirstViewController:(id<RVKViewControllerProtocol>)firstPage;
- (void)setViewControllers:(NSArray<id<RVKViewControllerProtocol>> *)vcs animated:(BOOL)animated;

- (TRVBaseViewController *)getAppPageViewController;

- (void)appPause;

// @brief
@property (nonatomic, assign) BOOL isLoadFailed;
@property (nonatomic, assign) BOOL isAppReady;

- (void)showRelaunchLoadingView;
- (void)showLoadingView;
- (void)hideLoadingView;
- (void)updateLoadingViewForAppLogoUrl:(NSString *)appLogoUrl appName:(NSString *)appName;

- (void)showLoadingErrorViewWithError:(NSError *)error;

@end

