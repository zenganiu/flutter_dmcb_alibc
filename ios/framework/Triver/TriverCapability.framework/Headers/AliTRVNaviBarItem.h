//
//  AliTRVNaviBarItem.h
//  AliWindmill
//
//  Created by AllenHan on 2019/4/4.
//  Copyright © 2019年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WMLAppPageNavBarConsts.h"
#import <WindmillTRiverKit/TRVBaseViewController.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>

@class AliTRVBaseNaviBar, AliTRVNaviBarItem, AliTRVNaviBarFavorItem;
typedef void(^AliTRVNaviBarItemCommonBlock)(AliTRVNaviBarItem *item);
typedef void(^AliTRVFavorStatusListener)(AliTRVNaviBarFavorItem *item);


@interface AliTRVNaviBarItem : UIView
/**
 当前item所处的naviBar, 通过pageVC的headerView获取而来
 */
@property (nonatomic, weak,   readonly) AliTRVBaseNaviBar *naviBar;

/**
 当前item初始化时传入的pageVC
 */
@property (nonatomic, weak,   readonly) TRVBaseViewController *pageVC;

/**
 当前item的colorStyle
 */
@property (nonatomic, assign, readonly) WMLAppPageNavBarColorStyle colorStyle;

/**
 初始化方法
 
 @param frame AliTRVNaviBarItem的frame
 @param pageVC 初始化AliTRVNaviBarItem对象将被添加到pageVC上
 @return 返回AliTRVNaviBarItem对象
 */
- (instancetype)initWithFrame:(CGRect)frame pageVC:(TRVBaseViewController *)pageVC;

/**
 更新当前item的colorStyle
 
 @param colorStyle 传入的colorStyle
 */
- (void)trv_updateColorStyle:(WMLAppPageNavBarColorStyle)colorStyle;


- (void)trv_setColorStyleChangedNotify:(AliTRVNaviBarItemCommonBlock)notifyBlk;

/**
 视图默认布局完成的时候调用，对象生命周期内只会调用一次；
 会在在layoutBlock调用之前调用。
 */
- (void)trv_viewDidLoad;

#pragma mark -

@property (nonatomic,   copy, readonly) AliTRVNaviBarItemCommonBlock layoutBlock;
/**
 设置布局block，方便临时修改item的子视图的布局；
 注意：item会强持有该block，使用者应避免循环引用
 
 @param layoutBlock 布局Block
 */
- (void)trv_setLayoutBlock:(AliTRVNaviBarItemCommonBlock)layoutBlock;

/**
 强制布局，如果trv_viewDidLoad之前没有被调用过，那么会触发trv_viewDidLoad
 */
- (void)trv_setNeedLayout;

#pragma mark -
- (UIImage *)imageWithPrefix:(NSString *)prefix;
@end


@interface AliTRVNaviBarButtonItem : AliTRVNaviBarItem

@property (nonatomic, strong, readonly) UIButton *barButton;

@property (nonatomic, copy) dispatch_block_t buttonAction;

/**
 设置返回按钮图片
 
 @param image 待设置的图片
 @param colorStyle 针对不同colorStyle可以设置不同的图片
 */
- (void)trv_setImage:(UIImage *)image forColorStyle:(WMLAppPageNavBarColorStyle)colorStyle;


/**
 支持设置返回标题，标题和图片只能有一个生效
 
 @param title 返回标题
 */
- (void)trv_setButtonTitle:(NSString *)title withFont:(UIFont *)font;


/**
 设置back title的颜色
 
 @param color 颜色
 @param colorStyle 针对不同的colorStyle可以设置不同的颜色
 */
- (void)trv_setButtonTitleColor:(UIColor *)color forColorStyle:(WMLAppPageNavBarColorStyle)colorStyle;

@end

//@interface AliTRVNaviBarCustomViewItem : AliTRVNaviBarItem
//
//@property (nonatomic, strong, readonly) UIView *customView;
//
//- (void)trv_addCustomView:(UIView *)customView;
//
//@end


@interface AliTRVNaviBarBackItem : AliTRVNaviBarButtonItem

/**
 关闭当前页面，返回到上一页面
 */
- (void)trv_closeMiniAppPage;

@end

//@interface AliTRVNaviBarBackHomeItem : AliTRVNaviBarButtonItem
//
//@end
///**
// 默认的返回按钮image
//*/
//- (UIImage *)trv_leftTopBackIconForColorStyle:(WMLAppPageNavBarColorStyle)colorStyle;
//
//@end

/**
 默认的Title实现，只实现了TitleLabel，不会响应icon、subtitle等设置
 */
@interface AliTRVNaviBarTitleItem : AliTRVNaviBarItem

/**
 更新app logo
 
 @param icon 如果不设置，默认取pageVC.appBundle.appInfo.appInfoDetail.appLogo
 */
- (void)trv_updateIcon:(NSString *)icon;

/**
 更新title
 
 @param title 如果不设置，默认取pageVC.appBundle.appInfo.appInfoDetail.appName
 */
- (void)trv_updateTitle:(NSString *)title;

/**
 设置title的image，有些小程序的title配置的是一张图片
 
 @param imageUrl 没有默认值，目前只有轻应用有
 */
- (void)trv_updateTitleWithImageUrl:(NSString *)imageUrl;

/**
 设置title的image，有些小程序的title配置的是一张图片
 
 @param imageData 没有默认值，目前只有轻应用有
 */
- (void)trv_updateTitleWithImageData:(NSData *)imageData;

/**
 设置subtitle，可以不实现
 
 @param title 无默认值，前端可以通过api设置
 */
- (void)trv_updateSubtitle:(NSString *)title;

/**
 设置subtitle的tag，根据UI设计实现，也可以不实现
 @param logo 如果不设置，默认取pageVC.windowInfo.navigationBarTag
 */
- (void)trv_updateTagLogo:(NSString *)logo;

@end

