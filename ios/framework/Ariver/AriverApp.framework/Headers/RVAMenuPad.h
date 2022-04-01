//
//  RVAMenuPad.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/6.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
#if INDEPENDENT

#import <Foundation/Foundation.h>

@protocol RVAMenuPadDataSource;

@interface RVAMenuPad : NSObject

@property(nonatomic, weak) id <RVAMenuPadDataSource> dataSource;
@property(nonatomic, readonly) BOOL                 isShowing;

- (void)show;

- (void)dismiss;

- (void)reload;

- (BOOL)isShowing;

- (void)setViewInsets:(UIEdgeInsets)insets;

- (void)setBackgroundColor:(UIColor *)color;

- (void)setContentViewBgColor:(UIColor *)color;

- (UILabel *)tipsLabel;

- (UIButton *)cancelButton;

@end


@protocol RVAMenuPadDataSource <NSObject>

- (NSUInteger)numberOfLines;

- (NSArray *)menuPad:(RVAMenuPad *)menuPad itemsAtLineIndex:(NSInteger)index;

@end

#endif
