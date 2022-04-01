//
//  TRVAppPageViewController.h
//  Triver
//
//  Created by zhongweitao on 2019/4/8.
//

#import <UIKit/UIKit.h>
#import "TRVBodyContainerView.h"
#import <AriverKernel/RVKViewControllerProtocol.h>
#import <WindmillTRiverKit/TRVBaseViewController.h>
#import <AriverResource/RVRApp.h>
#import <WindMix/WMixProxyProtocol.h>

#define kTRVAppPause             @"appPause"
#define kTRVAppResume            @"appResume"

typedef NS_ENUM(NSUInteger, TRVAppOpenType) {
    TRVAppOpenTypeNormal = 0, // 用小程序自身导航栈打开
    TRVAppOpenTypeEmbed = 1   // 用外部导航栈打开
};


@interface TRVAppPageViewController : TRVBaseViewController<RVKViewControllerProtocol>

@property (nonatomic, assign) BOOL forbidRvkLifeCycle;
@property (nonatomic, assign) BOOL showIndexPage;//是否是直接打开的二级页
@property (nonatomic, assign) BOOL pullDownRefresh;
@property (nonatomic, assign) double scrollDistance;
@property (nonatomic, copy) NSString *currentTransparentTitle;

@property (nonatomic, assign) UIEdgeInsets edgeInsets;

@property (nonatomic, assign) TRVAppOpenType appOpenType;
@property (nonatomic, assign) BOOL isSubViewMode;
@property (nonatomic, assign) BOOL embedInWeex;
@property (nonatomic, strong) TRVBodyContainerView *bodyContainerView;
@property (nonatomic, weak) id<WMixPageViewControllerLifeCycleDelegate> delegate;
@property (nonatomic, assign) BOOL disableSwipeBack;//是否禁止当前页面的右滑返回

/// @brief 启动创建页面后更新showIndexPage
- (BOOL)updateShowIndexPage;

/// @brief 构建导航栏信息
- (void)conctructTitleViewInfo;

/// @brief 构建页面UI配置信息
- (TRVPageUIInfoModel *)constructPageUIInfo;

/// @brief 页面配置
- (NSDictionary *)currentPageConfig;

/// @brief 构建分享信息
- (void)constructShareInfo;

/// @brief 打开授权设置页
- (void)openAuthSettingForApp:(RVRApp *)app;

/// @brief 添加导航栏
- (void)setupHeaderView;

/// @brief 设置导航栏能力
- (void)setupHeaderViewAction;

- (void)adjustWebviewContentInsets;

/// @brief 设置页面是否能够下拉
- (void)setPageCanPullDown:(BOOL)canPullDown;

/// @brief 当前的小程序信息
- (RVRApp *)currentApp;

/// @brief 关闭页面，内部会处理关闭小程序情况
- (void)closeCurrentAppPage:(NSString *)appId;

/// @brief 打开URL
- (void)openUrl:(NSString *)urlStr params:(NSDictionary *)params;
- (void)addMixComponents:(id)component;
- (void)removeMixComponents:(id)component;

@end
