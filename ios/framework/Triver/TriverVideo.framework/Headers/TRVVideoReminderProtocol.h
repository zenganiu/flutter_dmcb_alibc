//
//  TRVVideoReminderProtocol.h
//  Video
//
//  Created by 岚遥 on 2019/9/19.
//  Copyright © 2019 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVVideoReminderProtocol <NSObject>

@optional

/**
 是否在网络状态切换时进行提醒
 */
- (BOOL)trv_enableRemindWhenChangingNetworkStatus;

/**
 是否在 4G 播放时进行提醒
 */
- (BOOL)trv_enableRemindWhenPlayAt4G;

/**
 4G 播放时的提醒文案
 */
- (NSString *)trv_reminderMessageWhenPlayAt4G;

@end

NS_ASSUME_NONNULL_END
