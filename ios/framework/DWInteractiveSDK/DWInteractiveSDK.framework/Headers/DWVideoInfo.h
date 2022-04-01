//
//  DWVideoInfo.h
//  DWInteractiveSDK
//
//  Created by jyi on 2016/12/14.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DWVideoInfo : NSObject

/**
 * 视频来源 (强校验) 淘宝视频源传"TBVideo"，优酷视频源传@“YKVideo”，淘宝直播下传“TBLive”，其他场景下传任意非空字符串
 */
@property (nonatomic, strong) NSString *videoSource;

/**
 * 视频ID (强校验)，直播模式下不校验
 */
@property (nonatomic, strong) NSString *videoID;

/**
 * 视频业务标识 (强校验)，直播模式下不校验
 */
@property (nonatomic, strong) NSString *bizCode;

/**
 * 视频URL (强校验)，直播模式下不校验
 */
@property (nonatomic, strong) NSString *videoURL;

/**
 * 视频时长(用于视频缓存策略)，直播模式下不校验
 */
@property (nonatomic, copy) NSString*   videoDuration;

/**
 * 封面图片URL，直播模式下不校验
 */
@property (nonatomic, copy) NSString* imageURL;

/**
* 目前只给手淘内的全屏页业务使用，来标识全屏页业务
*/
@property (nonatomic, copy) NSString* videoPlayScenes;

/**
* 目前用在直播模式下，透传直播liveDetail接口内的所有字段给播放器
*/
@property (nonatomic, copy) NSDictionary* liveDetailInfo;

@end
