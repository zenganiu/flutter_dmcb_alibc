//
//  TRVBodyContainerView.h
//  AppContainer
//
//  Created by AllenHan on 2019/7/10.
//  Copyright © 2019年 Taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WindmillTRiverKit/WMLAppPageContainerScrollView.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class TRVAppPageViewController;
@interface TRVBodyContainerView : UIView

@property (nonatomic, strong) WMLAppPageContainerScrollView *containerScrollView;
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, weak) TRVAppPageViewController *pageVC;


- (instancetype)initWithFrame:(CGRect)frame pageVC:(TRVAppPageViewController *)pageVC;

- (void)addPageView:(UIView *)view;
- (void)updateRenderViewFrame:(CGRect)frame;

#pragma mark - 下拉刷新组件
// 是否能够下拉刷新
@property (nonatomic, assign) BOOL canPullRefresh;
// 当前下拉状态
@property (nonatomic, assign, readonly) TRVPullDownState pullDownState;
// 设置Loading样式
- (void)setupLoadingColorStyle:(NSString *)style;
// 触发页面的Loading动画
- (void)startPullDownRefresh;
// 停止页面的Loading动画
- (void)stopPullDownRefresh;
// 更新下拉状态
- (void)changePullDownRefreshState:(TRVPullDownState)state;
// 更新下拉进度
- (void)updatePullDownProcess:(CGFloat)process;
// 获取LoadingView的高度
- (CGFloat)loadingViewHeight;

@end

NS_ASSUME_NONNULL_END
