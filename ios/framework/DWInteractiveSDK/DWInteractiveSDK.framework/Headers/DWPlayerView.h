//
//  DWPlayerView.h
//  DWPlayerView
//
//  Created by Zhubicheng on 08/12/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <MediaPlayer/MediaPlayer.h>
#import <TBMediaPlayerBundle/TBMediaPlayerBundle.h>

#import <DWInteractiveSDK/DWSlider.h>
//#import <DWPlayerNotifyBar.h>
#import <DWInteractiveSDK/DWUtility.h>
#import <DWInteractiveSDK/DWPopLayerView.h>
#import <DWInteractiveSDK/DWFlowPromptView.h>
#import <DWInteractiveSDK/TBSVideoMenuView.h>
#import <DWInteractiveSDK/DWThumbnailView.h>
#import <DWInteractiveSDK/TBSVideoIconView.h>
//extern BOOL DWFlowPromptViewAllowToShow;

static const CGFloat ControllersBarHeight = 48;

@class DWPlayerView;
@class DWContext;
@class DWPlayerErrorView;
@class DWPlayerControlHUD;
@class DWThumbnailView;
@class DWError;
@class TBSVideoIconModel;

// 内容导航锚点数据模型
@interface DWAnchorModel : NSObject

@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, copy) NSString *type; // item-小卡；coupon-优惠劵；alipayCoupon-红包
@property (nonatomic, assign) BOOL enableAction;

@end

@protocol DWDanmakuDelelgate <NSObject>

- (void)sendDanmakuWithContent:(NSString*)content;

- (void)showDanmakuView;

- (void)hideDanmakuView;

@optional

- (void)sendDanmakuBtnClicked;

@end


@protocol DWPlayerViewDelegate <NSObject>

@optional
- (void)playerViewWillPlay:(DWPlayerView *)playerView;
- (void)playerViewWillPause:(DWPlayerView *)playerView;
- (void)playerViewDidPause:(DWPlayerView *)playerView;
- (void)playerViewWillResume:(DWPlayerView *)playerView;
- (void)playerViewWillEndPlaying:(DWPlayerView *)playerView;
- (void)playerViewDidEndPlaying:(DWPlayerView *)playerView;
- (void)playerViewWillStartLoading:(DWPlayerView *)playerView;
- (void)playerViewWillEndLoading:(DWPlayerView *)playerView;
- (void)playerViewTimeSliderStartDrag:(DWPlayerView *)playerView;
- (void)playerViewTimeSliderFinishDrag:(DWPlayerView *)playerView;
//- (void)playerView:(DWPlayerView *)playerView timeSliderValueDidChanged:(CGFloat)second;
- (void)playerViewShowFailView:(DWPlayerView *)playerView error:(NSError*)error;
- (void)playerViewShowPromptView:(DWPlayerView *)playerView;
- (void)playerViewStalled:(DWPlayerView *)playerView;
- (void)playerViewTimeChanged:(double)time;
- (void)playerViewPreload:(DWPlayerView *)playerView;
- (void)playerViewDidTap:(DWPlayerView *)playerView;
- (void)playerViewWillResignActive:(DWPlayerView *)playerView;
- (void)playerViewWillBecomActive:(DWPlayerView *)playerView;
- (void)playerViewControlBarHidden:(BOOL)hidden;
- (void)playerLoadedProgressChanged:(CGFloat)progress;
- (void)playerViewWillShowFreeTip:(DWPlayerView *)playerView;
- (void)playerViewWillHideFreeTip:(DWPlayerView *)playerView;
- (void)playerView:(DWPlayerView *)playerView firstVideoFrameRendered:(NSDictionary *)info;
/**
 *  用户手动触发play，互动层埋点用
 *
 */
- (void)playerViewDidTapToPlay:(DWPlayerView *)playerView;
- (void)playerViewDidTapToPause:(DWPlayerView *)playerView;

- (void) fullscreenButtonClicked;
- (void) muteBtnClicked;

//fangying
- (void)startToHideView;
- (void)startToShowView;

- (void)playerViewNetWorkErrorViewTapToRetry;
    
-(void)hiddenThumbnailPlayBtn:(BOOL)hidden;

@end

extern const NSInteger DWPlayerViewActivityIndicatorPriority;
extern const NSInteger DWPlayerViewErrorIndicatorPriority;

