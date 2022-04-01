//
//  RVAScrollPadView.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/6.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
#if INDEPENDENT

#import <UIKit/UIKit.h>

@protocol RVAScrollPadViewDataSource;
@protocol RVAScrollPadViewDelegate;

@interface RVAScrollPadView : UIView

@property(nonatomic, assign) UIEdgeInsets                   viewInsets;
@property(nonatomic, weak) id<RVAScrollPadViewDataSource>    dataSource;
@property(nonatomic, weak) id<RVAScrollPadViewDelegate>      delegate;
@property(nonatomic, assign) BOOL                           isShowing;
@property(nonatomic, strong) UIColor                        *contentViewBgColor;
@property(nonatomic, strong) UILabel                        *tipsLabel;
@property(nonatomic, strong) UIButton                       *cancelBtn;

- (void)reload;

- (void)show;

- (void)dismiss;

@end


// datasource
@protocol RVAScrollPadViewDataSource <NSObject>

- (NSUInteger)numberOfLines;

- (NSArray *)scrollPadView:(RVAScrollPadView *)scrollPadView viewsAtLineIndex:(NSUInteger)index;

@end


// delegate
@protocol RVAScrollPadViewDelegate <NSObject>

- (CGFloat)scrollPadView:(RVAScrollPadView *)scrollPadView heightAtLineIndex:(NSUInteger)index;

@end

#endif
