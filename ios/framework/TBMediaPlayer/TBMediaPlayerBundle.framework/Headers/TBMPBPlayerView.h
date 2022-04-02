//
//  TBMPBPlayerView.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 10/11/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBMediaPlayerBundle/TBMPBPlayerConst.h>
#import <TBMediaPlayerBundle/TBMPBPlayerOptions.h>
#import <TBMediaPlayerBundle/TBMPBPlayerControlView.h>

@class TBMPBPlayerView;

//extern NSString * const TBMBPPlayerViewDidEnterFullScreenModeNotification;
//extern NSString * const TBMBPPlayerViewDidExitFullScreenModeNotification;
extern NSString * const TBMBPPlayerViewPlayWillBeCalledNotification;


#pragma mark - TBMPBPlayerViewDelegate Interface
@protocol TBMPBPlayerViewDelegate <NSObject>
@optional
- (void)playButtonClickedInPlayerView:(TBMPBPlayerView *)playerView;
- (void)pauseButtonClickedInPlayerView:(TBMPBPlayerView *)playerView;
- (void)playerViewTapped:(TBMPBPlayerView *)playerView;
- (void)playerViewTwiceTapped:(TBMPBPlayerView *)playerView;
- (void)playerViewEnterFullScreenButtonClicked:(TBMPBPlayerView *)playerView;
- (void)playerViewExitFullScreenButtonClicked:(TBMPBPlayerView *)playerView;
- (void)playRateButtonDidClicked:(TBMPBPlayerView *)playerView withRate:(float)rate;

// 以下回调方法仅在开启了默认的全屏功能后会生效。
- (void)playerViewWillEnterFullScreenMode:(TBMPBPlayerView *)playerView;
- (void)playerViewDidEnterFullScreenMode:(TBMPBPlayerView *)playerView;
- (void)playerViewWillExitFullScreenMode:(TBMPBPlayerView *)playerView;
- (void)playerViewDidExitFullScreenMode:(TBMPBPlayerView *)playerView;
@end



#pragma mark - TBMPBPlayerView Interface
@interface TBMPBPlayerView : UIView

#pragma mark - Lifecycle
/*!
 * @abstract 创建播放器 View。
 * @discussion 目前不支持 2 个以上的播放器实例同时播放视频。
 * @param url 播放源地址。必填。
 * @param options 播放器选项。必填。注意：传入 options 时一定要通过 options.extraConfig 设置 m3u8Src 和 businessId 选项。
 * @return 返回 TBMPBPlayerView 实例。
 */
- (instancetype)initWithMediaURL:(NSString *)url options:(TBMPBPlayerOptions *)options;

/*!
 * @abstract 创建播放器 View。
 * @discussion 目前不支持 2 个以上的播放器实例同时播放视频。
 * @return 返回 TBMPBPlayerView 实例，init 方法不会加载任何播放资源和播放设置。后续可以调用 `- (void)loadWithMediaURL:(NSString *)url options:(TBMPBPlayerOptions *)options` 接口来设置播放资源和播放设置，在加载播放资源和播放设置之前不要设置 TBMPBPlayerView 的其他非 UIView 属性。
 */
- (instancetype)init;

/*!
 * @abstract 加载播放资源和播放设置。
 * @param url 播放源地址。必填。
 * @param options 播放器选项。必填。注意：传入 options 时一定要通过 options.extraConfig 设置 m3u8Src 和 businessId 选项。
 */
- (void)loadWithMediaURL:(NSString *)url options:(TBMPBPlayerOptions *)options;

/*!
 * @abstract 加载播放资源和播放设置。
 * @param info 播放源信息。必填。
 * @param options 播放器选项。必填。注意：传入 options 时一定要通过 options.extraConfig 设置 m3u8Src 和 businessId 选项。
 */
- (void)loadWithMediaInfo:(NSDictionary *)info options:(TBMPBPlayerOptions *)options;

/*!
 * @abstract 重新加载新的播放资源和播放设置。
 * @param info 播放源信息。必填。
 * @param options 播放器选项。必填。注意：传入 options 时一定要通过 options.extraConfig 设置 m3u8Src 和 businessId 选项。
 */
- (void)refreshWithMediaInfo:(NSDictionary *)info options:(TBMPBPlayerOptions *)options;

/*!
 * @abstract 刷新播放器。
 * @param index 播放源所在的index。
 * @param options 播放器选项。
 * @discussion 此方法用来动态刷新播放器，使用的前提当前播放器是通过loadWithMediaInfo接口启动的
 */
- (void)refreshWithMediaInfoArrayIndex:(int8_t)index options:(TBMPBPlayerOptions *)options;

