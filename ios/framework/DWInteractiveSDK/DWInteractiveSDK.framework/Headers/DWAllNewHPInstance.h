//
//  DWAllNewHPInstance.h
//  Pods
//
//  Created by fernando on 2020/3/26.
//

#import <DWInteractiveSDK/DWVideoInfo.h>
#import <DWInteractiveSDK/DWInteractiveInfo.h>
#import <DWInteractiveSDK/DWDefine.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DWAllNewHPInstance : NSObject

typedef void(^onDWHPEventFired)(DWHPEvent event, NSDictionary* info);

- (instancetype) initWithVideoInfo:(DWVideoInfo*)videoInfo
                   interactiveInfo:(DWInteractiveInfo*)interactiveInfo
                           UTParms:(NSDictionary*)UTParms
                      eventHandler:(onDWHPEventFired)handler;

@property (nonatomic, strong) DWVideoInfo *videoInfo;

@property (nonatomic, strong) DWInteractiveInfo *interactiveInfo;

@property (nonatomic, strong) NSDictionary *UTParms;

@property (nonatomic, strong) NSDictionary *playerConfig;

@property (nonatomic, copy) void (^onDWHPEventFired)(DWHPEvent event, NSDictionary* info);

/**
 * 播放相关资源准备
 1. auoPlay: 必填，默认NO，即不自动播放；
 2. playScenario: 必填，0表示直播，1表示点播，2表示纯音频播放；默认是1，即点播；
 3. loop: 默认NO，即不循环播放；
 4. usePlayerManager: 选择是否使用播放器内核多实例管理，默认YES，即使用；
 5. useCustomVideoURL: 选择是否使用特殊转码的视频地址，默认NO，即不使用；
 6. useEGLRenderer: 选择是否在TaobaoPlayer下使用EGL渲染，默认NO，即不用EGL；
 7. useDefaultAVAudioSessionCategery: 选择是否使用播放器默认的AVAudioSessionCategery，默认YES，即播放器内部会主动设置AVAudioSessionCategery；
 8. disableTimeUpdate: 选择是否实时上报视频播放时间进度，默认为NO，即实时上报;
 9. disableAudio: 选择是否禁掉音频（禁掉音频，即播放器内核会禁止音频的解码和播放），默认为NO，即不禁音频；
 9. businessId: 业务ID，比如淘宝直播业务下传"TBLive"；
 10. subBusinessId: 子业务ID，比如淘宝直播下，频道页播放时用"LiveCard"，直播间播放时用"live"
 11.mute:默认NO，即不静音
 12.useInputUrl:默认NO，是否使用用户输入videoUrl进行播放，在videoID与URL同时设置时使用
 13.cache:默认NO，是否需要缓存，点播模式下在useInputUrl为YES时生效
 14.preDownloadBytes，默认1M，cache启用时进行预下载请求大小
 15.videoUrlResources，使用url进行播放时，播放播放地址列表
 16.experienceTrackExInfo，非必填，体验埋点补充信息，NSDICTIONARY类型，需保证与播放器内部已有埋点不同名，详见《播放器埋点》
 *
 */
- (void)setupWithPlayerConfig:(NSDictionary*)config;

/**
 * 视频播放，
 * 注意：非自动播放时，必须在至少收到DWHPVideoPlayerServiceReady事件后才开始调用videoPlay
 **/
- (void)videoPlay;

/**
 * 视频暂停
 **/
- (void)videoPause;

- (void)videoRefresh;

/**
 * dealloc之前调用此接口释放依赖和资源，重复使用需要调用setup (暂时还不支持复用)
 */
- (void) destroy;

-(BOOL) isVideoViewPlaying;

- (void)UTBusinessSwitchWithType:(NSString *)type extraParam:(NSDictionary *)params;

#pragma mark - common
/**
 * 设置页面的frame
 **/
@property (nonatomic, assign) CGRect frame;

/**
 *
 **/
@property (nonatomic, readonly) UIView  *interactiveView;

/*
 * 是否循静音
 */
@property (nonatomic, assign) BOOL muted;
//@property (nonatomic, readonly) UIViewController *interactiveViewController;

/**
 * 画面填充模式，目前支持aspectFit、aspectFill、fill三个字段，对视频和封面图都生效
 **/
@property (nonatomic, copy) NSString* aspectMode;

/**
 * 是否隐藏mini进度条，默认隐藏
 **/
@property (nonatomic, assign) BOOL hidenMiniProgressView;

/**
 * 永久隐藏控制层(空实现，不做任何动作)
 */
@property (nonatomic, assign) BOOL controlsViewHidden;

/**
 * 原始视频尺寸（宽*高）
 */
@property (nonatomic, readonly) CGSize videoSize;

/**
 * 播放器内核View
 **/
@property (weak, readonly, nonatomic) UIView* playerCoreView;
/**
 * 获取当前视频总时长
 * onVideoPrepared后此值才有效
 *
 * @return 返回当前视频总时长（秒）
 */
@property (assign, nonatomic) CGFloat videoDuration;

/**
 *  获取当前视频播放的时间
 *
 *  @return 当前视频播放到第几秒
 */
- (CGFloat)getVideoCurrentTime;

/**
 *  视频播放时要seek到第几秒
 *
 *  @param seekTime 单位秒
 */
- (void)videoPlaySeekTo:(CGFloat)seekTime;
/*
 * 是否循环播放
 */
@property (nonatomic, assign) BOOL loop;

@end

NS_ASSUME_NONNULL_END
