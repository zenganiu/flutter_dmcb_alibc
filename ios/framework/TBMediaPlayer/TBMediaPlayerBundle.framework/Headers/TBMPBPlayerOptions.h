//
//  TBMPBPlayerOptions.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 10/13/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBMediaPlayerBundle/TBMPBPlayerConst.h>

@interface TBMPBPlayerOptions : NSObject

/*!
 * @abstract 获得默认播放器选项实例。各选项均为默认值。
 * @return 返回 TBMPBPlayerOptions 实例。
 */
+ (instancetype)defaultPlayerOptions;

@property (assign, nonatomic) TBMPBPlayerType playerType; //!< 播放器类型。默认为 TBMPBPlayerTypeTBPlayer。
@property (assign, nonatomic) TBMPBPlayScenario playScenario; //!< 播放场景类型。默认为 TBMPBPlayScenarioLive。
@property (assign, nonatomic) BOOL autoplay; //!< 是否自动播放。默认为 YES。
@property (assign, nonatomic) BOOL loop; //!< 是否循环播放。仅在 playScenairo = TBMPBPlayScenarioPlayback 时有效。默认为 NO。
@property (assign, nonatomic) BOOL cache; //!< 目前不支持缓存。

/*!
 * 应用退到后台时是否保持播放。在 playerType = TBMPBPlayerTypeFFPlayer or TBMPBPlayerTypeTBPlayer时有效。默认为 YES。
 * 当 playerType = TBMPBPlayerTypeAVPlayer 时退到后台一定会暂停。
 * 对于直播(playScenairo = TBMPBPlayScenarioLive/TBMPBPlayScenarioLinkLive)，退到后台暂停再切回前台时会刷新播放器以防止累积延时；
 * 对于点播(playScenairo = TBMPBPlayScenarioPlayback)，退到后台暂停再切回前台时即直接接着播放。
 */
@property (assign, nonatomic) BOOL pauseInBackground;

@property (assign, nonatomic) int32_t playerRenderType; //!< 0: defalut，glViewRender; 1: VR render。
@property (assign, nonatomic) int32_t playerRenderOrientation; //!< 默认是0，表示UIInterfaceOrientationPortrait，1表示UIInterfaceOrientationLandscapeRight

@property (assign, nonatomic) BOOL playerShouldUpthrowImage; //!< 在播放器上抛解码后的视频数据交给业务层渲染视频，默认 NO。  要设置为YES的话，推荐和下面一起设置。 
@property (assign, nonatomic) BOOL playerShouldNotRenderAfterUpthrowImage; //!< 在播放器上抛解码后的视频数据交给业务层渲染视频后，自己不渲染View ，默认NO。

