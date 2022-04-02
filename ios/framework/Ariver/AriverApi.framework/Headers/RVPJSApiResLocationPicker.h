//
//  RVPJSApiResLocationPicker.h
//  AriverApi
//
//  Created by 百喻 on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResLocationPicker : RVKJSApiResponseBase

@property (nonatomic,copy) NSString *poiId;                     // 兴趣点id
@property (nonatomic,copy) NSString *shopID;                    // 商铺id
@property (nonatomic,copy) NSString *snippet;                   // 简要地址信息
@property (nonatomic,copy) NSString *title;                     // 兴趣点名称
@property (nonatomic,copy) NSString *tel;                       // 联系电话
@property (nonatomic,strong) NSDictionary *latLonPoint;         // 经纬度信息
@property (nonatomic,copy) NSString *adCode;                    // 区域编码
@property (nonatomic,copy) NSString *adName;                    // 区域名称
@property (nonatomic,copy) NSString *cityCode;                  // 城市编码
@property (nonatomic,copy) NSString *cityName;                  // 城市名称
@property (nonatomic,copy) NSString *provinceCode;              // 省编码
@property (nonatomic,copy) NSString *provinceName;              // 省
@property (nonatomic,copy) NSString *gridcode;                  // 地理格id
@property (nonatomic,strong) NSNumber *hasIndoorMap;            // 是否有室内地图
@property (nonatomic,copy) NSDictionary *indoorData;            // 室内信息
@property (nonatomic,copy) NSString *businessArea;              // 商圈
@property (nonatomic,copy) NSString *parkingType;               // 停车场类型：地下，地上，路边
@property (nonatomic,strong) NSDictionary *enter;               // 入口经纬度
@property (nonatomic,strong) NSDictionary *exit;                // 出口经纬度
@property (nonatomic,strong) NSString *subPOIs;                  // 子POI列表
@property (nonatomic,copy) NSString *website;                   // 网站
@property (nonatomic,copy) NSString *email;                     // email信息
@property (nonatomic,strong) NSNumber *distance;                // 距中心点的距离，单位米，在周边搜索时有效
@property (nonatomic,copy) NSString *direction;                 // 兴趣点所在方向
@property (nonatomic,copy) NSString *typeDes;                   // 兴趣点类型
@property (nonatomic,copy) NSString *postcode;                  // 邮编

@end

NS_ASSUME_NONNULL_END
