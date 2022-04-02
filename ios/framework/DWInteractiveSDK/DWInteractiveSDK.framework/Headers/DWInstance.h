//
//  DWInstance.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/5.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <DWInteractiveSDK/DWVideoInfo.h>
#import <DWInteractiveSDK/DWInteractiveInfo.h>
#import <DWInteractiveSDK/DWPlayer.h>
#import <DWInteractiveSDK/DWPlayerLifecycleProtocol.h>
#import <DWInteractiveSDK/DWLikeServiceProtocol.h>
#import <DWInteractiveSDK/TBIctAddWeexCallbackProtocol.h>
@class TBSVideoIconModel;

@protocol DWInteractiveSDKProtocol <NSObject>

- (void)handleLikeStatusChange:(NSNumber*)bLike;

- (void)handleAttentionStatusChange:(NSNumber*)bAttention;

@end

@interface DWInstance : NSObject

#pragma mark - lifecycle

/**
 * 不需要互动，interactiveInfo传nil
 */
- (instancetype) initWithVideoInfo:(DWVideoInfo*)videoInfo
                   interactiveInfo:(DWInteractiveInfo*)interactiveInfo
                           UTParms:(NSDictionary*)UTParms;

- (instancetype) initWithVideoInfo:(DWVideoInfo*)videoInfo
                   interactiveInfo:(DWInteractiveInfo*)interactiveInfo
                           UTParms:(NSDictionary*)UTParms
                                playerConfig:(NSDictionary *)config;

@property (nonatomic, strong) DWVideoInfo *videoInfo;

@property (nonatomic, strong) DWInteractiveInfo *interactiveInfo;

@property (nonatomic, strong) NSDictionary *UTParms;

/*
 * 初始化完成后，或者destory后设置完参数，调用此接口
 */
- (void) setupNotAutoPlay;

/**
 * dealloc之前调用此接口释放依赖和资源，重复使用需要调用setup (暂时还不支持复用)
 */
- (void) destroy;

#pragma mark - common

+ (NSString*)getSDKVersion;

/**
 * 设置页面的frame
 **/
@property (nonatomic, assign) CGRect frame;

/**
 *
 **/
@property (nonatomic, readonly) UIView  *interactiveView;
@property (nonatomic, readonly) UIViewController *interactiveViewController;
@property (nonatomic, strong) NSDictionary *playerConfig;
/**
 * 视频互动数据成功回调
 **/
@property (nonatomic, copy) void (^onSuccess)(UIView *);

/**
 * 视频互动数据失败回调
 **/
@property (nonatomic, copy) void (^onError)(NSError *error);

/**
 * 视频从全屏返回回调
 **/
@property (nonatomic, copy) void (^onBackToNormalScreen)();

#pragma mark - video

@property (weak, nonatomic) id<DWPlayerLifecycleProtocol> lifecycleDelegate;

/**
 *  控制是否需要在播放结束后退出全屏,默认不需要
 *  请先添加interactiveView作为subView和设置frame，并在调用requestInteractiveVideo之前设置，否则以下属性会有使用问题
 */
@property (nonatomic, assign) BOOL shouldExitFullScreenWhenComplete;

/**
 *  控制是否需要在播放结束后显示封底,默认不需要
 *  请先添加interactiveView作为subView和设置frame，并在调用requestInteractiveVideo之前设置，否则以下属性会有使用问题
 */
@property (nonatomic, assign) BOOL backCoverDisplay;

/**
 *  是否显示右上角关注、进店等按钮
 */
@property (nonatomic, assign) BOOL rightMixBtnHiden;

/**
 * 画面填充模式，目前支持aspectFit、aspectFill、fill三个字段
 **/
@property (nonatomic, copy) NSString* aspectMode;

/**
 * 切换全屏和退出全屏时，是否需要动画
 * default = YES
 **/
//@property (nonatomic, assign) BOOL switchScreenAnimation;

/**
 * 设置视频是要全屏播放还是半屏播放
 *  请先添加interactiveView作为subView和设置frame，并在调用requestInteractiveVideo之前设置，否则以下属性会有使用问题
 **/
@property (nonatomic, assign) BOOL fullScreen;

/**
 *  设置视频是否隐藏close按钮,默认不隐藏; 而如果直接使用TBAVPlayerView，则是隐藏的
 *  请先添加interactiveView作为subView和设置frame，并在调用requestInteractiveVideo之前设置，否则以下属性会有使用问题
 */
