//
//  TBMPBPlayerConst.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 11/21/16.
//  Copyright © 2016 CX. All rights reserved.
//

#ifdef DEBUG
#define debugLog(...) NSLog(__VA_ARGS__)
#define debugMethod() NSLog(@"%s", __func__);
#else
#define debugLog(...)
#define debugMethod()
#endif

#ifndef TBMPBPlayerConst_h
#define TBMPBPlayerConst_h

/*!
 * 播放器类型。
 * 设置不同的播放器类型将选择不同的播放器进行播放。
 */
typedef NS_ENUM(int32_t, TBMPBPlayerType) {
    TBMPBPlayerTypeFFPlayer = 0, //!< 基于 FFmpeg 的播放器。支持 flv/m3u8/mp4，即将废弃。
    TBMPBPlayerTypeAVPlayer = 1, //!< 基于系统 AVPlayer 的播放器。支持 mp4/m3u8。
    TBMPBPlayerTypeTBPlayer = 2 //!< 基于 FFmpeg 的自研播放器。支持 flv/m3u8/mp4，相比FFPlayer性能提升明显，推荐使用
};

/*!
 * 播放场景类型。
 * 设置不同的播放场景将在播放时自动配置不同的播放参数。
 */
typedef NS_ENUM(int32_t, TBMPBPlayScenario) {
    TBMPBPlayScenarioLive = 0, //!< 普通直播。
    TBMPBPlayScenarioLinkLive = 1, //!< 连麦直播。
    TBMPBPlayScenarioPlayback = 2 //!< 点播。
};

/*!
 * 播放器状态。
 */
typedef NS_ENUM(int32_t, TBMPBPlayerStatus) {
    TBMPBPlayerStatusStopped = 0, //!< 播放器停止。
    TBMPBPlayerStatusLoading = 1, //!< 播放器缓冲中。
    TBMPBPlayerStatusPlaying = 2, //!< 播放器正在播放。
    TBMPBPlayerStatusPaused = 3, //!< 播放器暂停。
    TBMPBPlayerStatusStalled = 4, //!< 播放器卡顿。
    TBMPBPlayerStatusSeekingForward = 5, //!< 播放器向前追帧中。
    TBMPBPlayerStatusSeekingBackward = 6, //!< 播放器向后追帧中。
};

/*!
 * 播放器事件类型。
 * 播放器播放视频的过程中会通过 playerEventFired 回调函数上报相关事件。
 */
typedef NS_ENUM(int32_t, TBMPBPlayerEvent) {
    TBMPBPlayerEventPlayerPrepared = 0, //!< 播放器完成初始化。目前兼容性支持该事件，后续会废弃。
    TBMPBPlayerEventCanPlay = 1, //!< 播放器已经可以开始播放。
    TBMPBPlayerEventPlaying = 2, //!< 播放器开始播放。
    TBMPBPlayerEventPause = 3, //!< 播放器暂停。
    TBMPBPlayerEventStalled = 4, //!< 播放器卡顿。
    TBMPBPlayerEventInterrupted = 5, //!< 播放器被中断。
    TBMPBPlayerEventSeekingForward = 6, //!< 播放器向前追帧中。
    TBMPBPlayerEventSeekingBackward = 7, //!< 播放器向后追帧中。
    TBMPBPlayerEventEnded = 8, //!< 播放结束。
    TBMPBPlayerEventException = 9, //!< 播放器异常。播放器尚可播放。
    TBMPBPlayerEventError = 10, //!< 播放器报错。播放器不可播放。
    TBMPBPlayerEventUnknown = 11, //!< 未知。
    TBMPBPlayerEventFirstVideoFrameRendered = 12, //!< 首帧渲染。
    TBMPBPlayerEventWillBeRecycled = 13, //!< 播放器实例将被回收。
    TBMPBPlayerEventFirstAudioFrameRendered = 14,  //!< 音频首帧开始渲染，不对外透出
    TBMPBPlayerEventPlayerPreparing = 15, //!< 播放器开始初始化，外部无需处理
    TBMPBPlayerEventRetryingOpenInput = 16, //!< 播放器网络出错正在重连
    TBMPBPlayerEventVideoRenderingStalled = 17 //!< 播放器视频渲染卡顿
};

/*!
 * 播放器异常类型。
 * 播放器播放视频的过程中通过 playerEventFired 回调函数上报 TBMPBPlayerEventException 事件时，回调函数的参数 info 中，info[@"exceptionCode"] 会带上异常码，这个枚举定义了其中常用的异常码。
 */
typedef NS_ENUM(int64_t, TBMPBPlayerException) {
    TBMPBPlayerExceptionShouldSwitchToLowQualityStream = -20000 //!< 播放器频繁卡顿建议切换低档位流。
};

