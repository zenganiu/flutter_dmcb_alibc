//
//  RVAButton.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/30.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^RVADownloadImageComplete)(UIImage *image);

@interface RVAButton : UIButton

@property(nonatomic, assign) int redDot;

- (void)setBackgroundImageUrl:(NSString *)imageUrlString forState:(UIControlState)state;

- (void)setBackgroundImageUrl:(NSString *)imageUrlString forState:(UIControlState)state complete:(RVADownloadImageComplete)complete;

- (void)setImageUrl:(NSString *)imageUrlString forState:(UIControlState)state;

- (void)setImageUrl:(NSString *)imageUrlString forState:(UIControlState)state complete:(RVADownloadImageComplete)complete;

@end
