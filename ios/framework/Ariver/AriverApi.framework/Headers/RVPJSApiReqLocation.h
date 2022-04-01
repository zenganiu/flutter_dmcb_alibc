//
//  RVPJSApiReqLocation.H
//  AriverApi
//
//  Created by lanyao on 2019/4/17.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqLocation : RVKJSApiRequestBase

/**
 0：默认，获取经纬度
 1：获取经纬度和详细到区县级别的逆地理编码数据
 2：获取经纬度和详细到街道级别的逆地理编码数据，不推荐使用
 3：获取经纬度和详细到POI级别的逆地理编码数据，不推荐使用
 */
@property (nonatomic, strong) NSNumber *requestType;
@property (nonatomic, strong) NSNumber *cacheTimeout; // 可接受的缓存时间，单位秒

@end

NS_ASSUME_NONNULL_END
