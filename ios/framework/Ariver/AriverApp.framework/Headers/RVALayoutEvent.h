//
//  RVALayoutEvent.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/29.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RVALayoutEvent : RVKEvent

@property(nonatomic, readonly, strong) UIView       *layoutView;
@property(nonatomic, assign) CGRect                 newFrame;

+ (instancetype)webViewLayoutBefore:(UIView *)layoutView newFrame:(CGRect)newFrame;

+ (instancetype)webViewLayoutAfter:(UIView *)layoutView newFrame:(CGRect)newFrame;

@end
