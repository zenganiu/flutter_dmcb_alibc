//
//  TRVUIProviderProtocol.h
//  AppContainer
//
//  Created by AllenHan on 2019/3/28.
//  Copyright © 2019年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TRVBaseViewController.h"
#import "TRVEnterInfoModel.h"

#pragma mark - 导航栏样式定制协议
@protocol TRVHeaderViewStandardAPIProtocol <NSObject>
@optional
- (BOOL)trv_setTitle:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_setSubtitle:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_show:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_hide:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_setLeftItem:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_setRightItem:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_setStyle:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_showLoading:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_hideLoading:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (CGFloat)trv_getHeight:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_resetIndexBadge:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_scaleIndexBadge:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_setTitleColor:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (NSNumber *)trv_getTitleColor:(NSDictionary *)param forPage:(TRVBaseViewController *)page;

- (void)trv_addMenu:(NSDictionary *)param forPage:(TRVBaseViewController *)page error:(NSError **)error;

// 新添加，暂时透传给接入方
- (void)trv_setBarBottomLineColor:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_showBackButton:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_hideBackHome:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_setBackButton:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_hideShareMenu:(NSDictionary *)param forPage:(TRVBaseViewController *)page;
- (void)trv_showBackToHomepage:(NSDictionary *)param forPage:(TRVBaseViewController *)page;

@end


#pragma mark - 导航栏协议
typedef void(^TRVRouterHandler)(NSString *urlStr, NSDictionary *params);
typedef void(^TRVEventHandler)(NSString *eventName, NSDictionary *data, BOOL isGlobal);
typedef void(^TRVShareCompletion)(BOOL success, NSDictionary *resultInfo);
typedef void(^TRVShareHandler)(TRVShareCompletion completion);
typedef void(^TRVAuthSettingHandler)(NSDictionary *extraInfo);
@protocol TRVHeaderViewProtocol <NSObject>
@required
// 返回前一页回调
@property (nonatomic, copy) TRVRouterHandler popPageAction;
// 关闭小程序回调
@property (nonatomic, copy) TRVRouterHandler closeAppAction;
// 打开小程序首页回调
@property (nonatomic, copy) TRVRouterHandler openIndexPageAction;

@optional
// 事件发送回调
@property (nonatomic, copy) TRVEventHandler eventHander;
// 跳转指定页面回调
@property (nonatomic, copy) TRVRouterHandler routerHandler;
// 分享回调
@property (nonatomic, copy) TRVShareHandler shareHandler;
// 更新回流入口的显示状态
- (void)trv_setIndexBadgeHidden:(BOOL)hidden;
// 设置导航栏透明度
- (void)trv_setTranslucentAlpha:(CGFloat)alpha;
// 设置导航栏是否透明
- (void)trv_setTranslucent:(BOOL)translucent;
@end


#pragma mark - Loading页协议
#define TRVLoadingFinishNotificationName @"TRVLoadingFinishNotificationName"
#define TRVLoadingExtraAppInfoKey @"appInfo"
@protocol TRVLoadingViewProtocol <NSObject>
@required
// 停止Loading并关闭小程序
@property (nonatomic, copy) TRVRouterHandler closeAction;
// 是否正在Loading
@property (nonatomic, assign) BOOL isLoading;
// 更新Loading页样式
- (void)trv_updateLoadingViewWithAppLogoUrl:(NSString *)appLogoUrl appName:(NSString *)appName extraParams:(NSDictionary *)extraParams;
@optional
// 更新Loading页样式
- (void)trv_updateLoadingViewWithAppLogoUrl:(NSString *)appLogoUrl appName:(NSString *)appName DEPRECATED_MSG_ATTRIBUTE("该方法即将被弃用，请使用：-trv_updateLoadingViewWithAppLogoUrl:appName:extraParams 替代");
- (void)trv_showLoadingViewInView:(UIView *)view animate:(BOOL)animate;
- (void)trv_dismissLoadingViewWithAnimate:(BOOL)animate;
@end

#pragma mark - 导航控制协议
@protocol TRVNavOperationProtocol <NSObject>
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (UIViewController *)popViewControllerAnimated:(BOOL)animated;
@end


#pragma mark - UI定制协议
@protocol TRVUIProviderProtocol <NSObject>
@optional
/**
 返回导航栏视图给SDK

 @param page 页面所在的ViewController
 */
- (UIView<TRVHeaderViewProtocol>*)trv_headerViewForPage:(TRVBaseViewController*)page;

/**
 返回页面的渲染区域大小
 
 @param page 页面所在的ViewController
 */
- (CGRect)trv_renderFrameForPage:(TRVBaseViewController*)page;

/**
 返回LoadingView给SDK

 @param closeAction 关闭Loading的回调
 */
- (UIView<TRVLoadingViewProtocol>*)trv_loadingViewForEnterInfo:(TRVEnterInfoModel*)enterInfo closeAction:(TRVRouterHandler)closeAction;

/**
 返回一个自定义的错误页面，该错误页面用于在Loading小程序时展示
 
 @param error 错误Error
 @param frame 错误页面Frame
 @param title 错误Title
 @param subTitle 错误SubTitle
 @param enterInfo 小程序进入信息
 @param rootVC 小程序根视图
 @param closeAction 关闭小程序回调
 @param reLaunchAction 重新加载小程序
 */
