//
//  DWInstance+Interface.h
//  DWInteractiveSDK
//
//  Created by Jyi on 2018/1/12.
//  Copyright © 2018年 alibaba. All rights reserved.
//


#import <DWInteractiveSDK/DWInstance.h>
@interface DWInstance (Interface)

/**
 * 视频播放
 **/
- (void)videoPlay;

/**
 * 视频暂停
 **/
- (void)videoPause;

/**
 *  视频是否正在播放
 *
 *  @return 是否正在播放
 */
- (BOOL)isVideoViewPlaying;

/*
 * 是否使用视频预加载 default YES
 * 在调用setup之前调用此接口
 */
@property (nonatomic, assign) BOOL preload;

/*
 * preload = NO的情况下，业务方主动调用此接口，进行视频预加载
 */
- (void) loadVideo;

/*
 * 是否循环播放
 */
@property (nonatomic, assign) BOOL loop;

/*
 * 隐藏loading状态显示的UI，需要setup之前调用，不然第一次loading会被显示
 */
@property (nonatomic, assign) BOOL loadingHidden;

/**
 * 播放器静音, default = NO
 */
@property (nonatomic, assign) BOOL muted;

/*
 * 控件层，相对interactiView的间距。 defalut = 0.0
 */
@property (nonatomic, assign) CGFloat controlsViewTopMargin;

/*
 * 隐藏mini进度条，因是UI操作，请在setup后调用。
 */
@property (nonatomic, assign) BOOL miniProgressViewHidden;

/*
 * 隐藏mini进度条上的锚点，默认为YES
 */
@property (nonatomic, assign) BOOL miniProgressAnchorHidden;

/*
 * 自定义弹出的toast的上边距
 */
@property (nonatomic, assign) CGFloat toastTopMargin;

/*
 * 正常视频屏幕状态下，并且非静音状态下，开启手势控制视频播放进度 default = NO
 * setup之后调用此接口
 */
@property (nonatomic, assign) BOOL normalScreenAndNotMutedForGestureSeekOperation;

@end








