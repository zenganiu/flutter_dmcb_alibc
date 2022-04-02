//
//  RVANavigationTitleViewProtocol.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RVANavigationTitleViewDelegate;

@protocol RVANavigationTitleViewProtocol <NSObject>

@required
// mainTitle
- (void)setMainTitle:(NSString *)mainTitle subtitle:(NSString *)subtitle;

// titleLoading
- (void)showTitleLoading;

- (void)hideTitleLoading;

@optional
// mainTitleLabel
- (UILabel *)mainTitleLabel;

// subtitleLabel
- (UILabel *)subtitleLabel;

// padding
- (void)setPaddingLeft:(CGFloat)paddingLeft;

- (void)setPaddingRight:(CGFloat)paddingRight;

// right icon
- (void)setRightIconImage:(UIImage *)image;

- (void)setRightIconWidth:(CGFloat)width;

- (void)setCanShowRightIconWhenSubTitleIsWhitespace:(BOOL)canShow; // defult is NO

// delegate
- (void)setDelegate:(id<RVANavigationTitleViewDelegate>)delegate;

- (id<RVANavigationTitleViewDelegate>)delegate;

- (void)doAnimationRightIcon:(BOOL)isDown;

// rightIconImageView
- (UIImageView *)rightIconImageView;
@end


@protocol RVANavigationTitleViewDelegate <NSObject>

@optional
// 点击了主标题
- (void)navigationTitleView:(id<RVANavigationTitleViewProtocol>)navigationTitleView didClickedMainTitleView:(UIView *)mainTitleView;
// 点击了副标题
- (void)navigationTitleView:(id<RVANavigationTitleViewProtocol>)navigationTitleView didClickedSubTitleView:(UIView *)subtitleView;
// 点击了右边图标
- (void)navigationTitleView:(id<RVANavigationTitleViewProtocol>)navigationTitleView didClickedRightIconView:(UIView *)rightIconView;

@end