@property (nonatomic, assign) BOOL needHideCloseButton;

/**
 *  设置视频的封面图
 *  请先添加interactiveView作为subView和设置frame，否则以下属性会有使用问题
 */
@property (nonatomic, strong) UIImage *thumbnailImage;

/**
 *  封面图的View
 *  用来自定义业务方需求
 */
@property (nonatomic, readonly) UIImageView *thumbnailImageView;

/**
 * 控制显示隐藏宝贝列表按钮
 * default = NO
 */
@property (nonatomic, assign) BOOL goodsListBtnHidden;

/**
 * 控制显示隐藏宝贝列表按钮
 * default = NO
 */
@property (nonatomic, assign) BOOL goodsListBtnFullScreenHidden;
/**
 * 控制小屏时显示隐藏喜欢按钮
 * default = YES
 */
@property (nonatomic, assign) BOOL likeBtnHidden;

/**
 * 控制大屏时显示隐藏喜欢按钮
 * default = YES
 */
@property (nonatomic, assign) BOOL likeBtnFullScreenHidden;
/**
 * 控制显示隐藏举报
 * default = YES
 */
@property (nonatomic, assign) BOOL reportHidden;

/**
 * 播放器静音按钮, default = NO
 */
@property (nonatomic, assign) BOOL mutedBtnDisplay;
//是否开启弹幕功能
@property (nonatomic, assign) BOOL  danmakuHidden;


/**
 * 互动隐藏, default = NO
 */
@property (nonatomic, assign) BOOL interactiveHidden;

/**
 * 隐藏视频控制栏上的全屏按钮
 */
@property (nonatomic, assign) BOOL hideFullScreenButton;

/*
 * 全屏下点击返回按钮，不进入详情页面。default = NO
 */
@property (nonatomic, assign) BOOL onlyShowFullscreen;

/*
 * 业务方是否需要封面图。请在调用setUp之前设置。 defalut = NO
 */
@property (nonatomic, assign) BOOL  needVideoFrontView;

/*
 * 隐藏SmallBar时显示的倒计时组件
 */
@property (nonatomic, assign) BOOL hiddenPlayingIcon;

/*
 * 静默下显示打开声音的按钮
 */
@property (nonatomic, assign) BOOL shownMuteBtn;

/*
 * For 详情定制。请在setUp之后调用，removeView后请set成nil（通知我去显示全屏按钮）
 */
@property (nonatomic, weak) UIView*         customView;

/*
 * 互动SDK对外protocol接口
 */
@property (nonatomic, weak) id<DWInteractiveSDKProtocol> interactiveDelegate;

/*
 * weex组件对外protocol接口，提供给GoHi，给他weexView自己处理
 */
@property (nonatomic, weak) id<TBIctAddWeexCallbackProtocol> addWeexCallbackDelegate;

/*
 * 隐藏网络错误提示
 */
@property (nonatomic, assign) BOOL networkErrorViewHidden;

/*
 * 隐藏播放器错误提示
 */
@property (nonatomic, assign) BOOL playErrorViewHidden;

/*
 * 隐藏所有toast显示
 */
@property (nonatomic, assign) BOOL toastHidden;

/*
 * 隐藏所有手势操作显示
 */
@property (nonatomic, assign) BOOL gestureViewHidden;

/*
 * 是否关闭免流按钮展示逻辑。
 */
@property (nonatomic, assign) BOOL disableFreeFlowButton;

/*
 * 视频控制栏高度
 */
@property (nonatomic, readonly) CGFloat controlBarHeight;

/**
 * 隐藏封面图上的播放按钮
 * setup之后调用此接口
 */
@property (nonatomic, assign) BOOL thumbnailPlayBtnHidden;

/**
 * 永久隐藏控制层，用户点击视频区域也不会显示控制层
 */
@property (nonatomic, assign) BOOL controlsViewHidden;

/**
 * weex发起点赞，点赞成功后的回调
 */
@property (nonatomic, copy) DWLikeServiceComplete handleLikeStatus;
/**
 * 开启小窗模式
 */
@property (nonatomic, assign) BOOL floating;

/**
 * 对外透出全屏按钮
 */
@property (nonatomic, weak) UIButton *fullscreenButton;

/**
 * 显示播放器的控制层并设置几秒后隐藏
 * delay 设置为0，显示后不自动隐藏
 */
- (void) showControlBarWithDelay:(NSTimeInterval)delay;

