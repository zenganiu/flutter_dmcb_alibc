//
//  TRVDarkModeManager.h
//  TRiverKit
//
//  Created by AllenHan on 2019/11/29.
//  Copyright © 2019 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TRVColorSchemeType) {
    TRVColorSchemeTypeLight,
    TRVColorSchemeTypeDark
};


extern NSString *const TRVColorSchemeChangeNotification;

@interface TRVDarkModeManager : NSObject

/// @brief 是否开启DarkMode，默认YES
@property (nonatomic, assign) BOOL enableDarkMode;

+ (instancetype)sharedManager;

/// @brief 当前设备是否是DarkMode
- (BOOL)isDarkMode;

/// @brief 获取原始颜色对应的DarkMode颜色，如果当前未开启DarkMode，则返回defaultColor
- (UIColor *)darkModeColorWithDefaultColor:(UIColor *)defaultColor;

///// @brief 宿主App上外观样式改变通知，需要调用此API
- (void)updateCurrentColorScheme:(TRVColorSchemeType)colorScheme;

@end

NS_ASSUME_NONNULL_END
