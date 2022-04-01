//
//  DWInteractiveViewController.h
//  DWInteractiveSDK
//
//  Created by jyi on 2016/10/13.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <DWInteractiveSDK/DWContext.h>
typedef NS_ENUM(NSInteger, DWHPVideoPlayerEvent) {
    DWHPVideoPlayerEventPrepared,
    DWHPVideoPlayerEventStartRendering,
    DWHPVideoPlayerEventFirstVideoFrameRendered,
    DWHPVideoPlayerEventPaused,
    DWHPVideoPlayerEventEnded,
    DWHPVideoPlayerEventTimeupdated,
    DWHPVideoPlayerEventError,
    DWHPVideoPlayerEventStalled,
    DWHPVideoPlayerEventInterrupted,
    DWHPVideoPlayerEventDataUserSEI,
    DWHPVideoPlayerEventDataNetworkTraffic,
    DWHPVideoPlayerEventWillBeRecycled,
    DWHPVideoPlayerEventException,
    DWHPVideoPlayerEventSeekingForward,
    DWHPVideoPlayerEventSeekingBackward,
    DWHPVideoPlayerEventViewTapped,
    DWHPVideoPlayerEventUnknown,
};

@interface DWHighPerformanceVideoController : UIViewController

-(void)play;
-(void)pause;
- (void)refresh;
-(void)stop;

@property (nonatomic, weak) DWContext *context;
@property (nonatomic, assign, readonly) BOOL isPlaying;
@property (nonatomic, copy) void (^DWHPVideoPlayerEventHandler)(DWHPVideoPlayerEvent event, NSDictionary* info);
@property (nonatomic, assign) CGRect frame;
@property (nonatomic, assign) BOOL loop;
@property (nonatomic, assign) BOOL muted;
@property (assign, readonly, nonatomic) BOOL isLoadingFromCache;
@property (copy, nonatomic) NSString* aspectMode;
@property (assign, readonly, nonatomic) NSTimeInterval duration;
@property (assign, nonatomic) NSTimeInterval currentTime;
@property (nonatomic, copy) NSString* url;
@property (nonatomic, assign) BOOL hidenMiniProgressView;
@property (nonatomic, readonly) CGSize videoSize;
@property (weak, readonly, nonatomic) UIView* playerCoreView;


@end
