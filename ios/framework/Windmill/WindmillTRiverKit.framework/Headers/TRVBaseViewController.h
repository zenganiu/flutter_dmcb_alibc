//
//  TRVBaseViewController.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/3.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TRVPageViewControllerProtocol.h"
#import "TRVWindowInfoModel.h"

#define TRVAppActionSheetMenuKey                  @"TRV_App_ActionSheetMenu"
#define TRVAppPageActionSheetMenuKey              @"TRV_App_Page_ActionSheetMenu"

#define TRVAppDrawerMenuListKey                   @"TRV_App_DrawerMenuList"

#define TRVAppCunstomFollowNotification               @"TRVAppCunstomFollowNotification"
#define TRVAppCunstomFollowActionKey                  @"TRVAppCunstomFollowActionKey"
#define TRVAppCunstomFollowActionEventNameKey         @"TRVAppCunstomFollowActionEventNameKey"
#define TRVAppCunstomFollowActionDataKey              @"TRVAppCunstomFollowActionDataKey"


@interface TRVBaseViewController : UIViewController <TRVPageViewControllerProtocol>

/**
 页面路径
 */
@property (nonatomic, copy) NSString *trv_pagePath;

/**
 页面参数
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *trv_pageQuery;

/**
 小程序全局参数
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *trv_globalQuery;
/**
 导航栏视图
 */
@property (nonatomic, strong) UIView<TRVHeaderViewProtocol> *trv_headerView;

/**
 页面视图
 */
@property (nonatomic, strong) UIView *trv_containerView;

/**
 菜单视图
*/
@property (nonatomic, strong) UIView *trv_menuView;

/**
 导航栏定制器
 */
@property (nonatomic, strong) id<TRVHeaderViewStandardAPIProtocol> headerViewImp;

/**
 导航栏UI数据模型
 */
@property (nonatomic, strong) TRVPageUIInfoModel *pageUIInfo;

/**
 如果是Tab，那么返回是不是TabBar上的第一个Tab上的首个页面；
 如果不是Tab，那么返回是不是首页
 */
@property (nonatomic, assign) BOOL isFirstViewController;

/**
 是否是TabBar上的页面
 */
@property (nonatomic, assign) BOOL isTabBarPage;

/**
 页面的tabBar
 */
@property (nonatomic, strong) UITabBar *trv_tabBar;

/**
 是否展示WebView设置的Title
 */
@property (nonatomic, assign) BOOL useWebViewTitleAsTitle;

/**
 当前页面的状态栏样式
 */
@property (nonatomic, assign) UIStatusBarStyle currentBarStyle;

/**
 页面Query
 */
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *query;

/**
 小程序开发者给小程序设置的框架分享参数，当前页面有效
 */
@property (nonatomic, strong) NSDictionary *trv_extShareInfo;
@property (nonatomic, strong) WMLAppCustomPageShareInfoModel *trv_customShareInfo;

/**
 添加定位观察事件
 */
- (id)addLoactionObserveWithHandler:(TRVObserveBlock)handler type:(TRVLocationObserveType)type;

/**
 移除定位观察事件
 */
- (void)removeLocationObserver:(id)observer;

/**
 更新页面渲染视图大小
 
 @param frame 新的大小
 */
- (void)trv_updateContainerViewFrame:(CGRect)frame;

/**
 获取小程序的RootVC
 */
- (UIViewController<TRVRootViewControllerProtocol> *)getAppRootViewController;

/**
 刷新页面
 */
- (void)trv_reloadPage;

/**
 刷新页面布局，此方法会在VC的viewWillLayoutSubviews 中被调用
*/
- (void)trv_relayoutPageView;

/**
 更新页面标题
 */
- (void)trv_updatePagetTitle:(NSString *)title;

/**
 反馈额外参数
 */
@property (nonatomic, strong) NSDictionary *feedBackInfo;

/**
 隐藏页面分享按钮
 */
@property (nonatomic, assign) BOOL hideShareMenu;

/**
 隐藏回到首页按钮
 */
@property (nonatomic, assign) BOOL hideBackHome;

/**
 是否是新版小程序容器
 */
@property (nonatomic, assign) BOOL isNewContainer;

/**
 是否是允许WindVane控制手淘导航，返回NO
*/
- (BOOL)allowsControlNavigationBar;

@end

