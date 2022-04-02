//
//  TBIctAddWeexCallbackProtocol.h
//  DWInteractiveSDK
//
//  Created by Sapphire on 2017/11/8.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TBIctAddWeexCallbackProtocol <NSObject>

@optional

- (void)interactiveRequestFail;

- (BOOL)add:(UIView *)view cmpType:(NSString *)cmpType screenType:(NSString *)screenType;

// 展示全屏组件
- (void)showFullScreenView:(UIView *)view;
- (void)dismissFullScreenView;
- (CGSize)fullScreenSize;

- (NSDictionary *)currentBizOrientationInfo;

/**
 互动中存在的所有互动组件名称
 @param wxCmps 互动组件名称字符串组成的数据
 */
- (void)onWXCmpExistOrNot:(NSArray *)wxCmps;

/**
 互动组件消失回调

 @param source 当前消失的组件名称
 */
- (void)onWXCmpDismiss:(NSString *)source;


/**
 weex互动触发打开新视频
 videoListInfo中的videoInfo包含的key-value如下：
 videoId、interactiveId、userId、utParams
 */
- (void)openNewVideoWithLevel:(NSUInteger)level
                        index:(NSUInteger)index
                videoListInfo:(NSArray *)videoList
                isUserChecked:(BOOL)userChecked;
/**
 weex触发分享
 shareData中包含的key-value如下：
 icon、url、desc
 */
- (void)share:(NSDictionary *)shareData level:(NSUInteger)level index:(NSUInteger)index type:(NSUInteger)type;

- (void)showAllInteractiveCmp:(BOOL)show;

@end