/*!
 * 其他播放器选项。默认为 nil。
 * 包括：
 *
 * m3u8Src：M3U8 播放地址(NSString *)。当 TBMediaPlayer 动态库加载失败时，将自动切换到 AVPlayer，这时 AVPlayer 会使用 m3u8Src 播放源进行播放。必填。
 * businessId：业务 ID(NSString *)。业务接入方接入 TBMediaPlayerBundle 时需要传入 businessId 用于埋点数据区分，如果不传则不会上报埋点数据，此外，业务方还需要到魔兔平台注册该埋点。比如淘宝直播需要传入 "TBLive"。必填。
 * subBusinessType：业务细分类型(NSString *)。业务接入方接入 TBMediaPlayerBundle 时可以根据自己的需要传入 subBusinessType 区分细分业务。选填。
 * videoChannel：业务承接渠道类型(NSString *)。比如手淘的视频全屏页、视频 timeline 等。选填。
 * userId：用户 ID(NSString *)。业务接入方接入 TBMediaPlayerBundle 时需要传入 userId 用于埋点时的用户区分，用户未登录时传空字符串即可。淘宝直播业务必填。
 * feedId：直播间 Feed ID(NSString*)。业务接入方接入 TBMediaPlayerBundle 时需要传入 feedId 用于埋点。淘宝直播业务必填。点播业务传 video ID。Weex video 组件传组件拿到的 JS URL。
 * isSelected: 内容是否为精选内容(BOOL)。可选。
 * anchorAccountId：直播间主播的用户 ID(NSString *)。业务接入方接入 TBMediaPlayerBundle 时需要传入 anchorAccountId 用于埋点。淘宝直播业务必填。
 * videoDefinition：视频清晰度(NSString *)。业务接入方接入 TBMediaPlayerBundle 时需要传入 videoDefinition 用于埋点。淘宝直播业务必填。
 * videoDuration：视频总时长(double)。点播业务接入方传入 videoDuration 用于视频缓存模块的策略选择。可选。
 * videoDurationLimitForCache：视频总时长限制(double)。点播业务接入方传入 videoDurationLimitForCache 用于视频缓存模块的策略选择，当视频总时长超过 videoDurationLimitForCache 时则不会走缓存逻辑。可选。
 * coverImage: 用户传入的封面图(UIImage *)。可选。
 * coverImageContentMode: 用户传入封面图的显示模式(UIViewContentMode)。搭配 coverImage 使用，默认为 UIViewContentModeScaleAspectFit。可选。
 * intervalOfPeriodicTimer: 播放器定时上报当前播放时间的间隔(CGFloat)。单位秒。不建议设置为小于 0.5 的值。默认 1。可选。
 * defaultFullScreenFeatureEnabled: 是否开启默认的全屏行为(BOOL)。默认 NO。可选。
 * logToken: 日志 Token(NSString *)。日志标识。用于业务层和播放器保持日志可寻。
 * usePlayerManager: 针对点播，是否使用播放器多实例管理器(BOOL)。将管理播放器多实例，并按需回收，实例上限默认4个，默认关闭；
 * useLivePlayerManager: 针对直播，是否使用播放器多实例管理器(BOOL)。将管理播放器多实例，并按需回收，实例上限默认2个，默认打开；
 * useOptimizedHEVC: 是否使用优化后的 H265 算法(BOOL)。
 * isUseProxy: 是否使用代理(BOOL)。
 * mediaSourceType: 直播推流端的类型(NSString *)。
 * spm: 业务传下来的 spm 信息(NSString *)。
 * disableForcedTBPlayer: BOOL, 是否允许内部强制把TBMPBPlayerTypeFFPlayer在内部改成成TBMPBPlayerTypeTBPlayer，默认会强制改掉，不需要时请设置YES
 *
 *
 * 以下选项仅在 playerType = TBMPBPlayerTypeFFPlayer or  TBMPBPlayerTypeTBPlayer 时有效：
 * videoToolbox：是否使用硬解(int64_t)。可选值：0；1。0：使用软解码；1：使用硬解码。默认为 1。可选。
 * timeout：播放器超时时间(int64_t)。单位微秒，仅支持 HTTP/HTTPS。默认为 10 * 1000 * 1000，即 10s。可选。
 * maxRefreshCountForTimeout：播放器超时情况重新刷新播放器的最大次数(int)。在初始化播放器时会使用该值；使用新的 URL 调用 refreshWithMediaURL... 接口刷新播放器时会重新使用该值。一旦成功连接播放源，该值即失效。默认为 1。可选。
 * maxLoadingTime：最大加载时间(int)。在初始化播放器时设置该值；使用新的 URL 调用 refreshWithMediaURL... 接口刷新播放器时会重新使用该值。只对直播场景(playScenairo = TBMPBPlayScenarioLive/TBMPBPlayScenarioLinkLive)并且自动播放时(autoplay = YES)有效。超过该时间没有渲染出视频首帧时将会刷新播放器。单位为秒。默认为 6。可选。
 * maxFps：最大帧率(int64_t)。默认为 30。可选。
 * frameDrop：是否开启丢帧(int64_t)。可选值：0；1。0：关闭丢帧；1：开启丢帧。默认 1。可选。
 * videoPictqSize：视频队列长度(int64_t)。默认为 3。可选。
 * videoToolboxMaxFrameWidth：最大支持屏幕宽度(int64_t)。默认为 1080。可选。
 * reconnect：是否开启重连(int64_t)。可选值：0；1。0：关闭重连策略；1：开启重连策略。默认 1。可选。
 * cdnIP: 根据 HTTP DNS 选择的较优 CDN IP(NSString *)。默认为 nil。可选。
 */
@property (copy, nonatomic) NSDictionary *extraConfig;

@end
