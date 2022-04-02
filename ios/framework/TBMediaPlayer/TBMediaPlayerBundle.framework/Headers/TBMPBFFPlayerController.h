//
//  TBMPBFFPlayerController.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 3/29/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBMediaPlayerBundle/TBMPBUtil.h>
#import <TBMediaPlayerBundle/TBMPBFFOptions.h>
#import <TBMediaPlayerBundle/TBMPBPlayerProtocol.h>

#pragma mark - Common Define
// Player Info Notificcation.
extern NSString *const TBMPBPlaybackIsPreparedToPlayDidChangeNotification;
extern NSString *const TBMPBPlayerPlaybackDidFinishNotification;
extern NSString *const TBMPBPlayerPlaybackDidFinishReasonUserInfoKey;
extern NSString *const TBMPBPlayerPlaybackStateDidChangeNotification;
extern NSString *const TBMPBPlayerLoadStateDidChangeNotification;
extern NSString *const TBMPBPlayerIsAirPlayVideoActiveDidChangeNotification;
extern NSString *const TBMPBNaturalSizeAvailableNotification;
extern NSString *const TBMPBPlayerVideoDecoderOpenNotification;
extern NSString *const TBMPBPlayerFirstVideoFrameRenderedNotification;
extern NSString *const TBMPBPlayerFirstAudioFrameRenderedNotification;
extern NSString *const TBMPBPlayerReceivePTSDTSNotifcation;
extern NSString *const TBMPBPlayerReceivePTSUserInfoKey;
extern NSString *const TBMPBPlayerReceiveDTSUserInfoKey;

// Stream Monitor Notification.
extern NSString *const TBMPBPlayerStreamAbnormalNotification;
extern NSString *const TBMPBPlayerStreamAbnormalTypeInfoKey;
extern NSString *const TBMPBPlayerPrePTSInfoKey;
extern NSString *const TBMPBPlayerCurrentPTSInfoKey;

extern NSString *const TBMPBPlayerNetworkShakeNotification;
extern NSString *const TBMPBPlayerDelayTimeInfoKey;

extern NSString *const TBMPBPlayerAVFormatTimeNotification;
extern NSString *const TBMPBPlayerOpenTimeInfoKey;
extern NSString *const TBMPBPlayerFindStreamInfoTimeInfoKey;

extern NSString *const TBMPBPlayerDecodeErrorNotification;
extern NSString *const TBMPBPlayerFrameQueueNullNotification;
extern NSString *const TBMPBPlayerVideoToolboxFailNotification;

extern NSString *const TBMPBPlayerShouldSwitchToLowQualityStreamNotification;

// Network Traffic Notification.
extern NSString *const TBMPBPlayerNetworkTrafficNotification;
extern NSString *const TBMPBPlayerNetworkTrafficInfoKey;

extern NSString *const TBMPBPlayerUserDefinedSEINotification;
extern NSString *const TBMPBPlayerUserDefinedSEIIDInfoKey;
extern NSString *const TBMPBPlayerUserDefinedSEIPTSInfoKey;
extern NSString *const TBMPBPlayerUserDefinedSEIMessageInfoKey;

extern NSString *const TBMPBPlayerARTPErrorCode;

typedef NS_ENUM(int32_t, TBMPBPlayerStreamAbnormalType) {
    TBMPBPlayerStreamAbnormalTypeAdjoin = 0,
    TBMPBPlayerStreamAbnormalTypeVideo = 1,
    TBMPBPlayerStreamAbnormalTypeAudio = 2,
    TBMPBPlayerStreamAbnormalTypeAVStream = 3,
    TBMPBPlayerStreamAbnormalTypeVideoDTSZero = 4
};

// Use TBMPBPlayerContentMode instead.
//typedef NS_ENUM(NSInteger, TBMPBMovieScalingMode) { // Equal to 'IJKMPMovieScalingMode'.
//    TBMPBMovieScalingModeNone, // No scaling
//    TBMPBMovieScalingModeAspectFit, // Uniform scale until one dimension fits
//    TBMPBMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
//    TBMPBMovieScalingModeFill // Non-uniform scale. Both render dimensions will exactly match the visible bounds
//};

typedef NS_ENUM(NSInteger, TBMPBMoviePlaybackState) { // Equal to 'IJKMPMoviePlaybackState'.
    TBMPBMoviePlaybackStateStopped,
    TBMPBMoviePlaybackStatePlaying,
    TBMPBMoviePlaybackStatePaused,
    TBMPBMoviePlaybackStateInterrupted,
    TBMPBMoviePlaybackStateSeekingForward,
    TBMPBMoviePlaybackStateSeekingBackward,
    TBMPBMoviePlaybackStatePrepared
};

