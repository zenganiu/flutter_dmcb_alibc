//
//  UIColor+Alibc.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/8/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Alibc)

+ (UIColor*)alibc_colorWithHex:(NSInteger)hexValue;
+ (UIColor *)alibc_colorWithHex:(NSInteger)hexValue alpha:(CGFloat)alphaValue;

/// @brief UIColor转ARGB十进制
+ (NSInteger)alibc_hexValueFromColor:(UIColor *)color;

/// @brief 处理形如'#RRGGBB'或'#AARRGGBB'的字符串格式
+ (UIColor *)alibc_colorWithHexString:(NSString *)hexString;

/// @brief 处理形如'#RRGGBB'的字符串格式
+ (UIColor *)alibc_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

/// @brief 处理形如'#AARRGGBB'的字符串格式
+ (CGFloat)alibc_alphaWithHexString:(NSString *)hexString;

@end

NS_ASSUME_NONNULL_END