//extern NSString * const kDWPlayerViewNotReachableMessage;
extern NSString * const kDWPlayerViewWWANMessage;
extern NSString * const kDWPlayerViewWWANMessage2;
extern NSString * const kDWPlayerViewFreeFlowMessage;

typedef NS_ENUM (NSInteger, DWPlayerStatus) {
    DWPlayerStatusUnknown = 0,
    DWPlayerStatusReady,
    DWPlayerStatusWaiting,
    DWPlayerStatusPlaying,
    DWPlayerStatusPaused,
    DWPlayerStatusError,
    DWPlayerStatusEnd,
};

typedef NS_ENUM(NSInteger, DWPlayerViewNetworkStatus) {
    DWPlayerViewNetworkStatusUnknown = 0,
    DWPlayerViewNetworkStatusNotReachable,
    DWPlayerViewNetworkStatusWiFi,
    DWPlayerViewNetworkStatusWWAN
};

typedef void(^DWPlayerViewBigPlayButtonClickHandler)(UIButton *bigPlayButton);

#define DWAVPlayerImageLoader_ADAPTER @"DWAVPlayerImageLoader_ADAPTER"

//#define DWAVPlayerVolumeHasBeenChangedUserDefaultKey @"DWAVPlayerVolumeHasBeenChangedUserDefaultKey"

@interface DWPlayerView : DWPopLayerView

@property (nonatomic, strong) DWContext *context;

@property (strong, nonatomic) NSURL *videoURL;
@property (assign, nonatomic) NSInteger controlsTimeoutPeriod;
@property (nonatomic, assign) BOOL exitFullScreenWhenFinish;
@property (nonatomic, assign) BOOL shouldShowCloseButton;
// default NO
@property (nonatomic, assign) BOOL disableCache;
// default YES
@property (nonatomic, assign) BOOL preload;

@property (nonatomic, assign) BOOL normalScreenAndNotMutedForGestureSeekOperation;

//视频播放时长，指视频实际播放自然时长
@property (nonatomic, assign) NSTimeInterval playTime;
//视频播放时长，指视频实际播放自然时长，播放完成后重新计算此时间
@property (nonatomic, assign) NSTimeInterval playOnceTime;

/**
 *  解决详情自动播放和直播小窗的冲突问题
 */
@property (nonatomic, assign) BOOL allowWiFiAutoPlay;

/**
 *  自定义按钮，默认隐藏。
 */
- (TBSVideoIconView *) customBtn;
@property (nonatomic, assign) BOOL showCustomBtn;
@property (nonatomic, assign) BOOL hasGoods;
@property (nonatomic, assign) BOOL showLikeBtn;
@property (nonatomic, assign) BOOL showReport; // 是否展示举报
@property (nonatomic, assign) BOOL isMenuViewShow;

//弹幕按钮
@property (nonatomic, assign) BOOL  showDanmakuBtn;
@property (nonatomic, assign) BOOL  showSendDanmakuBtn;

/**
 * 隐藏视频控制栏上的全屏按钮
 */
@property (nonatomic, assign) BOOL hideFullScreenButton;

/**
 *  详情需求：需要自定义大播放按钮的处理事件,不传默认处理为播放
 */
@property (nonatomic, copy) DWPlayerViewBigPlayButtonClickHandler bigPlayButtonHandler;

@property (weak, nonatomic) id<DWPlayerViewDelegate> delegate;
@property (nonatomic, weak) id<DWDanmakuDelelgate> danmakuDelegate;
@property (nonatomic, weak) id<TBSVideoMenuActionProtocol> menuActionDelegate;
/**
 * 视频是否load成功，是否可以读取视频宽高等数据
 */
@property (nonatomic, assign) BOOL playReady;

// UI
@property (nonatomic, strong) UIView      *controlsView;
@property (nonatomic, strong) UIImageView      *headerBar;
@property (nonatomic, strong) UIView *headerBarContentView;
@property (nonatomic, strong) DWThumbnailView *thumbnailView;
//@property (nonatomic, strong) UIImageView *thumbnailImageView;
@property (nonatomic, strong) UIButton      *danmakuBtn;
@property (nonatomic, strong) UIView        *rightInteractiveView;
@property (nonatomic, strong) TBSVideoIconView    *customBtn;
@property (nonatomic, strong) UIButton    *menuBtn;
@property (nonatomic, strong) TBSVideoIconView    *likeBtn;
@property (nonatomic, strong) TBSVideoMenuView *menuView;
@property (nonatomic, strong) UIButton *menuFullscreenBgBtn;
//@property (nonatomic, strong) UILabel*     goodsListLabel;
@property (nonatomic, strong) TBSVideoIconView*    sendDanmakuBtn;