typedef NS_OPTIONS(NSUInteger, TBMPBMovieLoadState) { // Equal to 'IJKMPMovieLoadState'.
    TBMPBMovieLoadStateUnknown = 0,
    TBMPBMovieLoadStatePlayable = 1 << 0,
    TBMPBMovieLoadStatePlaythroughOK = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    TBMPBMovieLoadStateStalled = 1 << 2, // Playback will be automatically paused in this state, if started
};

typedef NS_ENUM(NSInteger, TBMPBMovieFinishReason) { // Equal to 'IJKMPMovieFinishReason'.
    TBMPBMovieFinishReasonPlaybackEnded,
    TBMPBMovieFinishReasonPlaybackError,
    TBMPBMovieFinishReasonUserExited,
    IJKMPMovieFinishReasonARTPError
};

typedef NS_ENUM(int, RTCSTREAM_TRANSPORT_TYPE) {
    FFP_PROP_ARTP_FFDECODER_THREAD = 21801,         //设置ff解码线程数
    RTCSTREAM_STATSTYPE_RTT = 21901,                //RTT
    RTCSTREAM_STATSTYPE_RECV_BUFFER_DELAY = 21902,  //音视频缓存延时长度
    RTCSTREAM_STATSTYPE_RECV_JITTER = 21903,        //音视频抖动
    RTCSTREAM_STATSTYPE_RECV_LOSS_RATE = 21904,     //音视频丢包率
    RTCSTREAM_STATSTYPE_NACK_REQ_RSP_NUM = 21905,   //nack请求响应次数
    RTCSTREAM_STATSTYPE_FEC_RECOVERED_NUM = 21906,  //fec 恢复次数
    RTCSTREAM_STATSTYPE_NET_RECV_RATE = 21907,      //音视频网络接收码率
    RTCSTREAM_TRANSPORT_STREAM_INFO = 21990,        //traceid和sfu_ip
    RTCSTREAM_TRANSPORT_START_INFO = 21991,         //启播各项耗时
    RTCSTREAM_TRANSPORT_INFO_SNAPSHOT = 21992,      //卡顿瞬间获取rtc状态信息 SeqNO=9999
    RTCSTREAM_TRANSPORT_DELAY_INFO = 21993,         //端到端延时相关信息
    RTCSTREAM_TRANSPORT_STATS_INCYCLE = 21994,      //周期性指标计算
};

#pragma mark - TBMPBFFPlayerController Interface
@interface TBMPBFFPlayerController : NSObject // 'IJKFFMoviePlayerController' Wrapper
@property (strong, atomic) id ijkFFPlayer; // IJKFFMoviePlayerController
@property (weak, nonatomic) UIView *playerView; // Retained by ijkFFPlayer, so use 'weak' here.

@property (assign, nonatomic) BOOL shouldShowHudView;
@property (assign, readonly, nonatomic) BOOL isPreparedToPlay;
@property (assign, nonatomic) BOOL muted; // Default is NO.
@property (assign, nonatomic) TBMPBPlayerContentMode contentMode; // Default is AspectFill.
@property (assign, nonatomic) float playbackRate;

- (instancetype)initWithUrl:(NSString *)url;
- (instancetype)initWithUrl:(NSString *)url options:(TBMPBFFOptions *)options;

- (void)setConfig:(NSDictionary *)config;
- (void)setInfo:(NSDictionary *)info;

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (void)shutdown;
- (void)prepareToRecycle;

- (BOOL)isPlaying;
- (BOOL)shouldPlayAfterLoadingOrSeeking;
- (NSTimeInterval)playableDuration;
- (BOOL)isVideoToolboxOpen;

- (BOOL)hasNewVideoPixelBufferToDraw;
- (CVPixelBufferRef)copyCurrentVideoPixelBuffer;
@property (assign, nonatomic) UIInterfaceOrientation renderViewOrientation;

@property (assign, nonatomic) NSTimeInterval currentPlaybackTime;
@property (assign, readonly, nonatomic) NSTimeInterval duration;
@property (assign, readonly, nonatomic) CGRect videoRect;
@property (assign, readonly, nonatomic) CGSize naturalSize;
- (UIImage *)thumbnailImageAtCurrentTime;
- (NSDictionary *)playerStatusData;
@property (copy, readonly, nonatomic) NSString *liveIP;
@property (copy, readonly, nonatomic) NSString *localIP;
@property (copy, readonly, nonatomic) NSString *routeNodes;

@property (copy, nonatomic) void (^playerEventFired)(TBMPBPlayerEvent event, NSDictionary *info);
@property (copy, nonatomic) void (^playerDataPopped)(TBMPBPlayerData dataType, NSDictionary *data);

- (TBMPBMovieLoadState)loadState;
- (TBMPBMoviePlaybackState)playbackState;
- (void)clearBackgroundColor;

-(void) switchVideoResolutionSmoothlyWithNewUrl:(NSString*)url;

@end
