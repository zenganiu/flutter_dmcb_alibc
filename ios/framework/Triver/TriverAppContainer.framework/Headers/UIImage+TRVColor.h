//
//  UIImage+TRVColor.h
//  AppContainer
//
//  Created by AllenHan on 2019/5/2.
//  Copyright © 2019年 Taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (TRVColor)

/**
 生成1*1像素的纯色图片
 */
+ (UIImage *)trv_imageWithColor1x1:(UIColor *)color;

/**
 生成指定尺寸的纯色图片
 */
+ (UIImage *)trv_imageWithColor:(UIColor *)color size:(CGSize)size;

@end

