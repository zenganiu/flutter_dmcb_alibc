//
//  TBMPBObserver.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 04/08/2017.
//  Copyright © 2017 CX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVAudioSession.h>

@class TBMPBObserver;

#pragma mark - TBMPBObserverDelegate
@protocol TBMPBObserverDelegate <NSObject>

- (void)observer:(TBMPBObserver *)observer willResignActive:(NSNotification *)notification;
- (void)observer:(TBMPBObserver *)observer didBecomeActive:(NSNotification *)notification;
- (void)observer:(TBMPBObserver *)observer didEnterBackground:(NSNotification *)notification;
- (void)observer:(TBMPBObserver *)observer willEnterForeground:(NSNotification *)notification;
- (void)observer:(TBMPBObserver *)observer audioSessionInterrupt:(NSNotification *)notification;

@end


// 为了规避 UT 会删除 UIView 的切前后台的 observer 的问题。
#pragma mark - TBMPBObserver
@interface TBMPBObserver : NSObject

@property (weak, nonatomic) id<TBMPBObserverDelegate> delegate;

@end
