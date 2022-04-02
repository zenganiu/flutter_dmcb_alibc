//
//  WMLAppPageNavBarConsts.h
//  AppContainer
//
//  Created by Jason Lee on 2018/4/16.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindmillTRiverKit/TRVDefines.h>

#ifndef WMLAppPageNavBarConsts_h
#define WMLAppPageNavBarConsts_h

typedef NS_ENUM(NSUInteger, WMLAppPageNavBarColorStyle) {
    WMLAppPageNavBarColorStyleLight,
    WMLAppPageNavBarColorStyleDark,
};

typedef void(^WMLAppPageClickAction)(id sender, NSDictionary *info);

typedef void(^WMLAppPageNavBarBackAction)(void);
typedef void(^WMLAppPageNavBarMoreAction)(void);
typedef void(^WMLAppPageNavBarRightItemAction)(void);

#define kPageNavBarHeight                   44.0f
#define kBackBtnMarginLeft                  4.0f
#define kBackBtnMarginBottom                7.0f
#define kMaxTitleLabelLength                110.f
#define kTitleMarginBottom                  12.5f
#define kFavorMarginTitle                   5.0f
#define kRightItemMarginMore                10.5f
#define KRightMoreBtnMarginRight            2.0f
#define kGuideViewRightMarginFavorRight     55.0f
#define kGuideViewWidth                     210.0f
#define kGuideViewHeight                    36.0f
#define kIndexViewMarginLeftBtn             15.0f
#define kIndexViewMarginBottom              7.5f

#define kWMLHeaderViewColorStyleKey         @"WML_AppPage_HeaderView_ColorStyle"

#endif /* WMLAppPageNavBarConsts_h */
