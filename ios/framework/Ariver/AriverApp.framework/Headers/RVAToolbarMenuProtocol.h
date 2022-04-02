//
//  RVAToolbarMenuProtocol.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RVAToolbarMenuDelegate;

@protocol RVAToolbarMenuProtocol <NSObject>

@required
- (void)show;

- (void)dismiss;

- (void)reload;

- (UILabel *)tipsLabel;

- (BOOL)isShowing;

- (void)setToolbarMenu:(NSDictionary *)data asDefault:(BOOL)asDefault;

@optional
- (void)setViewInsets:(UIEdgeInsets)insets;

- (void)setBackgroundColor:(UIColor *)color;

- (void)setContentViewBgColor:(UIColor *)color;

- (void)setMenuItemImageViewInsets:(UIEdgeInsets)insets;

// cancel btn
- (UIButton *)cancelButton;

- (void)setDelegate:(id<RVAToolbarMenuDelegate>)delegate; // 若外部设置了，则kRVAEvent_Scene_ToolbarMenu_Select事件无法发出
- (id<RVAToolbarMenuDelegate>)delegate;

@end


@protocol RVAToolbarMenuDelegate <NSObject>

@optional
- (void)toolbarMenu:(id<RVAToolbarMenuProtocol>)toolbarMenu didSelectedItem:(id)item; // 必须实现.tag方法

@end
