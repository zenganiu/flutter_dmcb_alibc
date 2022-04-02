//
//  DWVideoModel.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/5.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

//(真！)互动类型
#define DWVideoInteractiveModelTypeItem             @"item"
#define DWVideoInteractiveModelTypeCoupon           @"coupon"
#define DWVideoInteractiveModelTypeAlicoupon        @"alicoupon"
#define DWVideoInteractiveModelTypeContentTag       @"contentTag"
#define DWVideoInteractiveModelTypecontentTagTrace  @"contentTagTrace"
#define DWVideoInteractiveModelTypeTaoWa            @"taowa"

typedef NS_ENUM(NSInteger, DWVideoInteractiveModelType) {
    DWVideoInteractiveModelTypeTimeLine = 1,
    //DEPRECATED = 2
//    DWVideoInteractiveModelTypeLive = 3,
    DWVideoInteractiveModelTypeLabel = 4, //贴片
    DWVideoInteractiveModelTrackTag = 5
};

@class DWTimeLineModel;

@interface DWVideoModel : NSObject

@property (strong, nonatomic) NSString        * id;
@property (strong, nonatomic) NSString        * videoId;
@property (strong, nonatomic) NSString        * source;
@property (strong, nonatomic) NSString        * duration;
@property (strong, nonatomic) NSString        * videoUrl;
@property (strong, nonatomic) NSString        * userId;
@property (strong, nonatomic) NSString        * title;
@property (strong, nonatomic) NSDictionary    * begin;
@property (strong, nonatomic) NSDictionary    * end;
@property (strong, nonatomic) NSArray<DWTimeLineModel*>         * timeline;
@property (strong, nonatomic) NSDictionary    * jsTemplates;
@property (strong, nonatomic) NSDictionary    * jsUrls;
@property (nonatomic, copy) NSString*           userName;

@property (strong, nonatomic) NSString        * shopUrl;
@property (nonatomic, copy) NSString*           coverUrl;

//@property (nonatomic, strong) NSDictionary *comprehensionType;

@property (nonatomic, strong) NSDictionary *interactiveMap;

@property (nonatomic, strong) NSDictionary *extendsParam;

@property (nonatomic, strong) NSDictionary *taokeRelation;

+ (instancetype)modelWithJSONDictionary:(NSDictionary *)dict;

@end