- (UIView *)trv_errorViewForLoadingWithError:(NSError *)error
                                       frame:(CGRect)frame
                                       title:(NSString *)title
                                    subTitle:(NSString *)subTitle
                                      rootVC:(UIViewController *)rootVC
                                   enterInfo:(TRVEnterInfoModel *)enterInfo
                                 closeAction:(void(^)(void))closeAction
                              reLaunchAction:(void(^)(void))reLaunchAction;

/**
 同上
 @param redirectAction 错误页重定向targetUrl页面
 */
- (UIView *)trv_errorViewForLoadingWithError:(NSError *)error
                                       frame:(CGRect)frame
                                       title:(NSString *)title
                                    subTitle:(NSString *)subTitle
                                      rootVC:(UIViewController *)rootVC
                                   enterInfo:(TRVEnterInfoModel *)enterInfo
                                 closeAction:(void(^)(void))closeAction
                              redirectAction:(void(^)(NSString *targetUrl))redirectAction;

- (UIView *)trv_errorViewForEmbed:(NSError *)error
                            frame:(CGRect)frame
                            title:(NSString *)title
                         subTitle:(NSString *)subTitle;
/**
 返回一个自定义的错误页面，该页面用于在小程序单个页面加载页面失败时展示
 
 @param error 错误Error
 @param frame 错误页面Frame
 @param title 错误Title
 @param subTitle 错误SubTitle
 @param vc 错误发生时的ViewController
 */
- (UIView *)trv_errorViewForPageWithError:(NSError *)error frame:(CGRect)frame title:(NSString *)title subTitle:(NSString *)subTitle inViewController:(TRVBaseViewController *)vc reLoadAction:(void(^)(void))reLoadAction;

/**
 页面状态栏样式

 @param page 页面所在的ViewController
 */
- (UIStatusBarStyle)trv_statusBarStyleForPage:(TRVBaseViewController*)page;

/**
设置小程序根ViewController所在的NavigationController的NavigatorBar隐藏状态。
inside接入方可以在改方法中，处理隐藏状态时，根VC的Frame

@param hidden 是否需要隐藏NavigatorBar
@param rootVC 小程序的根VC
*/
- (void)trv_setOuterNavBarHidden:(BOOL)hidden forRootVC:(UIViewController *)rootVC;

- (UIViewController<TRVNavOperationProtocol> *)customNavigationControllerForViewController:(UIViewController *)vc;

- (UIView *)customNavigationBarForViewController:(UIViewController *)vc;

- (void)customAddChildViewController:(UIViewController *)child parentViewController:(UIViewController *)parent;

- (void)customRemoveChildViewController:(UIViewController *)child parentViewController:(UIViewController *)parent;

/**
 小程序RootViewController所在的父ViewController，如果有
 
 @param appRootVC 小程序RootViewController
 */
- (UIViewController *)containerViewControllerForAppRootViewController:(UIViewController *)appRootVC;

/**
 展示Toast
 
 @param toast   内容
 @param options toast配置，目前支持设置位置和时长，配置Key参考宏定义
 @param view    所在的View
 */
- (void)trv_showToast:(NSString *)toast withOptions:(NSDictionary *)options onView:(UIView *)view;

/**
 是否显示关注按钮，默认YES
 */
- (BOOL)trv_showFollowButton;


@end


@protocol TRVActionSheetProtocol <NSObject>

/**
 获取ActionSheet显示的Item，包含默认项和开发者自定义项
 
 @param menuInfo 开发者自定义项
 @param vc 当前所在的ViewController
 @param appName appName
 @return 包含最终包含默认项和开发者自定义项的MenuInfo
 */
- (NSDictionary *)getActionSheetMenuItemWithCustomMenuInfo:(NSDictionary *)menuInfo inViewController:(TRVBaseViewController *)vc appName:(NSString *)appName;

@end


typedef NS_ENUM(NSInteger, TRVPullDownState) {
    TRVPullDownStateNone,
    TRVPullDownStateStart,
    TRVPullDownStateStop,
    TRVPullDownStateRefreshing
};
typedef NS_ENUM(NSInteger, TRVPullDownStyle) {
    TRVPullDownStyleLight,
    TRVPullDownStyleDark
};

@protocol TRVPullRefreshProtocol <NSObject>

@required
/**
 提供下拉刷新的主视图
 SDK会根据主视图的高度决定触发下拉刷新的距离
 
 @param style 下拉刷新颜色样式
 @param viewController 当前VC
 */
- (UIView *)trv_refreshViewWithColorStyle:(TRVPullDownStyle)style inViewController:(TRVBaseViewController *)viewController;

@optional
- (void)trv_pullDownRefresh:(UIView *)refreshView changeToState:(TRVPullDownState)state inViewController:(TRVBaseViewController *)viewController;;
- (void)trv_pullDownRefresh:(UIView *)refreshView changeToStyle:(TRVPullDownStyle)style inViewController:(TRVBaseViewController *)viewController;;
- (void)trv_pullDownRefresh:(UIView *)refreshView process:(CGFloat)process inViewController:(TRVBaseViewController *)viewController;;
- (void)trv_pullDownRefresh:(UIView *)refreshView didChangeToFrame:(CGRect)frame inViewController:(TRVBaseViewController *)viewController;

@end
