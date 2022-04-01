//
//  DWInteractiveInfo.h
//  DWInteractiveSDK
//
//  Created by jyi on 2016/12/14.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, DWVideoMeasureType) {
    DWVideoMeasureTypeUnknown = 0,
    DWVideoMeasureType1to1,
    DWVideoMeasureType16to9,
    DWVideoMeasureType9to16
};


@interface DWInteractiveInfo : NSObject

@property (nonatomic, strong) NSString *interactiveID;

//视频作者ID
@property (nonatomic, strong) NSString *userID;
@property (nonatomic, copy)   NSString *contentID;// 内容平台id

//临时 -- fangying
@property (nonatomic, copy)   NSString *mediaContentID;// 媒资平台id
@property (nonatomic, assign) BOOL               bNewInteractiveInfo;
@property (nonatomic, assign) BOOL               bSupportMute;
@property (nonatomic, assign) DWVideoMeasureType videoMeasureType;
@property (nonatomic, copy) NSDictionary       *outBizData;// 透传外部的业务数据
//临时 -- fangying
@property (copy, nonatomic) NSDictionary *interactiveParms;

//内部使用，业务方无需传
@property (nonatomic, strong) NSDictionary*      recommendVideos;
// 标识互动应用的大场景 比如timeline
@property (nonatomic, strong) NSString *scenes;
// 标识互动的玩法 比如套娃
@property (nonatomic, strong) NSString *interactiveType;


@end
