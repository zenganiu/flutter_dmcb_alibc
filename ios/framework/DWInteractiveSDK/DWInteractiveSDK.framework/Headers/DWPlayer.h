//
//  DWPlayer.h
//  DWInteractiveSDK
//
//  Created by jyi on 2017/2/6.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DWInteractiveSDK/DWPlayerLifecycleProtocol.h>
#import <DWInteractiveSDK/DWPlayerView.h>
#import <DWInteractiveSDK/DWContext.h>
#import <DWInteractiveSDK/DWUtility.h>

@interface DWPlayer : NSObject

@property (nonatomic, strong) DWContext *context;

@property (nonatomic, assign) CGRect     frame;
@property (nonatomic, readonly) CGRect videoFrame;
@property (readonly, nonatomic) Float64  videoTime;

@property (nonatomic, assign) DWViewMode viewMode;

@property (nonatomic, strong) DWPlayerView   *playerView;
@property (nonatomic, assign) BOOL progressDraging;

@property (nonatomic, weak) id<DWPlayerLifecycleProtocol> delegate;

//@property (nonatomic, assign) BOOL wifiNetwork;
@property (nonatomic, strong) NSString *videoURL;

@property (nonatomic, assign) BOOL loop;
@property (nonatomic, assign) BOOL thumbnailPlayBtnHidden;

- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)playing;
- (NSTimeInterval)currentVideoTime;
- (void)seekTo:(CGFloat)progress;
- (void)closeVideo;

//@property (nonatomic, assign) BOOL fullscreen;

- (void)setExitFullScreenWhenComplete:(BOOL)shouldExit;

@property (nonatomic, assign) BOOL hidenCloseBtn;

- (void)showToast:(NSString *)toast;

- (void)setThumbnailImage:(UIImage *)image;

@end






