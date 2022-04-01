//
//  WMLActionSheetCommon.h
//  JDYUIControls
//
//  Created by 连墨 on 2018/4/11.
//  Copyright © 2018年 连墨. All rights reserved.
//

#ifndef WMLActionSheetCommon_h
#define WMLActionSheetCommon_h

#define WMLAS_HEXCOLOR(hexValue)              [UIColor colorWithRed : ((CGFloat)((hexValue & 0xFF0000) >> 16)) / 255.0 green : ((CGFloat)((hexValue & 0xFF00) >> 8)) / 255.0 blue : ((CGFloat)(hexValue & 0xFF)) / 255.0 alpha : 1.0]

#ifndef WMLAS_rgba
#define WMLAS_rgba(r, g, b, a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#endif

#ifndef WMLAS_rgb
#define WMLAS_rgb(r, g, b) WMLAS_rgba(r, g, b, 1.0f)
#endif

#ifndef WMLAS_iPad
#define WMLAS_iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#endif

#define IS_IPHONE_X() ([UIScreen mainScreen].bounds.size.height == 812 && [UIScreen mainScreen].bounds.size.width == 375)
#define StatusBarHeight() (IS_IPHONE_X()?44:20)
#define SafeAreaInsets()  (IS_IPHONE_X()?UIEdgeInsetsMake(88, 0, 34, 0):UIEdgeInsetsZero)
#define WMLAS_kHostsCornerRadius 12.0f
#define WMLAS_kHostsCornerRadiusForContentView 12.0f
#define WMLAS_kSpacing 6.0f
#define WMLAS_kSpacingBetweenButtonsInSectionV 1.0f
#define WMLAS_kSpacingBetweenButtonsInSectionH 0.0f
#define WMLAS_kButtonHeight 53.0f
#define WMLAS_kDestructiveButtonHeight 45.0f
#define WMLAS_kTitleHeightForContentView 56.5f
#define WMLAS_kShadowRadius 0.0f
#define WMLAS_kShadowOpacity 0.2f
#define WMLAS_kFixedWidth 320.0f
#define WMLAS_kFixedWidthContinuous 300.0f
#define WMLAS_kButtonTitleLeftInset 62
#define WMLAS_kButtonTitleSepLeftInset 62
#define WMLAS_kContentViewTitleLeftInset 19
#define WMLAS_kNormalSectionTitleLeftInset 19
#define WMLAS_kButtonIconSideLen 28
#define WMLAS_kButtonIconLeftPadding 17
#define WMLAS_kConentEntryCellWidth 48
#define WMLAS_kAnimationDurationForSectionCount(count) MAX(0.22f, MIN(count*0.12f, 0.45f))

#endif /* WMLActionSheetCommon_h */
