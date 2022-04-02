//
//  RVANavigationTitleView.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVANavigationTitleViewProtocol.h"

@protocol RVANavigationTitleViewDelegate;

@interface RVANavigationTitleView : UIView <RVANavigationTitleViewProtocol>

@property(nonatomic, weak) id<RVANavigationTitleViewDelegate>    delegate;

- (void)startLoading; // 开始转菊花，frame.size.width = 30

- (void)stopLoading; // 结束

- (void)doAnimationRightIcon:(BOOL)isDown; // 右边icon向上、下动画

@end
