//
//  TRVVideoPlayerModel.h
//  Media
//
//  Created by 岚遥 on 2019/7/25.
//  Copyright © 2019 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// mobile network remind type, default is 1
typedef NS_ENUM(NSInteger, TRVVideoPlayerMobileNetworkRemindType) {
    TRVVideoPlayerMobileNetworkRemindTypeNone = 0,              // 不提醒
    TRVVideoPlayerMobileNetworkRemindTypeTip = 1,               // tip提醒
    TRVVideoPlayerMobileNetworkRemindTypeBlockWithNoFlow = 2,   // 阻塞提醒(无消耗流量大小)
    TRVVideoPlayerMobileNetworkRemindTypeBlockWithFlow = 3      // 阻塞提醒(有消耗流量大小，只有优酷vid才能取到流量大小)
};

typedef NS_ENUM(NSInteger, TRVVideoGravityType) {
    TRVVideoGravityResizeAspect = 0,                            // Preserve aspect ratio; fit within layer bounds.
    TRVVideoGravityResizeAspectFill = 1,                        // Preserve aspect ratio; fill layer bounds.
    TRVVideoGravityResize = 2                                   // Stretch to fill layer bounds.
};

// video player status code
typedef NS_ENUM(NSInteger, TRVVideoPlayerStatus) {
    TRVVideoPlayerStatusUnknow = -1,        // 默认值
    TRVVideoPlayerStatusStop = 0,           // 播放停止
    TRVVideoPlayerStatusPlay = 1,           // 播放中
    TRVVideoPlayerStatusPause = 2,          // 暂停播放
    TRVVideoPlayerStatusLoading = 3,        // 缓冲中
    TRVVideoPlayerStatusEnded = 4,          // 播放完毕
    TRVVideoPlayerStatusReadyToPlay = 5,    // 将要播放
};

@interface TRVVideoPlayerModel : NSObject

@property (nonatomic, strong) NSString *src; // 视频源
@property (nonatomic, strong) NSString *poster; // 封面图（获取第一帧当封面图）
/**
 当视频大小与 video 容器大小不一致时，视频的表现形式。contain：包含，fill：填充。
 */
@property (nonatomic, strong) NSString *objectFit;
@property (nonatomic, assign) AVLayerVideoGravity videoGravity;

@property (nonatomic, strong) NSNumber *initialTime; // 指定视频初始播放位置，单位s
@property (nonatomic, strong) NSNumber *duration; // 指定视频时长，单位s，默认读取视频本身时长信息
/**
 设置全屏时视频的方向，不指定则根据宽高比自动判断。有效值为 0（正常竖向）, 90（屏幕逆时针90度）, -90（屏幕顺时针90度）
 */
@property (nonatomic, strong) NSNumber *direction;
@property (nonatomic, assign) UIInterfaceOrientation orientation;

@property (nonatomic, assign) TRVVideoPlayerStatus playStatus;

/**
 移动网络提醒样式：0-不提醒；1-tip提醒；2-阻塞提醒(无消耗流量大小)；3-阻塞提醒(有消耗流量大小，只有优酷vid才能取到流量大小) 默认 1
 */
@property (nonatomic, assign) TRVVideoPlayerMobileNetworkRemindType mobilenetHintType;

@property (nonatomic, assign) BOOL controls; // 是否显示默认播放控件（底部工具条，包括播放/暂停按钮、播放进度、时间）true
@property (nonatomic, assign) BOOL autoplay; // 是否自动播放 false
@property (nonatomic, assign) BOOL loop; // 是否循环播放 false
@property (nonatomic, assign) BOOL muted; // 是否静音播放 false
@property (nonatomic, assign) BOOL showFullScreenBtn; // 是否显示全屏按钮 true
@property (nonatomic, assign) BOOL showPlayBtn; // 是否显示视频底部控制栏的播放按钮 true
@property (nonatomic, assign) BOOL showCenterPlayBtn; // 是否显示视频中间的播放按钮 true
@property (nonatomic, assign) BOOL showMuteBtn; // 是否展示工具栏上的静音按钮 true
@property (nonatomic, assign) BOOL showThinProgressBar; // 当底部工具条隐藏时，是否显示细进度条（controls=false时设置无效）false
@property (nonatomic, assign) BOOL enableProgressGesture; // 是否开启控制进度的手势 true
/**
 如果poster没有设置，且该值为true，会默认取视频的首帧图作为封面图；如果设置了poster，该属性会被忽略
 */
@property (nonatomic, assign) BOOL showFirstFrameAsPoster;

// 手淘店铺二楼视频新增属性, trvVideoSource 和 trvVideoBizCode 是强校验，必填
@property (nonatomic, strong) NSString *trvVideoSource;
@property (nonatomic, strong) NSString *trvVideoID;
@property (nonatomic, strong) NSString *trvVideoBizCode;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
