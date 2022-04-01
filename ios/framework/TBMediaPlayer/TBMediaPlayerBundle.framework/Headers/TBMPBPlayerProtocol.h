//
//  TBMPBPlayerProtocol.h
//  TBMediaPlayerBundle
//
//  在这里定义播放器的标准接口，所有对播放器的封装需要遵循该接口。
//
//  Created by qiufu on 9/7/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TBMediaPlayerBundle/TBMPBPlayerConst.h>
#import <TBMediaPlayerBundle/TBMPBPlayerOptions.h>

@protocol TBMPBPlayerProtocol <NSObject>

@required
#pragma mark - Lifecycle
- (instancetype)initWithMediaURL:(NSString *)url playerOptions:(TBMPBPlayerOptions *)options;

#pragma mark - Player Control
- (void)prepareToPlay; // 准备播放。如果 autoplay 为 YES，则调用该方法会直接播放；如果 autoplay 为 NO，则调用该方法后不会直接播放，需要接着调用 play 方法才会开始播放。
- (void)play;
- (void)pause;
- (void)stop;
- (void)shutdown;
- (void)prepareToRecycle;

@property (assign, nonatomic) BOOL muted;
@property (assign, nonatomic) TBMPBPlayerContentMode playerContentMode;
@property (assign, nonatomic) double preferredForwardBufferDuration;
@property (assign, nonatomic) float playbackRate;

- (void)clearBackgroundColor;

- (void)setConfig:(NSDictionary *)config; // 主要用于业务层向播放器在线下发动态配置，比如：Orange 配置。
- (void)setInfo:(NSDictionary *)info; // 主要用于业务层向播放器下发一些数据。

#pragma mark - Player Status
@property (assign, nonatomic) NSTimeInterval currentPlaybackTime;
@property (assign, readonly, nonatomic) NSTimeInterval duration;
@property (assign, readonly, nonatomic) BOOL isLoadingFromCache;
@property (assign, readonly, nonatomic) NSTimeInterval cacheDuration;
@property (assign, readonly, nonatomic) CGFloat cacheProgress;
@property (assign, readonly, nonatomic) CGRect videoRect;
@property (assign, readonly, nonatomic) CGSize naturalSize;
@property (assign, nonatomic) NSTimeInterval lastActiveTime;
- (BOOL)isPlaying;
- (BOOL)shouldPlayAfterLoadingOrSeeking;
- (NSTimeInterval)playableDuration;
- (UIImage *)snapshotImageAtCurrentTime;
- (NSDictionary *)playerStatusData;

#pragma mark - Player Event
@property (copy, nonatomic) void (^playerEventFired)(TBMPBPlayerEvent event, NSDictionary *info);
@property (copy, nonatomic) void (^playerDataPopped)(TBMPBPlayerData dataType, NSDictionary *data);

@optional
#pragma mark - VR Render
- (void)toggleUpthrowingCVPixelBufferRef:(BOOL)value;
- (void)toggleNotRenderAfterUpthrowingCVPixelBufferRef:(BOOL)value;
- (BOOL)hasNewVideoPixelBufferToDraw;
- (CVPixelBufferRef)copyCurrentVideoPixelBuffer;
@property (assign, nonatomic) UIInterfaceOrientation renderViewOrientation;

#pragma mark - ResolutionSwitch
-(void) switchVideoResolutionSmoothlyWithNewUrl:(NSString*)url;

@end
