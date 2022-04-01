//
//  AliTRVBaseNaviBar.h
//  AliWindmill
//
//  Created by AllenHan on 2019/4/4.
//  Copyright © 2019年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AliTRVNaviBarItem.h"
#import "WMLAppPageNavBarConsts.h"
#import <WindmillTRiverKit/TRVBaseViewController.h>

@class AliTRVBaseNaviBar;
typedef void(^AliTRVNaviBarCommonBlock)(AliTRVBaseNaviBar *naviBar);
typedef CGRect(^AliTRVNaviBarOccupyRectCalcBlock)(AliTRVBaseNaviBar *naviBar);



@interface AliTRVBaseNaviBar : UIView<TRVHeaderViewProtocol>

/// @brief 是否允许手淘自动翻转DarkMode下的颜色，仅在手淘下生效
@property (nonatomic, strong) NSNumber *tbDarkMode_needAutoColorInvert;

@property (nonatomic, strong) UIImageView *bgImageView;

/**
 初始化时传入的pageVC
 */
@property (nonatomic, weak, readonly) TRVBaseViewController *pageVC;

/**
 默认初始化方法
 
 @param frame 导航栏大小
 @param pageVC 为pageVC初始化导航栏
 @return 返回初始化的导航栏视图对象
 */
- (instancetype)initWithFrame:(CGRect)frame pageVC:(TRVBaseViewController *)pageVC;

/**
 导航栏是否透明，会影响导航栏占用的渲染区域和导航栏可点击区域
 注意：transulent为YES时，无法设置背景色和背景图片；
 */
@property (nonatomic, assign) BOOL transulent;

/**
 是否忽略背景色/背景图设置
 */
@property (nonatomic, assign) BOOL ignoreBackgroundSet;

#pragma mark - UI生命周期

/**
 类似UIViewController的viewDidLoad
 */
- (void)trv_viewDidLoad;

/**
 当前视图渲染完成后的回调，有些导航栏会对渲染完成后的视图做一些操作（譬如轻店铺的圆角等）。
 Inside接入方可以通过覆写此方法，实现对渲染完成视图的一些操作
 
 @param bodyView 渲染完成后的视图
 */
- (void)trv_pageDidRenderContainerView:(UIView *)bodyView;

#pragma mark - 布局方法

/**
 返回占用render区域的大小，WMLUIProviderProtocol协议中"-renderFrameForPage:inApp:"方法实现，可以通过这个函数计算导航栏占用渲染区域的大小
 @return 返回导航栏占用渲染区域的大小。当transulent为YES时，默认返回CGRectZero；transulent为NO时，默认返回self.bounds；继承此类者可以自定义返回占用渲染区域大小。
 */
- (CGRect)trv_occupyRenderRect;

/**
 设置计算占用渲染区域大小的block
 
 @param block 计算大小的block
 */
- (void)trv_setOccupyRenderRectCalcBlock:(AliTRVNaviBarOccupyRectCalcBlock)block;

/**
 内部会强持有此block，在合适的时机调用，注意循环引用问题
 
 @param layoutBlock 布局block
 */
- (void)trv_setLayoutBlock:(AliTRVNaviBarCommonBlock)layoutBlock;

/**
 立即触发layoutBlock的调用
 */
- (void)trv_setNeedLayout;
#pragma mark - Color Style
/**
 更新ColorStyle
 */
@property (nonatomic, assign, readonly) WMLAppPageNavBarColorStyle colorStyle;

#pragma mark - 背景
/**
 当前设置的导航栏背景色
 */
@property (nonatomic, strong) UIColor *currNavBarBgColor;

/**
 当前背景alpha，默认1。仅当transparentTitle=auto时，滚动会改变该值
 */
@property (nonatomic, assign, readonly) CGFloat currentAlpha;

/**
 更新当前背景alpha
*/
- (void)trv_updateCurrentAlpha:(CGFloat)alpha;

/**
 内部会强持有此block，在合适的时机调用，注意循环引用问题
 
 @param notifyBlk colorStyle更新时调用的block
 */
- (void)trv_setColorStyleChangedNotify:(AliTRVNaviBarCommonBlock)notifyBlk;
/**
 更新colorStyle
 
 @param colorStyle 待设置的colorStyle
 */
- (void)trv_updateColorStyle:(WMLAppPageNavBarColorStyle)colorStyle;


#pragma mark - 导航栏Item添加方法

/**
 获取导航栏视图上的所有的items
 */
@property (nonatomic, copy, readonly) NSArray <AliTRVNaviBarItem *>*allItems;

/**
 添加item
 
 @param item 待添加的导航栏item
 */
- (void)trv_addItem:(AliTRVNaviBarItem *)item;

/**
 添加items(item数组)
 
 @param items 待添加的导航栏items
 */
- (void)trv_addItems:(NSArray<AliTRVNaviBarItem *>*)items;

/**
 获取对应类名的item，为了方便对已有的轻店铺和轻应用导航栏item进行继承定制。
 所以内部使用isKindOfClass:获取对应item
 
 @param cls item的类名
 @return 返回找到的item
 */
- (AliTRVNaviBarItem *)trv_firstItemOfClass:(Class)cls;

/**
 获取对应类名的items，当同一种类添加的item多于一个时，可以通过此方法获取
 
 @param cls item对应的class
 @return 返回AliWMLNaviBarItem对象数组
 */
- (NSArray <AliTRVNaviBarItem *>*)trv_itemsOfClass:(Class)cls;

/**
 移除item
 
 @param item 待移除的item
 */
- (void)trv_removeItem:(AliTRVNaviBarItem *)item;
/**
 移除所有的item
 */
- (void)trv_removeAllItems;


#pragma mark - 导航栏背景设置方法

/**
 设置导航栏背景图片（如果设置不生效，注意transulent的值是否为YES）
 
 @param imageUrl 背景图片的url
 */
- (void)trv_setBackgroundImageWithUrl:(NSString *)imageUrl;

/**
 设置导航栏背景色（如果设置不生效，注意transulent的值是否为YES）
 
 @param colorStr 背景颜色（十六进制字符串，类似"#ffffff"）
 */
- (void)trv_setBackgroundColorWithHexString:(NSString *)colorStr;


//增加事件透传Orange配置，导航栏透明默认透传，不透明不透传
- (BOOL)getOrangePointInsideConfig;

@end