/**
 * 延迟几秒后隐藏播放器的控制层
 * delay 设置为0，立即隐藏
 */
- (void) hideControlBarWithDelay:(NSTimeInterval)delay;

/**
 *  临时暴露，后续优化
 *
 */
- (DWPlayer*) player;

/**
 * 视频停止
 **/
//TODO 这个接口不好用了
- (void)videoStop;

/**
 * 获取当前视频总时长
 * onVideoPrepared后此值才有效
 *
 * @return 返回当前视频总时长（秒）
 */
- (CGFloat)videoDuration;

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

/**
 * 添加/删除自定义封面
 */
- (void) addCoverView:(UIView*)view;
- (void) removeCoverView:(UIView*)view;

/**
 * 加入购物车
 */
- (void)addCart:(NSDictionary *)itemInfo;
/**
 * 暴露给直接进入视频全屏页的需求用，在context里面加个环境变量标识是否是打开直接进入全屏页
 */
- (void)setDWInstanceFromFullScreen:(BOOL)isFromFullScreen;
/**
 * 取消点赞请求，暴露给container全屏页使用
 */
- (void)requestCancleLike:(DWLikeServiceComplete) completionBlock;
/**
 * 点赞请求，暴露给container全屏页使用
 */
- (void)requestAddLike:(DWLikeServiceComplete) completionBlock;
/**
 * 更新点赞状态
 */
- (void)updateLikeButton:(BOOL)like num:(NSInteger)num;

- (void)queryAliBaoCardFreeFlow:(NSString *)bizCode result:(void (^)(BOOL isSuccess, NSString *code, NSString *returnDesc))result;
- (BOOL)isChinaUnicom;

#if !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
/**
 * weex处理点赞事件
 */
- (void)handleWeexLikedOperation:(BOOL)bliked callback:(DWLikeServiceComplete)completionBlock;

/**
 * weex处理发弹幕事件
 */
- (void)handleWeexSendDanma:(void (^)(BOOL))complete;

/**
 * weex调用关注功能入口
 */
- (void)handleWeexAddFollow:(void(^)(BOOL success))complete;

/**
 * 设置weex组件显示白名单
 * 在调用DWInstance的setupNotAutoPlay和setUp方法之前设置
 */
- (void)addWhiteWeexCmpList:(NSArray *)list;

/**
 * 设置全屏weex组件显示白名单
 * 在调用DWInstance的setupNotAutoPlay和setUp方法之前设置
 */
- (void)addFullScreenWeexCmpList:(NSArray *)list;

/**
 * 设置隐藏外互动的weex组件白名单
 * 在调用DWInstance的setupNotAutoPlay和setUp方法之前设置
 */
- (void)addHideOuterViewWeexCmpList:(NSArray *)list;

/**
 * weex组件消失回调
 */
- (void)onWXCmpDismiss:(NSString *)source;

/**
 * 设置weex组件显示位置
 * 在调用DWInstance的setupNotAutoPlay和setUp方法之前设置
 */
- (void)changeWeexCmpFrame:(NSArray *)list;

/**
 * 获取所有按钮的开关状态，给weex调用
 */
- (NSDictionary *)getAllInteractiveBtnStatus;
#endif // !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)

/**
 * 重新请求互动信息
 */
- (void)reloadInteractive;

/**
 * 为详情增加插入右侧按钮坑位，所有按钮居中展示的功能，此方法加入的view在右侧只有一个点赞按钮时才会显示，其他情况均不显示。
 * @params up 在点赞按钮的上方/下方
 * @params layout 加入按钮后是否立刻布局，如果同时加入两个按钮建议第一个传NO，第二个传YES，两个按钮加完后一起布局，否则会影响性能。
 * 注意view的frame是50*47，右侧互动按钮都是这个尺寸，麻烦按照我们的尺寸来。
 **/
- (void)addViewToRightInteractiveView:(UIView *)view upOfLikeBtn:(BOOL)up needLayout:(BOOL)layout;

- (void)addRightBarIconWithItems:(NSArray<TBSVideoIconModel *> *)iconModel;

/**
 * 配合套娃项目修改，打开新的视频
 **/

- (void)openNewVideo:(NSUInteger)level index:(NSUInteger)index;

/**
 * 配合套娃项目修改，分享套娃视频
 **/
- (void)share:(NSUInteger)level index:(NSUInteger)index type:(NSUInteger)type;

#if !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
- (void)postEventForWeexComponent:(NSString *)eventName params:(NSDictionary *)params;
#endif // !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)

