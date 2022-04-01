//
//  DWSlider.h
//  DWPlayerView
//
//  Created by Zhubicheng on 08/12/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
@class DWAnchorModel;

@interface DWSmallProgressView : UIView
@property (nonatomic, assign) double progress;
@property (nonatomic, assign, readonly) double maxProgress;
//@property (nonatomic, strong) UIImageView *gifImageView;
@property (nonatomic, assign) CGFloat totalDuration;
@property (nonatomic, assign) CGFloat curDuration;

@property (nonatomic, strong) UILabel *timeLabel;

@property (nonatomic, assign) double secondaryValue;

@property (nonatomic, assign) BOOL progressViewHidden;

@property (nonatomic, assign) BOOL anchorHidden;

// 设置锚点数据
- (void)updateAnchorNaviWithModels:(NSArray<DWAnchorModel *> *)models duration:(Float64)duration;
- (void)updateAnchorNaviWithDuration:(Float64)duration;

@end


////////////////////////////

@interface DWSlider : UISlider

- (void)setSecondaryValue:(float)value;
- (void)setSecondaryTintColor:(UIColor *)tintColor;

/**
 *  size参数废弃,原先传size是为了使用Quartz2D计算尺寸，现在是直接给图片
 *
 *  @param size <#size description#>
 */
- (void)setThumbSize:(CGSize)size;

// 设置锚点数据
- (void)updateAnchorNaviWithModels:(NSArray<DWAnchorModel *> *)models duration:(Float64)duration;
- (void)updateAnchorNaviWithDuration:(Float64)duration;

// 隐藏/隐藏气泡提示信息
- (void)hideAnchorBubbleView:(BOOL)hidden;

@end
