//
//  DWInteractiveModel.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/7.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DWTrackerModel;

@interface DWInteractiveModel : NSObject

@property (strong, nonatomic) NSString        * type;          //类型, weex or h5 or...
@property (strong, nonatomic) NSString        * jsTemplate;    //jsbundle
@property (strong, nonatomic) NSString        * jsUrl;
@property (strong, nonatomic) NSDictionary        * jsData;        //数据
@property (strong, nonatomic) NSString        * layout;        //组件基于视频的坐标布局
@property (nonatomic, strong) NSArray<DWTrackerModel*> *anchorArray;//用于描述视频追踪的某一时刻的位置信息
@property (nonatomic, copy) NSString*            renderOrientation; //用于描述渲染方向，取值为LT、RT、RB、LB
// 3.0 新增
@property (nonatomic, strong) NSDictionary    *margin;
@property (nonatomic, strong) NSArray *startAnimations;
@property (nonatomic, strong) NSArray *endAnimations;
// timelinemodel的source
@property (nonatomic, strong) NSString *source;

+ (instancetype)modelWithJSONDictionary:(NSDictionary *)dict;

@end
