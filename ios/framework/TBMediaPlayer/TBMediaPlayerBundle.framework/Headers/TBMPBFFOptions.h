//
//  TBMPBFFOptions.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 3/30/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBMPBFFOptions : NSObject // 'IJKFFOptions' Wrapper

@property (strong, nonatomic) id ijkFFOptions; // IJKFFOptions

@property (assign, nonatomic) BOOL showHudView;
@property (assign, nonatomic) int32_t playScenario; // 0: normal live; 1: link live; 2: playback.
@property (assign, nonatomic) BOOL shouldAutoplay;
@property (assign, nonatomic) BOOL loop;
@property (copy, nonatomic) NSString *cdnIP;
@property (assign, nonatomic) BOOL useOptimizedHEVC;
@property (assign, nonatomic) BOOL videotoolboxHEVC;
@property (assign, nonatomic) BOOL vtbHandleResolutionChange;

@property (copy, nonatomic) NSString *businessID; // 用于区别不同业务的埋点。比如：淘宝直播的 businessID 为 "TBLive"。
@property (copy, nonatomic) NSString *subBusinessType; // 业务细分类型。
@property (copy, nonatomic) NSString *videoChannel; // 视频业务承接渠道。
@property (copy, nonatomic) NSString *userID; // 用于埋点时区分用户。由业务方传入。
@property (copy, nonatomic) NSString *feedID; // 直播间 Feed ID。由业务方传入。
@property (assign, nonatomic) BOOL isSelected; // 内容是否为精选。
@property (copy, nonatomic) NSString *anchorAccountID; // 直播间主播的用户 ID。由业务方传入。
@property (copy, nonatomic) NSString *videoDefinition; // 视频清晰度。由业务方传入。
@property (copy, nonatomic) NSString *logToken; // 日志标识。
@property (copy, nonatomic) NSString *mediaSourceType;
@property (copy, nonatomic) NSString *spm;

@property (assign, nonatomic) BOOL isUseProxy;

@property (assign, nonatomic) BOOL playerShouldUpthrowImage;
@property (assign, nonatomic) BOOL playerShouldNotRenderAfterUpthrowImage;
@property (assign, nonatomic) int32_t renderType; // 默认为0，普通glView渲染，1为VR渲染
@property (assign, nonatomic) int32_t playerRenderOrientation; // 默认是0，表示UIInterfaceOrientationPortrait，1表示UIInterfaceOrientationLandscapeRight
@property (assign, nonatomic) int32_t maxnormalplay;
@property (assign, nonatomic) int32_t minnormalplay;
@property (assign, nonatomic) int32_t maxfastplay;

@property (assign, nonatomic) BOOL simpleMode;
@property (copy, nonatomic) NSString* expectedVideoInfo;
@property (copy, nonatomic) NSDictionary *extraConfig;

+ (instancetype)defaultPlayerOptions;

- (void)setFormatOptionValue:(NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:(NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:(NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:(NSString *)value forKey:(NSString *)key;

- (void)setFormatOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:(int64_t)value forKey:(NSString *)key;

- (void)setPlayScenarioOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setServerDispatchedOptionIntValue:(int64_t)value forKey:(NSString *)key;

- (NSDictionary *)getAllOptions;

@end
