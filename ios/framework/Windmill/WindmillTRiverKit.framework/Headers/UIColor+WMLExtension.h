//
//  UIColor+WMLExtension.h
//  Windmill
//
//  Created by Jason Lee on 2018/5/7.
//

#import <UIKit/UIKit.h>

@interface UIColor (WMLExtension)

+ (UIColor*)wml_colorWithHex:(NSInteger)hexValue;
+ (UIColor *)wml_colorWithHex:(NSInteger)hexValue alpha:(CGFloat)alphaValue;

/// @brief UIColor转ARGB十进制
+ (NSInteger)wml_hexValueFromColor:(UIColor *)color;

/// @brief 处理形如'#RRGGBB'或'#AARRGGBB'的字符串格式
+ (UIColor *)wml_colorWithHexString:(NSString *)hexString;

/// @brief 处理形如'#RRGGBB'的字符串格式
+ (UIColor *)wml_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

/// @brief 处理形如'#AARRGGBB'的字符串格式
+ (CGFloat)wml_alphaWithHexString:(NSString *)hexString;

@end
