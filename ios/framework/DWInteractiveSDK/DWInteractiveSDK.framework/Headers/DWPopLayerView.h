//
//  DWPopLayerView.h
//  DWInteractiveSDK
//
//  Created by jyi on 16/9/6.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DWPopLayerView : UIView

@property (nonatomic, assign) CGFloat modalThreshold;

- (CGFloat)alphaOfPointFromViewScreenShot:(CGPoint)point;
- (CGFloat)alphaOfPointFromLayer:(CGPoint)point;

@end
