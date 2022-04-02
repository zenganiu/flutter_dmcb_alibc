//
//  RVAMenuItem.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/6.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
#if INDEPENDENT

#import <UIKit/UIKit.h>

@interface RVAMenuItem : UIView

@property(nonatomic, strong) UIButton *button;
@property(nonatomic, strong) UILabel  *label;

- (instancetype)initWithIcon:(NSString *)icon title:(NSString *)title;

@end

#endif
