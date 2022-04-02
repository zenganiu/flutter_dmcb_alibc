//
//  VideoPlayerLifecycleProtocol.h
//  DWAVPlayerSDK
//
//  Created by 凌言 on 16/4/3.
//  Copyright © 2016年 Taobao.com. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <DWInteractiveSDK/DWPlayerView.h>
@protocol DWPlayerLifecycleProtocol <NSObject>

@optional

- (void)onVideoStart;
- (void)onVideoClose;

- (void)onVideoPause;
- (void)onVideoResignActive;
- (void)onVideoBecomeActive;
- (void)onVideoTapToPause;
- (void)onVideoPlay;
- (void)onVideoTapToPlay;
//- (void)onVideoSeekTo:(CGFloat)percent;
- (void)onVideoPrepared;
- (void)onVideoError:(NSError*)error;
- (void)onVideoComplete;
- (void)onVideoFullScreen;
- (void)onVideoNormalScreen;
- (void)onVideoFloatingWindow;
- (void)onVideoTimeChanged:(CGFloat)time;
- (void)onVideoLoadedProgressChanged:(CGFloat)progress;

- (void)onVideoStartLoading;
- (void)onVideoEndLoading;
- (void)onVideoSliderStartDrag;

//弹出阻塞播放的Prompt View
- (void)onShowPromptView;

// 展示免流窗口
- (void)onShowFreeView;

// 隐藏免流窗口
- (void)onHideFreeView;

// 首帧渲染完成
- (void)onFirstVideoFrameRendered:(NSDictionary *)info;

//小窗被点击
- (void) onFloatingWindowTap;

//静音播放
- (void) onMuted:(BOOL)b;

//- (void)onVideoModeChangeTo:(DWPlayerViewMode)mode;
- (void)onVideoViewTapAtPlayedTime:(CGFloat)playedTime;

- (void) onVideoControlBarHidden:(BOOL)hidden;


//出网络提示错误页时点击重试按钮
- (void)onNetWorkErrorTapToRetry;

- (void) switchFullScreen;


//fangying
- (void)shouldHideView;
- (void)shouldShowView;

@end

