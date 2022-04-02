/*
 * IJKFFOptions.h
 *
 * Copyright (c) 2013-2015 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import <Foundation/Foundation.h>

typedef enum IJKFFOptionCategory {
    kIJKFFOptionCategoryFormat = 1,
    kIJKFFOptionCategoryCodec  = 2,
    kIJKFFOptionCategorySws    = 3,
    kIJKFFOptionCategoryPlayer = 4,
} IJKFFOptionCategory;

// for codec option 'skip_loop_filter' and 'skip_frame'
typedef enum IJKAVDiscard {
    /* We leave some space between them for extensions (drop some
     * keyframes for intra-only or drop just some bidir frames). */
    IJK_AVDISCARD_NONE    =-16, ///< discard nothing
    IJK_AVDISCARD_DEFAULT =  0, ///< discard useless packets like 0 size packets in avi
    IJK_AVDISCARD_NONREF  =  8, ///< discard all non reference
    IJK_AVDISCARD_BIDIR   = 16, ///< discard all bidirectional frames
    IJK_AVDISCARD_NONKEY  = 32, ///< discard all frames except keyframes
    IJK_AVDISCARD_ALL     = 48, ///< discard all
} IJKAVDiscard;

struct IjkMediaPlayer;

@interface IJKFFOptions : NSObject

+ (IJKFFOptions *)optionsByDefault;

- (void)applyTo:(struct IjkMediaPlayer *)mediaPlayer;

- (void)setOptionValue:(NSString *)value
                forKey:(NSString *)key
            ofCategory:(IJKFFOptionCategory)category;

- (void)setOptionIntValue:(int64_t)value
                   forKey:(NSString *)key
               ofCategory:(IJKFFOptionCategory)category;


- (void)setFormatOptionValue:(NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:(NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:(NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:(NSString *)value forKey:(NSString *)key;
- (int64_t)getPlayerOptionValueWithKey:(NSString*)key;

- (void)setFormatOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:(int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:(int64_t)value forKey:(NSString *)key;

-(void)setServerDispatchedIntValue:(int64_t)value forKey:(NSString*)key;
- (int64_t)getServerDispatchedOptionIntValueForKey:(NSString *)key;

- (void)setPlayScenarioOptionIntValue:(int64_t)value forKey:(NSString *)key;

@property (assign, nonatomic) BOOL showHudView;
//@property (assign, nonatomic) BOOL isLive; // Deprecated, use 'playScenario' to mark media type.
@property (assign, nonatomic) int32_t playScenario; // 0: normal live; 1: link live; 2: playback.
@property (copy, nonatomic) NSString *cdnIP;
@property (strong, nonatomic, readonly) NSMutableDictionary *playScenarioConfig; // 与 playScenario 对应的播放器参数配置。
@property (assign, nonatomic) BOOL shouldAutoplay;
@property (assign, nonatomic) BOOL shouldUpthrowImage;  // 是否要上抛解码后的视频数据
@property (assign, nonatomic) int32_t renderType; // 0: defalut glViewRender; 1: VR render
@property (assign, nonatomic) int32_t playerRenderOrientation; // 默认是0，表示UIInterfaceOrientationPortrait，1表示UIInterfaceOrientationLandscapeRight
- (NSDictionary *)getAllOptions;
@property (assign, nonatomic) BOOL useOptimizedHEVC;
@property (assign, nonatomic) BOOL enablePlaybackRate;

//是否使用videotoolboxHEVC
@property (assign, nonatomic) BOOL videotoolboxHEVC;
//是否启用动态刷新vtb
@property (assign, nonatomic) BOOL vtbHandleResolutionChange;

@property (assign, nonatomic) int32_t maxnormalplay;
@property (assign, nonatomic) int32_t minnormalplay;
@property (assign, nonatomic) int32_t maxfastplay;

@property (assign, nonatomic) BOOL simpleMode;

@end
