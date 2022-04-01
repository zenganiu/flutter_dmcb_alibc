//
//  TBMPBPlayerContext.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 09/09/2017.
//  Copyright © 2017 CX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TBMediaPlayerBundle/TBMPBPlayerConst.h>

@interface TBMPBPlayerContext : NSObject

@property (assign, nonatomic) NSTimeInterval lastPlaybackTime;
@property (assign, nonatomic) TBMPBPlayerStatus lastStatus;
@property (assign, nonatomic) BOOL shouldPlay; // 逻辑上是否应该播放。

@end
