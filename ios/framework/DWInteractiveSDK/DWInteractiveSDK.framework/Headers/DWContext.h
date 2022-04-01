//
//  DWContext.h
//  Pods
//
//  Created by jyi on 2016/12/6.
//
//

#import <Foundation/Foundation.h>

@class DWInstance;
@class DWHighPerformanceInstance;
@class DWAllNewHPInstance;
@class DWVideoFrontModel;
@class DWVideoResources;

@interface DWContext : NSObject

@property (nonatomic, weak) DWInstance *dwInstance;
@property (nonatomic, weak) DWHighPerformanceInstance *dwHPInstance;
@property (nonatomic, weak) DWAllNewHPInstance *dwAllNewHPInstance;
@property (nonatomic, weak) DWVideoFrontModel*      frontModel;
//只容许存储环境信息
@property (nonatomic, strong) NSMutableDictionary *properties;
@property (nonatomic, strong) NSDictionary* recommendVideos;
//Config
@property (nonatomic, assign) BOOL muted;
@property (nonatomic, assign) BOOL interactiveHidden;
@property (nonatomic, assign) BOOL onlyShowFullscreen;
@property (nonatomic, assign) float controlsViewTopMargin;
@property (nonatomic, assign) BOOL notAutoPlay;
@property (nonatomic, assign) BOOL hiddenPlayingIcon;
@property (nonatomic, assign) BOOL shownMuteBtn;

@property (nonatomic, copy) NSDictionary *outBizData;

@property (copy, nonatomic) NSDictionary *interactiveParms;

//fangying
@property (nonatomic, strong) NSMutableDictionary *parameters;
+ (BOOL) enableCacheWith:(NSString*)bizcode;
+ (BOOL) enableMediaCacheWith:(NSString*)bizcode;
+ (BOOL) enablePlayControlWith:(NSString*)bizcode;
+ (BOOL) enableH265ForMachine;
+ (BOOL) enablePlayControlServiceBackupLogicWith:(NSString*)bizcode;
+ (BOOL) deferPlayControlRequestWith:(NSString *)bizcode;


+ (NSString *)interactiveVideoPlayerCoreMode;
+ (BOOL)isPlayerCoreABTestEnabledForBusiness:(NSString *)bizcode;
+ (NSString *)playerCoreABTestBucket;
+ (NSDictionary *)getDWInteractiveSDKOrangeConfig;
+ (NSDictionary *)getTBMediaPlayerBundleOrangeConfig;
+ (BOOL)isFreeFlowGuideEnabledForBusiness:(NSString *)bizcode;

+ (void) setFullScreen:(BOOL)fullScreen;
+ (BOOL) fullScreen;
+ (void) startNetworkProxyServerOnce;
+ (void) initSDKEnvironment;

//UT
//使用过全屏
@property (nonatomic, assign) BOOL UTFull;
//完整播放过
@property (nonatomic, assign) BOOL UTComplete;
//视频时间
@property (nonatomic, assign) float UTVideoDuration;
//用户调用开始播放
@property (nonatomic, assign) NSTimeInterval userStartPlayTime;
//开始预加载时间
@property (nonatomic, assign) NSTimeInterval preloadStartTime;
//视频资源信息
@property (nonatomic, strong) DWVideoResources *videoResources;
//视频播放链路统一埋点标识
@property (nonatomic, strong) NSString *UTLogToken;

- (void)tLog:(NSString*)timingName msg:(NSString*)msg;

@end

