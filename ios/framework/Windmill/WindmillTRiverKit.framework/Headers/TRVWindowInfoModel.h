//
//  TRVWindowInfoModel.h
//  AppContainer
//
//  Created by AllenHan on 2019/3/28.
//  Copyright © 2019年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVThreadSafeMutableDictionary.h"

typedef enum : NSUInteger {
    TRVNavigationStyleUnknown,
    TRVNavigationStyleDefault,
    TRVNavigationStyleCustom,
    TRVNavigationStyleCount
} TRVNavigationStyleType;


@interface TRVWindowInfoModel : NSObject

@property (nonatomic, copy) NSString *defaultTitle;
@property (nonatomic, copy) NSString *titleBarColor;
@property (nonatomic, copy) NSString *navigationStyle; // "default" or "custom"
@property (nonatomic, copy) NSString *navigationBarBackgroundColor; //导航栏背景色
@property (nonatomic, copy) NSString *navigationBarBackgroundBg; //导航栏背景图片
@property (nonatomic, copy) NSString *navigationBarLogo; //导航栏Logo
@property (nonatomic, copy) NSString *navigationBarTag; //导航栏Tag 图片地址
@property (nonatomic, copy) NSString *navigationBarTitleText; //导航栏文字标题
@property (nonatomic, copy) NSString *navigationBarTitleBg; //导航栏图片标题
@property (nonatomic, copy) NSString *navigationBarTextStyle; //导航栏标题颜色，仅支持black/white
@property (nonatomic, copy) NSString *backgroundTextStyle;//Loading颜色样式
@property (nonatomic, assign) BOOL translucent; //是否导航栏透明
@property (nonatomic, copy) NSString *transparentTitle;
@property (nonatomic, assign) BOOL showNavigationBar; //是否展示导航栏
@property (nonatomic, assign) BOOL navigationBarForceEnable; //展示轻店铺次级页面的导航栏
@property (nonatomic, assign) BOOL showNavigationBarTitle;
@property (nonatomic, assign) BOOL showNavigationBarLogo;
@property (nonatomic, assign) BOOL isDirectToSecondPage;
@property (nonatomic, assign) BOOL isShowAboutItem; //导航栏菜单是否显示“关于”入口
@property (nonatomic, assign) BOOL isShowAuthSettingItem; //导航栏菜单是否显示“授权设置”入口

@property (nonatomic, strong) TRVThreadSafeMutableDictionary *extraInfo; // 可扩展的配置项，如页面菜单项、页面信息等，考虑到外部使用的线程安全性，会在对象初始化时同步初始化


- (instancetype)initWithDictionary:(NSDictionary *)dict isShoppingTool:(BOOL)isShoppingTool;
- (instancetype)initForShoppingTool:(BOOL)isShoppingTool;
- (TRVNavigationStyleType)navigationStyleType;

@end


@interface TRVTabBarInfoModel : NSObject

@property(nonatomic, copy) NSString *backgroundColor;

@end
