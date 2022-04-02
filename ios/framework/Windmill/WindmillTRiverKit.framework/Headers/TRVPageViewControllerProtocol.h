//
//  TRVPageViewControllerProtocol.h
//  AppContainer
//
//  Created by AllenHan on 2019/3/28.
//  Copyright © 2019年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TRVPageUIInfoModel.h"
#import "WMLAppCustomPageShareInfoModel.h"
#import "TRVAppContainerProtocol.h"


typedef void(^TRVObserveBlock)(NSString *name, NSDictionary *userInfo);
typedef id(^TRVAddObserveHandler)(NSString *name, TRVObserveBlock block);
typedef void(^TRVRemoveObserveHandler)(id obj);

typedef NS_ENUM(NSInteger, TRVLocationObserveType) {
    TRVLocationObserveTypeStart,
    TRVLocationObserveTypeStop
};

@protocol TRVLoadingViewControllerProtocol <NSObject>
@end


@protocol TRVLoadingViewProtocol;
@protocol TRVRootViewControllerProtocol <NSObject>

@required
/**
 小程序全局属性,可扩展的配置项，如应用全局菜单项
 */
@property (nonatomic, strong) TRVThreadSafeMutableDictionary *trv_extraInfo;

/**
 小程序开发者给小程序设置的框架分享参数，所有页面都有效
 */
@property (nonatomic, strong) NSDictionary *trv_extShareInfo;
@property (nonatomic, strong) WMLAppCustomPageShareInfoModel *trv_customShareInfo;

@optional
/// @brief tbMenu
@property (nonatomic, strong) NSArray *replaceMenuItems;
/// @brief default tbMenuItems
@property (nonatomic, strong) NSArray *defualtMenuItems;
/// @brief LoadingView
@property (nonatomic, strong) UIView<TRVLoadingViewProtocol> *loadingView;
/// @brief 更新当前状态栏样式
- (void)trv_updateCurrentStatusBarStyle:(UIStatusBarStyle)style;

@end


@protocol TRVHeaderViewProtocol;
@protocol TRVHeaderViewStandardAPIProtocol;
@protocol TRVPageViewControllerProtocol <NSObject>
@required

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
 导航视图所需要的数据结构
 */
@property (nonatomic, strong) TRVPageUIInfoModel *pageUIInfo;

/**
 导航视图
 */
@property (nonatomic, strong) UIView<TRVHeaderViewProtocol> *trv_headerView;

/**
 页面视图
 */
@property (nonatomic, strong) UIView *trv_containerView;

/**
 导航视图定制器
 */
@property (nonatomic, strong) id<TRVHeaderViewStandardAPIProtocol> headerViewImp;

/**
 TabBar，二级页没有TabBar
 */
@property (nonatomic, strong) UITabBar *trv_tabBar;

/**
 是否是TabBar上的页面
 */
@property (nonatomic, assign) BOOL isTabBarPage;

/**
 是否是小程序首页
 */
@property (nonatomic, assign) BOOL isFirstViewController;

/**
 是否使用页面webview的title作为页面Title
 */
@property (nonatomic, assign) BOOL useWebViewTitleAsTitle;

/**
 小程序开发者给小程序设置的框架分享参数，当前页面有效
 */
@property (nonatomic, strong) NSDictionary *trv_extShareInfo;
@property (nonatomic, strong) WMLAppCustomPageShareInfoModel *trv_customShareInfo;

/**
 获取小程序的RootVC
 */
- (UIViewController<TRVRootViewControllerProtocol> *)getAppRootViewController;


/**
 获取小程序实例
 */
- (id<TRVAppContainerProtocol>)getAppContainer;

@optional

/**
 * 刷新当前页面
 */
- (void)reload;

/**
 添加定位观察事件

 @param handler 事件处理器
 @param type 类型：开始 or 结束
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
 获取当前页面的分享URL，兼容逻辑。原Windmill页面容器需实现该方法。分享组件默认用新SDK的模式

 @param customPath 开发者自定义的页面路径
 */
- (NSString *)trv_getShareUrlWithCustomPath:(NSString *)customPath;

@end
