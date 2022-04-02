//
//  DWThumbnailView.h
//  DWInteractiveSDK
//
//  Created by Jyi on 2017/8/10.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DWThumbnailView : UIView

@property (nonatomic, strong) UIImageView *backgroundImageView;
@property (nonatomic, strong) UIImageView *bigPlayBtn;
@property (nonatomic, strong) UILabel *durationLabel;

@property (nonatomic, strong) NSString *playTimesText;

@property (nonatomic, assign) BOOL needAnimation;

@property (nonatomic, assign) BOOL foreverHidden;

@end
