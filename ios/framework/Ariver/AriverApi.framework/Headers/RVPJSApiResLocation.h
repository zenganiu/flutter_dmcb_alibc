//
//  RVPJSApiResLocation.h
//  AriverApi
//
//  Created by lanyao on 2019/4/17.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResLocation : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *longitude; // 经度
@property (nonatomic, strong) NSNumber *latitude; // 纬度
@property (nonatomic, strong) NSNumber *accuracy; // 精确度，单位m
@property (nonatomic, strong) NSNumber *horizontalAccuracy; // 水平精确度，单位m
@property (nonatomic, strong) NSString *country; // 国家(type>0生效)
@property (nonatomic, strong) NSString *countryCode; // 国家编号 (type>0生效)
@property (nonatomic, strong) NSString *province; // 省份(type>0生效)
@property (nonatomic, strong) NSString *city;  // 城市(type>0生效)
@property (nonatomic, strong) NSString *cityAdcode; // 城市级别的地区代码(type>0生效)
@property (nonatomic, strong) NSString *district; // 区县(type>0生效)
@property (nonatomic, strong) NSString *districtAdcode; // 区县级别的地区代码(type>0生效)
@property (nonatomic, strong) NSDictionary *streetNumber; // 需要街道级别逆地理的才会有的字段,街道门牌信息，结构是：{street, number} (type>1生效)
@property (nonatomic, strong) NSArray *pois; // 需要POI级别逆地理的才会有的字段,定位点附近的 POI 信息，结构是：{name, address}（type>2生效）

@end

NS_ASSUME_NONNULL_END
