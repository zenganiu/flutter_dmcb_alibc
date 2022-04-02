//
//  TRVVideoPlayerViewProtocol.h
//  Video
//
//  Created by 岚遥 on 2019/10/25.
//  Copyright © 2019 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVVideoPlayerModel.h"

@protocol TRVVideoPlayerViewDelegateProtocol;

NS_ASSUME_NONNULL_BEGIN

@protocol TRVVideoPlayerViewProtocol <NSObject>

@property (nonatomic, weak) id<TRVVideoPlayerViewDelegateProtocol> delegate;
@property (nonatomic, assign, getter=isFullScreen) BOOL fullScreen;

/**
 设置初始化数据
 */
- (void)setupDataWithVideoModel:(TRVVideoPlayerModel *)playerModel;

/**
 播放
 */
- (void)play;

/**
 暂停
 */
- (void)pause;

/**
 停止
 */
- (void)stop;

/**
 设置播放速度
 */
- (void)setNomarlRate:(CGFloat)rate;

/**
 静音
 */
- (void)setMuted:(BOOL)muted;

/*!
 跳转到指定位置，单位 s
 */
- (void)seekToTimeToPlay:(double)time;

/*!
 展示状态栏
 */
- (void)showStatusBar:(BOOL)isShow;

/**
 是否正在展示状态栏
 */
- (BOOL)isShowBottomView;

/**
 是否正在播放
 */
- (BOOL)isPlaying;

@end

NS_ASSUME_NONNULL_END