@property (nonatomic, strong) UIView      *indicatorOverlayView;
@property (nonatomic, strong) UIButton    *closeButton;
@property (nonatomic, strong) UIView      *controllersBar;
@property (nonatomic, strong) DWSmallProgressView *smallProgressView;
@property (nonatomic, strong) UIButton *muteBtn;

@property (nonatomic, strong) UIButton *freeFlowButton;
@property (nonatomic, copy) NSString *freeFlowURL;

// UI Config
@property (nonatomic, assign) BOOL miniProgressViewHidden;
@property (nonatomic, assign) BOOL miniProgressAnchorHidden;
@property (nonatomic, assign) BOOL networkErrorViewHidden;
@property (nonatomic, assign) BOOL playErrorViewHidden;
@property (nonatomic, assign) BOOL toastViewHidden;
@property (nonatomic, assign) BOOL gestureViewHidden;
@property (nonatomic, assign) BOOL disableFreeFlowButton;

// Header Bar
@property (nonatomic, strong) UIButton    *landscapeBackBtn;

// controls
@property (strong, nonatomic) UIButton   *playButton;
@property (strong, nonatomic) DWSlider *progressIndicator;
@property (strong, nonatomic) UIButton   *fullscreenButton;
@property (strong, nonatomic) UIPanGestureRecognizer *panGesture;
@property (strong, nonatomic) UITapGestureRecognizer *tapGesture;
@property (strong, nonatomic) UILabel *playerTimeLabel;
@property (strong, nonatomic) UILabel *playerTimeLabel2;
@property (strong, nonatomic) UIButton *playRateButton;
@property (strong, nonatomic) DWPlayerControlHUD *controlHUD;

@property (nonatomic, strong) DWPlayerErrorView *activityIndicator;
@property (nonatomic, strong) DWFlowPromptView *promptView;

// status
/**
 * 切换全屏和退出全屏时，是否需要动画
 * default = YES
 **/
//@property (nonatomic, assign) BOOL switchScreenAnimation;
//@property (nonatomic, assign) BOOL fullscreen;
@property (nonatomic, assign) BOOL isDragingProgress;
@property (nonatomic, assign) BOOL isComplete;

@property (nonatomic, assign) DWPlayerViewNetworkStatus networkStatus;

@property (nonatomic, assign) NSTimeInterval totalTime;
@property (nonatomic, assign) BOOL isPlaying;
@property (nonatomic, assign) Float64 playNeedSeekTime;
@property (nonatomic, assign) CGFloat playNeedSeekProgress;


/**
 *  内部使用
 */
@property (nonatomic, assign) BOOL allowShowControls;
@property (nonatomic, assign) BOOL allowShowIndicator;

/**
 *  networkHandler
 */
@property (nonatomic, copy) void(^networkHandler)(DWPlayerViewNetworkStatus status);


/**
 *  UT see:http://tbdocs.alibaba-inc.com/pages/viewpage.action?pageId=283607984
 */
/**
 *  以下可以获取到
 */
@property (nonatomic, copy) NSString *dimensions;
@property (nonatomic, copy) NSString *volume;
@property (nonatomic, copy) NSString *URL;
/**
 *  以下暂时没有
 */
@property (nonatomic, copy) NSString *playDelayTime;
@property (nonatomic, copy) NSString *mimeType;
@property (nonatomic, copy) NSString *connectionSpeed;
@property (nonatomic, copy) NSString *droppedFrames;


//@property (nonatomic, strong) DWFlowPromptView* landScapeNetworkErrorView;
//@property (nonatomic, strong) DWFlowPromptView* portraitNetworkErrorView;

//@property (nonatomic, strong) DWFlowPromptView* portraitFlowPromptView;
//@property (nonatomic, strong) DWFlowPromptView* landScapeFlowPromptView;