/*!
 * @abstract 播放器 View 的代理。
 * @discussion 提供播放器控制界面相关的一些回调。
 */
@property (weak, nonatomic) id<TBMPBPlayerViewDelegate> delegate;

#pragma mark - Player Control
/*!
 * @abstract 开始播放。
 */
- (void)play;

/*!
 * @abstract 暂停播放。
 * @discussion 暂停播放后可以调用 play 方法继续播放。
 */
- (void)pause;

/*!
 * @abstract 停止播放。
 * @discussion 停止播放后不能再播放。一般在销毁播放器之前调用该方法。
 */
- (void)stop;

/*!
 * @abstract 刷新播放器。
 * @param url 播放源地址。
 * @param options 播放器选项。
 * @discussion 此方法用新传入的 url 和新传入的 options 刷新播放器。
 */
- (void)refreshWithMediaURL:(NSString *)url options:(TBMPBPlayerOptions *)options;

@property (assign, nonatomic) BOOL muted; //!< 播放器是否静音。默认为 NO。
@property (assign, nonatomic) TBMPBPlayerContentMode playerContentMode; //!< 播放器内容显示模式。默认为 TBMPBPlayerContentModeScaleAspectFill。
@property (assign, nonatomic) double preferredForwardBufferDuration; //!< 播放器向前缓冲时长参考。单位为 s。默认为 0。仅对 playerType = TBMPBPlayerTypeAVPlayer 且 HLS 且 iOS 10 以上版本生效。
@property (assign, nonatomic) float playbackRate; // !< 播放速度率。限定范围为 [1, 1.5]。

/*!
 * @abstract 业务设置播放器的背景图，设置了背景图后，播放区域的黑色部分用该图片覆盖。
 * @param image 背景图。
 */
- (void)setVideoBackgroundImage:(UIImage *)image;

/*!
 * @abstract 播放器默认控制界面。
 * @discussion 控制界面的视图层级和布局管理由使用方管理。即调用方可以把 playerControlView 添加到任意的视图上，并且可以控制其 frame、layout constraints 等布局属性。建议最低高度 45(此时只包含控制条)。
 */
@property (strong, nonatomic) TBMPBPlayerControlView *playerControlView;

/*!
 * @abstract 是否开启进入和退出全屏时的过渡动画。
 * @discussion 在使用播放器默认控制界面的全屏按钮进入或退出全屏时生效。默认为 YES。
 */
@property (assign, nonatomic) BOOL fullScreenAnimationEnabled;

/*!
 * @abstract 主要用于业务层向播放器在线下发动态配置，比如：Orange 配置。
 * @param config 配置信息。
 * @discussion 请向本 SDK 维护方咨询该接口用法。
 */
- (void)setConfig:(NSDictionary *)config;

/*!
 * @abstract 主要用于业务层向播放器下发一些数据。
 * @param info 数据。
 * @discussion 请向本 SDK 维护方咨询该接口用法。
 */
- (void)setInfo:(NSDictionary *)info;

#pragma mark - 上抛CVPixelBufferRef

/*!
 * @abstract 在播放过程中动态开启或者关闭上抛CVPixelBuffer的功能. 只在playerType = TBMPBPlayerTypeTBPlayer下生效
 * @discussion 1. 如果是起播就要上抛CVPixelBuffer，请一定在TBMPBPlayerOptions中设置playerShouldUpthrowImage为YES；
               2. 开播以后，才可以通过当前接口动态切换；
 */
- (void)toggleUpthrowingCVPixelBufferRef:(BOOL)value;

/*!
 * @abstract 在开启上抛CVPixelBuffer的功能的时候，把native渲染关闭， 只在playerType = TBMPBPlayerTypeTBPlayer下生效
 * @discussion 1. 如果是起播就要生效，请一定在TBMPBPlayerOptions中设置playerShouldNotRenderAfterUpthrowImage为YES；
               2. 开播以后，才可以通过当前接口动态切换；
 */
- (void)toggleNotRenderOnViewCVPixelBufferRef:(BOOL)value;

/*!
 * @abstract 判断当前最新的解码后的视频 Pixel buffer。
 * @discussion 仅在 playerType不等于TBMPBPlayerTypeAVPlayer时有效。
 */
- (BOOL)hasNewVideoPixelBufferToDraw;

/*!
 * @abstract 获取当前播放器解码后的视频 Pixel buffer。
 * @discussion 仅在 playerType不等于TBMPBPlayerTypeAVPlayer 时有效。返回的 CVPixelBufferRef 使用完后需要调用 CVPixelBufferRelease 释放。
 */
