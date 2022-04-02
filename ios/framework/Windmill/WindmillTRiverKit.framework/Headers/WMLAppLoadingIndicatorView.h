//
//  WMLAppLoadingIndicatorView.h
//  AppContainer
//
//  Created by AllenHan on 2018/4/19.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, WMLAppLoadingIndicatorStyle) {
    WMLAppLoadingIndicatorStyleDefault,
    WMLAppLoadingIndicatorStyleDark,
    WMLAppLoadingIndicatorStyleLight,
    WMLAppLoadingIndicatorStyleGolden,
    WMLAppLoadingIndicatorStyleRed
};

@interface WMLAppLoadingIndicatorView : UIView

@property (nonatomic, assign) WMLAppLoadingIndicatorStyle colorStyle;

- (instancetype _Nullable )initWithWidth:(CGFloat)width
                                  height:(CGFloat)height
                                 dotSize:(CGFloat)dotSize
                              colorStyle:(WMLAppLoadingIndicatorStyle)colorStyle;

- (void)updateColorStyle:(WMLAppLoadingIndicatorStyle)colorStyle;


/**
 *  手动自行移除动画
 */
- (void)removeAnimation;

/**
 *  重新设置动画颜色
 */
- (void)resetColorStyle:(WMLAppLoadingIndicatorStyle)colorStyle;


@end
