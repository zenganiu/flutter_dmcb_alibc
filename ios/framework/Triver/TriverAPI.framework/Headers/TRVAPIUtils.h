//
//  TRVAPIUtils.h
//  Triver
//
//  Created by lanyao on 2019/4/11.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TRVAPIUtils : NSObject

UIColor *TRVColorWithHex(NSInteger hex); // 0xAARRGGBB、0xRRGGBB

UIColor *TRVColorWithWebString(NSString *colorString); // #aarrggbb 、 #rrggbb 、 rgb(rr,gg,bb) 、 argb(aa,rr,gg,bb)

UIColor *TRVColorWithHexString(NSString *colorString);

// 截图
UIImage *H5SnapShot(CGSize size, UIView *view, BOOL isWK);

UIImage *H5ReSizeImage(UIImage *image, CGSize reSize);

// 获取当前显示的 viewController
+ (UIViewController *)getTopMostViewController;

// 获取当前的 window
+ (UIWindow *)currentWindow;

// 获取 safeArea 的缩进
+ (UIEdgeInsets)getWindowSafeAreaInsets;

// 获取当前系统版本号
+ (CGFloat)getSystemVersion;

/**
 绘制一个某种颜色的图片
 @param color 图片颜色
 @param size 图片大小
 @return 图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 对 NSData 类型的数据进行 sha1 编码
 */
+ (NSString *)sha1StringFromData:(NSData *)data;

/**
 对 NSData 类型的数据进行 md5 编码
 */
+ (NSString *)md5StringFromData:(NSData *)data;

/**
 对字符串进行 md5 编码
 */
+ (NSString *)md5StringFromString:(NSString *)originString;

@end

NS_ASSUME_NONNULL_END