@property (nonatomic, assign) BOOL isOperating; // 下拉菜单动画，防止快速点击
@property (nonatomic, assign) BOOL isHideNotWiFiToast; // 是否隐藏非WiFi提醒

@property (nonatomic, assign) CGFloat toastTopMargin;

// 为详情增加插入右侧按钮坑位，upLikeView布局在likeBtn上方，downLikeView布局在lkeBtn下方
@property (nonatomic, strong) UIView *upLikeView;
@property (nonatomic, strong) UIView *downLikeView;

/**
 * 为详情增加插入右侧按钮坑位，所有按钮居中展示的功能
 * @params up 在点赞按钮的上方/下方
 * @params layout 加入按钮后是否立刻布局，如果同时加入两个按钮建议第一个传NO，第二个传YES，两个按钮加完后一起布局，否则会影响性能。
**/
- (void)addViewToRightInteractiveView:(UIView *)view upOfLikeBtn:(BOOL)up needLayout:(BOOL)layout;

- (void)addIconWithItems:(NSArray<TBSVideoIconModel *> *)iconModel;

- (void)play;

/**
 *  解决详情自动播放和直播小窗的冲突问题。
 */
- (void)pause;
- (void)stop;

- (void)loadVideo;

- (void) refreshPlayer;

- (void)seekToProgress:(CGFloat)progress;
- (void)seekToTime:(CGFloat)time;

- (void)setBufferTintColor:(UIColor *)tintColor;

- (void)showPromptView:(DWError*)error retryBlock:(dispatch_block_t)retryBlock;
- (void)showErrorPromptView:(DWError *)error retryBlock:(dispatch_block_t)retryBlock;
- (void)showNetworkPromptView;
- (BOOL)promptViewHidden;

- (void)showIndicatorView:(UIView *)indicator withPriority:(NSInteger)priority;
- (void)hideIndicatorView:(UIView *)indicator;

- (void)showToast:(NSString *)toast inView:(UIView *)view dismissAfterSeconds:(NSTimeInterval)seconds delayTime:(NSTimeInterval)delayTime;

/**
 *  注册是否需要缓存机制, 手淘忽略，自动走orange配置，默认配置为true
 */
+ (void)registerConfigWithClass:(id)class;
/**
 *  注册获取GIF动画的adapter，手淘忽略
 *
 */
+ (void)registerImageLoaderWithClass:(id)class;

/**
 *  设置内容导航的锚点信息
 */
- (void)setupAnchorNaviView:(NSArray<DWAnchorModel *> *)models;

@property (nonatomic, assign) TBMPBPlayerError playerErrorCode;

@property (nonatomic, weak) TBMPBPlayerView *videoView;

@property (nonatomic, strong) NSDateFormatter *dateFormatter;

@property (nonatomic, assign) BOOL seeking;

@property (nonatomic, strong) NSMapTable *indicatorViews;
@property (nonatomic, strong) UIView *currentIndicatorView;

@property (nonatomic, assign) DWPlayerStatus playerStatus;

@property (nonatomic, assign) DWViewMode viewMode;

@property (nonatomic, assign) BOOL enterForegroundShouldPlay;

@property (nonatomic, strong) MPVolumeView *volumeView;

@property (nonatomic, weak) UIView*         customView;
@property (nonatomic, strong) UISlider *volumeViewSlider;

//@property (nonatomic, strong) NSTimer *fadeInVolumeTimer;

@property (nonatomic, strong) NSTimer *controlsTimer;

@property (nonatomic, assign) BOOL loadingHidden;

- (void) updateCustomLayout;

//- (void)showFlowPromptView;
//- (void)hideFlowPromptView;
//- (BOOL)flowPromptViewisHidden;

- (void)danmakuBtnClick;

- (void)updateVideoFrontViewWithData:(id)data;

- (void) showSmallProgressView;
- (void) hideSmallProgressView;

- (void)debugHUD:(UIGestureRecognizer *)recognizer;

- (void) hideBaseControllers;
- (void) showBaseControllers;

- (void)changeDanmaBtn:(BOOL)selected;

- (void)showThumbnailImageView;
- (void)hideThumbnailImageView;

/**
 *  聚划算用，隐藏时间标签，默认不隐藏
 */
@property (nonatomic, assign) BOOL shouldHideTimeLabel DEPRECATED_MSG_ATTRIBUTE("应该没人用了，两个版本后删除。");

@end
