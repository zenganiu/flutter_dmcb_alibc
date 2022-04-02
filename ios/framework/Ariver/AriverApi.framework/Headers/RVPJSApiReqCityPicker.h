//
//  RVPJSApiReqCityPicker.h
//  AriverApi
//
//  Created by 百喻 on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

@interface RVPJSApiReqCityPicker : RVKJSApiRequestBase

@property (nonatomic,copy) NSString *currentCity;
@property (nonatomic,copy) NSString *adcode;
@property (nonatomic,strong) NSArray *customCities;
@property (nonatomic,strong) NSArray *customHotCities;
@property (nonatomic,strong) NSArray *customHistoryCities;
@property (nonatomic,strong) NSNumber *setLocatedCity;          // 只有显示当前定位城市，才判断是否要业务来修改当前城市
@property (nonatomic,strong) NSNumber *setLocatedCityTimeout;   // 业务获取城市名时的超时时间
// ui Config
@property (nonatomic,strong) NSNumber *needHotCity;
@property (nonatomic,copy) NSString *searchbarhint;
@property (nonatomic,copy) NSString *hotcitytitle;
@property (nonatomic,copy) NSString *cityselect_hot_city_section;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,copy) NSString *recommendlinktitle_oversea;
@property (nonatomic,copy) NSString *recommendlinkname_oversea;
@property (nonatomic,copy) NSString *recommendlinkurl_oversea;
@property (nonatomic,copy) NSString *recommendlinksection_oversea;

@end

