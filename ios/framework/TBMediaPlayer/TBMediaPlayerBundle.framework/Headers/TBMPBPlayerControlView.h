//
//  TBMPBPlayerControlView.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 8/30/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBMediaPlayerBundle/TBMPBPlayerConst.h>

@class TBMPBPlayerControlView;

#pragma mark - TBMPBPlayerControlViewDelegate Interface
@protocol TBMPBPlayerControlViewDelegate <NSObject>
- (void)playButtonDidClickedInControlView:(TBMPBPlayerControlView *)playerControlView;
- (void)pauseButtonDidClickedInControlView:(TBMPBPlayerControlView *)playerControlView;
- (void)fullScreenButtonDidClickedInControlView:(TBMPBPlayerControlView *)playerControlView;
- (void)miniScreenButtonDidClickedInControlView:(TBMPBPlayerControlView *)playerControlView;
- (void)progressSliderBeginToDragInControlView:(TBMPBPlayerControlView *)playerControlView;
//- (void)progressSliderCancelDragInControlView:(TBMPBPlayerControlView *)playerControlView;
- (void)progressSliderDidDragToTime:(NSTimeInterval)time inControlView:(TBMPBPlayerControlView *)playerControlView;
- (void)controlViewDidTapped:(TBMPBPlayerControlView *)playerControlView;
- (void)controlViewDidTwiceTapped:(TBMPBPlayerControlView *)playerControlView;
- (void)playRateButtonDidClickedInControlView:(float)rate;
@end


#pragma mark - TBMPBPlayerControlViewDataSource Interface
@protocol TBMPBPlayerControlViewDataSource <NSObject>
- (NSTimeInterval)playerDurationForControlView:(TBMPBPlayerControlView *)playerControlView;
- (NSTimeInterval)playerCurrentPlaybackTimeForControlView:(TBMPBPlayerControlView *)playerControlView;
- (BOOL)isPlayerPlayingForControlView:(TBMPBPlayerControlView *)playerControlView;
@end


#pragma mark - TBMPBPlayerControlView Interface
@interface TBMPBPlayerControlView : UIView

@property (weak, nonatomic) id<TBMPBPlayerControlViewDelegate> delegate;
@property (weak, nonatomic) id<TBMPBPlayerControlViewDataSource> dataSource;

@property (assign, nonatomic) BOOL gestureRecognizerEnabled; //!< 是否开启播放控制界面的手势识别功能。
@property (assign, nonatomic) BOOL tapGestureRecognizerEnabled; //!< 是否开启单击手势识别。
@property (assign, nonatomic) BOOL twiceTapGestureRecognizerEnabled; //!< 是否开启双击手势识别。
@property (assign, nonatomic) BOOL panGestureRecognizerEnabled; //!< 是否开启上下左右滑动手势识别。

@property (assign, nonatomic) BOOL showControlBar; //!< 是否显示播放器控制条。
@property (strong, nonatomic) UIColor *controlBarBackgroundColor; //!< 播放器控制条背景颜色。
@property (assign, nonatomic) BOOL showFullScreenButton; //!< 是否显示全屏按钮。
@property (strong, nonatomic) UIButton *fullScreenButton;
@property (assign, nonatomic) BOOL showPlayrateButton;

@property (strong, nonatomic) UISlider *progressSlider; //!< 方便其他业务定制颜色等效果

- (instancetype)initWithFrame:(CGRect)frame  options:(NSDictionary*)options;
- (void)refreshPlayButtonStatus:(TBMPBPlayerStatus)status; //!< 刷新播放按钮的状态。
- (void)refreshPlayerProgressWithTimeInfo:(NSDictionary *)info; //!< 刷新播放进度。

@end
