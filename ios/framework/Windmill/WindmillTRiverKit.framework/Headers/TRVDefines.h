//
//  TRVDefines.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/4.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <WindmillTRiverKit/TRVUtils.h>

// TabBar动画类型
typedef NS_ENUM(NSInteger, WMLAppTabBarAnimationType) {
    WMLAppTabBarAnimationTypeNone, // 无动画
    WMLAppTabBarAnimationTypeAlpha, // 渐隐渐现
    WMLAppTabBarAnimationTypeTranslate // 渐入渐出
};

// NavBar动画类型
typedef NS_ENUM(NSInteger, WMLAppNavBarAnimationType) {
    WMLAppNavBarAnimationTypeNone, // 无动画
    WMLAppNavBarAnimationTypeAlpha, // 渐隐渐现
    WMLAppNavBarAnimationTypeTranslate // 渐入渐出
};

// 关注按钮状态
typedef NS_ENUM(NSUInteger, WMLAppInfoViewFollowStyle) {
    WMLAppInfoViewFollowStyleUndefined,
    WMLAppInfoViewFollowStyleToFollow,
    WMLAppInfoViewFollowStyleFollowed,
};

// 首页名称
#define APP_CONTAINER_INDEX_PAGE_NAME @"windmill_container_index_page"

#define WML_SAFE_STR(arg)   ([arg isKindOfClass:[NSString class]] ? arg : nil)
#define WML_SAFE_ARR(arg)   ([arg isKindOfClass:[NSArray class]] ? arg : nil)
#define WML_SAFE_DIC(arg)   ([arg isKindOfClass:[NSDictionary class]] ? arg : nil)
#define WML_SAFE_NUM(arg)   ([arg isKindOfClass:[NSNumber class]] ? arg : nil)
#define WML_SAFE_IMG(arg)   ([arg isKindOfClass:[UIImage class]] ? arg : nil)
#define WML_SAFE_URL(arg)   ([arg isKindOfClass:[NSURL class]] ? arg : nil)
#define WML_SAFE_DATA(arg)  ([arg isKindOfClass:[NSData class]] ? arg : nil)
#define WML_SAFE_DATE(arg)  ([arg isKindOfClass:[NSDate class]] ? arg : nil)
#define WML_SAFE_URL(arg)   ([arg isKindOfClass:[NSURL class]] ? arg : nil)

#pragma mark - 设备相关
#define WML_IsIPhoneXR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)
#define WML_IsBangs() [TRVUtils trv_isIPhoneXSeries]
#define WML_TabBarHeight (WML_IsBangs() ? 83.f : 49.f)
#define WML_StatusBarHeight (WML_IsBangs() ? 44.f : 20.f)
#define WML_ScreenWidth [[UIScreen mainScreen] bounds].size.width
#define WML_ScreenHeight [[UIScreen mainScreen] bounds].size.height

#pragma mark - 错误码
#define ERROR_ICON_KEY      @"errorIcon"
#define ERROR_TITLE_KEY     @"errorTitle"
#define ERROR_SUBTITLE_KEY  @"errorSubTitle"
#define ERROR_CODE_KEY      @"errorCode"
#define ERROR_REASON_KEY    @"errorReason"
#define ERROR_BUTTON_URL    @"errorButtonUrl"
#define ERROR_BUTTON_TEXT   @"errorButtonText"

#define ERROR_REDIRECT_TITLE    @"errorRedirectTitle"
#define ERROR_REDIRECT_URL      @"errorRedirectUrl"

#pragma mark - 默认的AppLogo
static NSString * const WMLAppDefaultAppLogo = @"http://gw.alicdn.com/mt/TB1wrITdRUSMeJjSszcXXbnwVXa-144-144.png";

// 关于页面URL
#define APP_CONTAINER_ABOUT_PAGE_ADDRESS @"http://market.m.taobao.com/app/mtb/taobao-app-more/pages/about"
// 授权设置页URL
static NSString * const TRVAuthSettingPageUrl = @"trvNative://authorize/settings";

// 轻店铺导航栏默认颜色
#define DefaultNavBarColor4TinyCycle @"#999999"
// 轻应用导航栏默认颜色
#define DefaultNavBarColor4HugeCycle @"#FFFFFF"