- (CVPixelBufferRef)copyCurrentVideoPixelBuffer;

/*!
 * @abstract   底层 VR 渲染 view 的 orientation。
 * @discussion 仅在 playerType = TBMPBPlayerTypeFFPlayer 同时 playerRenderType = 1 时有效。目前在手淘环境下，播放器初始化时不用设置，从小屏到全屏时请设置 UIInterfaceOrientationLandscapeRight，从全屏回到小屏时必须设置为 UIInterfaceOrientationPortrait。
 */
@property (assign, nonatomic) UIInterfaceOrientation renderViewOrientation;

#pragma mark - Player Status
@property (assign, readonly, nonatomic) TBMPBPlayerStatus playerStatus; //!< 播放器状态。
@property (copy, nonatomic) NSString *url; //!< 当前播放源地址。
@property (strong, nonatomic) TBMPBPlayerOptions *options; //!< 当前播放器选项。
- (BOOL)isPlaying; //!< 是否正在播放。

/*!
 * @abstract 当前播放时间进度。
 * @discussion 仅在 playScenairo = TBMPBPlayScenarioPlayback 时有效。单位为秒。
 */
@property (assign, nonatomic) NSTimeInterval currentPlaybackTime;

/*!
 * @abstract 视频总时长。
 * @discussion 仅在 playScenairo = TBMPBPlayScenarioPlayback 时有效。单位为秒。
 */
@property (assign, readonly, nonatomic) NSTimeInterval duration;

/*!
 * @abstract 视频是否从缓存中加载。
 */
@property (assign, readonly, nonatomic) BOOL isLoadingFromCache;

/*!
 * @abstract 缓存时长。
 */
@property (assign, readonly, nonatomic) NSTimeInterval cacheDuration;

/*!
 * @abstract 缓存占总时长的百分比。
 */
@property (assign, readonly, nonatomic) CGFloat cacheProgress;

/*!
 * @abstract 视频画面所在区域。
 */
@property (assign, readonly, nonatomic) CGRect videoRect;

/*!
 * @abstract 视频原始尺寸。
 */
@property (assign, readonly, nonatomic) CGSize naturalSize;

/*!
 * @abstract 播放器可播放时长。
 * @return 返回可播放时长(NSTimeInterval)。
 */
- (NSTimeInterval)playableDuration;

/*!
 * @abstract 视频截图。
 * @discussion 此方法在 playerType = TBMPBPlayerTypeAVPlayer 并且播放源为 M3U8 时不适用。
 * @return 返回视频截图(UIImage *)。
 */
- (UIImage *)snapshotImageAtCurrentTime;

/*!
 * @abstract 播放器总体状态数据。
 * @discussion 主要用于测试时获取播放器状态数据进行监测。
 * @return 返回状态数据(NSDictionary *)。
 */
- (NSDictionary *)playerStatusData;

/*!
 * @abstract 播放器内核对象是否处于被回收状态。
 */
- (BOOL)didPlayerCoreRecycled;

/*!
 * @abstract 当前视频切换到新的分辨率地址上进行帧同步播放
 * @param url 同一场直播的另一个分辨率的流地址
 * @discussion 1. 此接口只在这些条件(是直播、playerType是FFPlayer、isPlaying为YES)同时满足时生效；
 *             2. 调用成功后，会收到TBMPBPlayerEventSwitchResolutionResult事件，参数info会携带具体信息；
 */
-(void) switchVideoResolutionSmoothlyWithNewUrl:(NSString*)url;

#pragma mark - Player Event
/*!
 * 上报播放器事件的回调方法。
 *
 * 回调函数的返回参数：
 * event：事件类型。
 * info：事件相关的信息。比如：当回调函数上报 TBMPBPlayerEventError 事件时，参数 info 的 info[@"errorCode"] 会带上错误码。
 */
@property (copy, nonatomic) void (^playerEventFired)(TBMPBPlayerEvent event, NSDictionary *info);

/*!
 * 上报播放器数据的回调方法。
 *
 * 回调函数的返回参数：
 * dataType：数据类型。
 * data：具体数据。关于不同类型数据的具体格式请参考 TBMPBPlayerData 相关说明。
 */
@property (copy, nonatomic) void (^playerDataPopped)(TBMPBPlayerData dataType, NSDictionary *data);

/*!
 * 上报播放器状态的回调方法。
 *
 * 回调函数的返回参数：
 * status：状态类型。
 */
@property (copy, nonatomic) void (^playerStatusChanged)(TBMPBPlayerStatus status);

@end