/*!
 * 播放器错误类型。
 * 播放器播放视频的过程中通过 playerEventFired 回调函数上报 TBMPBPlayerEventError 事件时，回调函数的参数 info 中，info[@"errorCode"] 会带上错误码，这个枚举定义了其中常用的错误码。
 */
typedef NS_ENUM(int64_t, TBMPBPlayerError) {
    TBMPBPlayerErrorTimeout = -60, //!< 播放器连接超时。
    TBMPBPlayerErrorInputOutputError = -5, //!< 媒体资源出错。
    TBMPBPlayerErrorInputOutputErrorSub1 = -50009, //!< 媒体资源出错。
    TBMPBPlayerErrorVideoToolboxFailed = -10000, //!< 播放器硬解码器异常无法使用。
    TBMPBPlayerHTTPBadRequest = -400, //!< HTTP Bad Request。
    TBMPBPlayerHTTPServerError = -500, //!< HTTP Server Error。
    TBMPBPlayerHTTPOther4XX = -499, //!< HTTP Other 4XX。
    TBMPBPlayerDecoderNotFound = -1128613112, //!< 未找到支持的解码器。
    TBMPBPlayerDemuxerNotFound = -1296385272, //!< 未找到支持的 Demuxer。
    TBMPBPlayerProtocolNotFound = -1330794744, //!< 未找到支持的协议。
    TBMPBPlayerURLErrorTimedOut = kCFURLErrorTimedOut,
    TBMPBPlayerURLErrorNetworkConnectionLost = kCFURLErrorNetworkConnectionLost,
    TBMPBPlayerURLErrorResourceUnavailable = kCFURLErrorResourceUnavailable,
    TBMPBPlayerErrorArtpLoadFailed = -10001,
    TBMPBPlayerErrorStreamNotFound = -10604,
    TBMPBPlayerErrorStreamHasStopped = -10605,
    TBMPBPlayerErrorActiveDegrade = -10611,
    TBMPBPlayerErrorUDPNoUsable = -10612,
    TBMPBPlayerErrorArtpUnused = -20000,
    TBMPBPlayerErrorPrepareFailed = -1347571960,
};

/*!
 * 播放器数据类型。
 * 播放播放视频的过程中会通过 playerDataPopped 回调函数上报相关数据。
 */
typedef NS_ENUM(int32_t, TBMPBPlayerData) {
    /*!
     * 播放器上报的流量数据。只支持 TBMPBPlayerTypeFFPlayer。
     *
     * 数据格式(NSDictionary *)：
     * key : value
     * @"IJKMPMoviePlayerNetworkTrafficInfoKey" : (int64_t)
     */
    TBMPBPlayerDataNetworkTraffic = 0,
    
    /*!
     * 播放器上报的用户自定义 SEI 信息。只支持 TBMPBPlayerTypeFFPlayer。
     *
     * 数据格式(NSDictionary *)：
     * key : value
     * @"IJKMPMoviePlayerUserDefinedSEIIDInfoKey" : (int64_t)
     * @"IJKMPMoviePlayerUserDefinedSEIPTSInfoKey" : (int64_t)
     * @"IJKMPMoviePlayerUserDefinedSEIMessageInfoKey" : (NSString *)
     */
    TBMPBPlayerDataUserSEI = 1,
    
    /*!
     * 播放器上报当前播放时间。只支持 TBMPBPlayerTypeAVPlayer 且仅在 playScenairo = TBMPBPlayScenarioPlayback 时有效。
     *
     * 数据格式(NSDictionary *)：
     * key : value
     * @"duration" : (double)
     * @"currentTime" : (double)
     */
    TBMPBPlayerDataPlaybackTime = 2
};

/*!
 * 播放器内容显示模式。
 * 设置不同的内容显示模式，播放器会呈现不同的视频裁剪或拉伸样式。推荐使用 TBMPBPlayerContentModeScaleAspectFit 或 TBMPBPlayerContentModeScaleAspectFill。
 */
typedef NS_ENUM(NSInteger, TBMPBPlayerContentMode) {
    TBMPBPlayerContentModeNone = 0, //!< 等同 TBMPBPlayerContentModeScaleAspectFit。
    TBMPBPlayerContentModeScaleAspectFit, //!< 原比例适配。不会造成视频图像变形，不会裁掉视频图像内容，会留黑边。
    TBMPBPlayerContentModeScaleAspectFill, //!< 裁剪填充。不会造成视频图像变形，会裁掉视频图像内容，不会留黑边。
    TBMPBPlayerContentModeScaleToFill //!< 拉伸填充。会造成视频图像变形，不会裁掉视频图像内容，不会留黑边。
};

#endif /* TBMPBPlayerConst_h */