/**
 * 配合套娃项目修改，套娃中的数据需要透传到业务方
 **/
- (NSDictionary *)taowaData;
- (NSDictionary *)shareData;

#if !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
/**
 * 提供给weex的接口在当前页面打开一个weex浮层
 **/
- (void)openWeexViewLayer:(NSDictionary *)weexData;

/**
 * 关闭weex组件
 **/
- (void)closeWeexViewLayer;

/**
 * 提供给weex的接口在业务页面打开一个weex浮层
 **/
- (void)openViewOnFullScreenLayer:(NSDictionary *)weexData;

/**
 * 关闭weex业务层组件
 **/
- (void)closeFullScreenLayer;

/**
 * weex触发，通知映像淘宝全屏页隐藏所有互动
**/
- (void)showAllInteractiveCmp:(BOOL)show;

/**
 * weex触发，在时间点之前主动隐藏weex
 **/
- (void)invisibaleWXCmp:(id)component;
#endif // !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)

// 强制隐藏视频右上角的logo
- (void)forceHideVideoLogoView;

// 强制隐藏播放进度条上的剩余时间展示;
- (void)forceHideVideoRemainTime;

// 业务设置播放器的背景图，设置了背景图后，播放区域的黑色部分用该图片覆盖。
- (void)setVideoBackgroundImage:(UIImage *)image;

- (void)UTBusinessSwitchWithType:(NSString *)type extraParam:(NSDictionary *)params;

#pragma mark - Private

@property (nonatomic, strong) DWContext *context;

@property (nonatomic, weak) DWPlayer *curPlayer;

- (void) quitFullScreen;

/**
 * 视频唤起登陆回调
 **/
@property (nonatomic, copy) void (^onReceivedLoginNotification)();

@property (nonatomic, assign) BOOL deferredRequestPlayControlService;


//- (instancetype) init __attribute__((unavailable("init not available, call initWithVideoInfo:interactiveInfo:UTParms")));

//+ (instancetype) new __attribute__((unavailable("new not available, call initWithVideoInfo:interactiveInfo:UTParms")));

- (void) openUrlAction:(NSString*)URL;

- (void)openUrlActionNotQuitFullScreen:(NSString*)URL;

//! 播前或者播后展示右侧的bar
- (void)predisplayInteractiveRightBar;
//! 即将播放时或暂停时恢复右侧bar的状态
- (void)restoreInteractiveRightBar;

- (void)requestPlayUrlWithAutoPlay:(BOOL)autoPlay;

#pragma mark - Deprecated

/**
 *  设置视频的播放模式
 *  请先添加interactiveView作为subView和设置frame，并在调用requestInteractiveVideo之前设置，否则以下属性会有使用问题
 */
typedef NS_ENUM(NSInteger, DWPlayerViewMode) {
    DWPlayerViewModeUnknown = 0,
    DWPlayerViewModeNormal,
    DWPlayerViewModeMute
};
@property (nonatomic, assign) DWPlayerViewMode playMode DEPRECATED_MSG_ATTRIBUTE("请使用拆分后的接口 muted, interactiveHidden");

/**
 *  外部关闭视频浮层时设置埋点状态
 */
- (void)change2VideoCloseUTStatus DEPRECATED_MSG_ATTRIBUTE("这个接口没工作过，不要了");

/**
 *  控制是否需要在播放结束后显示大的播放按钮,默认需要
 *  请先添加interactiveView作为subView和设置frame，并在调用requestInteractiveVideo之前设置，否则以下属性会有使用问题
 */
@property (nonatomic, assign) BOOL shouldShowBigPlayBtnWhenComplete DEPRECATED_MSG_ATTRIBUTE("现在控制栏的播放按扭，移到屏幕中间去了，所以这个接口没意义了");


/**
 * 此接口为了兼容老逻辑，不要使用此接口，请使用setupNotAutoPlay。
 * 初始化完成后，或者destory后设置完参数，调用此接口 (为了兼容老逻辑，setup后自动播放)
 */
- (void) setup;

/**
 * 不要使用，为了兼容老逻辑
 * Wi-Fi下普通视屏播放
 * 如果有直播小窗，SDK会禁止WiFi自动播放（新接入业务方不要使用此接口）
 **/
- (void)wifiStartVideo DEPRECATED_MSG_ATTRIBUTE("废弃");
@end

#import <DWInteractiveSDK/DWInstance+Interface.h>






