//
//  TRVVideoPlayerViewDelegateProtocol.h
//  Triver
//
//  Created by 岚遥 on 2019/7/28.
//

#import <Foundation/Foundation.h>
#import "TRVVideoPlayerViewProtocol.h"


@class TRVVideoPlayerModel;

NS_ASSUME_NONNULL_BEGIN

@protocol TRVVideoPlayerViewDelegateProtocol <NSObject>

@optional

/*!
 播放器开始加载
 */
- (void)videoPlayerViewWillStartLoading:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器完成加载
 */
- (void)videoPlayerViewDidReadyToPlay:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器将要开始播放视频
 */
- (void)videoPlayerViewWillStartPlaying:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器改变播放状态
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView willChangePlayStatus:(TRVVideoPlayerStatus)status;

/*!
 播放器已经开始播放视频
 */
- (void)videoPlayerViewDidStartPlaying:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器已经播放完成
 */
- (void)videoPlayerViewDidFinishPlaying:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器暂停
 */
- (void)videoPlayerViewDidPause:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器停止
 */
- (void)videoPlayerViewDidStopPlaying:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器开始更新当前播放时间
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didUpdateCurrentTimeWithData:(NSDictionary *)data;

/*!
 播放器是否成功跳转到time去播放
 */
- (void)videoPlayerViewDidSeekToTime:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 播放器修改缓存状态
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didChangeShuffleMode:(BOOL)enabled;

/*!
 播放器开始更新缓存进度
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didUpdateStreamingProgress:(float)progress;

/*!
 播放器出现错误
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didFailedWithErrorMessage:(NSDictionary *)errorMessage;

/*!
 点击静音按钮
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didClickVoiceButtonWithSelected:(BOOL)muteStatus;

/*!
 点击全屏按钮
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didClickFullScreenButtonWithSelected:(BOOL)isSelected;

/*!
 点击下方播放、暂停按钮
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didClickPlayButton:(BOOL)play;

/*!
 点击中间播放、暂停按钮
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didClickCenterPlayButton:(BOOL)play;

/*!
 点击重试
 */
- (void)videoPlayerViewDidClickRetryButton:(id<TRVVideoPlayerViewProtocol>)playerView;

/*!
 单击视频视图
 */
- (void)videoPlayerView:(id<TRVVideoPlayerViewProtocol>)playerView didTapPlayerViewInPoint:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
