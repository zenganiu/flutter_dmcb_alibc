//
//  TRVLocationProtocol.h
//  Triver
//
//  Created by lanyao on 2019/4/17.
//

#import <Foundation/Foundation.h>
#import <AriverApi/RVPJSApiResLocation.h>

/**
 * 定位错误类型
 **/
typedef NS_ENUM(NSUInteger, TRVLocationError) {
    /**
     * 定位相关权限未开启
     **/
    TRVLocationErrorNoPermission        = 11,
    /**
     * 网络异常
     **/
    TRVLocationErrorNetworkNotReachable = 12,
    /**
     * 定位失败
     **/
    TRVLocationErrorLocationFailed      = 13,
    /**
     * 业务定位超时
     **/
    TRVLocationErrorLocationTimeOut     = 14,
};

typedef NS_ENUM(NSUInteger, TRVLocationType) {
	/**
	 * 默认，获取经纬度
	 **/
	TRVLocationTypeBasic = 0,
	/**
	 * 获取经纬度和详细到区县级别的逆地理编码数据
	 **/
	TRVLocationTypeDistrict = 1,
	/**
	 * 获取经纬度和详细到街道级别的逆地理编码数据
	 **/
	TRVLocationTypeStreet = 2,
	/**
	 * 获取经纬度和详细到POI级别的逆地理编码数据
	 **/
	TRVLocationTypePOI = 3
};

@protocol TRVLocationManagerProtocol <NSObject>
@required

/**
 请求定位信息
 ！！注意：这个方法当做单例来触发，扩展时需要注意数据和状态之间的污染
 
 @param type 请求定位信息类型，决定返回数据的类型
 @param cacheTime 定位信息缓存时间
 @param aBlock 数据回调
 */
- (void)requestLocationWithType:(TRVLocationType)type
				   cacheTimeout:(NSNumber *)cacheTime
					   complete:(void(^)(BOOL success, RVPJSApiResLocation *locationData, TRVLocationError error))aBlock;

@end
