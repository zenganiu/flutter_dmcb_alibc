//
//  DWTimeLineModel.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/5.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DWInteractiveSDK/DWInteractiveModel.h>
#import <DWInteractiveSDK/DWComponent.h>
#import <DWInteractiveSDK/DWVideoModel.h>
@interface DWTimeLineModel : NSObject

@property (nonatomic) BOOL isShowed;

@property (strong, nonatomic) NSString        * index;          //索引
@property (strong, nonatomic) NSString        * startTime;      //启动时间点
@property (strong, nonatomic) NSString        * endTime;        //结束时间点
@property (strong, nonatomic) NSString        * source;         //业务属性
@property (strong, nonatomic) DWInteractiveModel        * portraitMode;   //类型
@property (strong, nonatomic) DWInteractiveModel        * landscapeMode;   //类型

@property (nonatomic, strong) NSDictionary *utParams;

@property (strong, nonatomic) DWComponent        * portComponent;
@property (strong, nonatomic) DWComponent        * landComponent;

//@property (strong, nonatomic) DWComponent*         anchorPortComponent;
//@property (strong, nonatomic) DWComponent*         anchorLandComponent;
// 3.0 新增, 由VideoModel传来
@property (nonatomic, assign) DWVideoInteractiveModelType videoInteractiveType;

//@property (nonatomic, strong) NSDictionary*             portIndexedAnchor;
//@property (nonatomic, strong) NSDictionary*             landIndexedAnchor;
@property (nonatomic, strong) NSArray *portraitVideoList;


+ (instancetype)modelWithJSONDictionary:(NSDictionary *)dict;

@end
