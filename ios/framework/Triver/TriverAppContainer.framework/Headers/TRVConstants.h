//
//  TRVConstants.h
//  Triver
//
//  Created by zhongweitao on 2019/4/8.
//

#import <Foundation/Foundation.h>


#pragma mark - Error Domain

#define TRV_ERROR_DOMAIN_DB      @"TRVErrorDomainDB"
#define TRV_ERROR_DOMAIN_APPINFO @"TRVErrorDomainAppInfo"
#define TRV_ERROR_DOMAIN_UI      @"TRVErrorDomainUI"
#define TRV_ERROR_DOMAIN_API     @"TRVErrorDomainAPI"

#pragma mark - Error Code

#define TRV_ERROR_TITLE   @"服务竟然出错了"
#define TRV_ERROR_SUBTITLE @"一定是哪里出了问题，请稍后再试"

#pragma mark - 启动错误码

// AppInfo 请求出错
#define TRV_APPINFO_MTOP_ERROR         @"TRV_APPINFO_MTOP_ERROR"

#pragma mark - API

#define TRV_API_ERROR_NOT_SUPPORTED @"当前容器不支持该方法调用"
#define TRV_API_ERROR_INVALID_ARGS  @"参数错误"

//#define TVR_APPX_APPID @"66666692"

#define TRVOpenFromAppIdKey           @"triverOpenFromAppId"
#define TRVOpenAppExtraDataKey        @"triverOpenAppExtraData"
#define TRVOpenHideLoadingKey         @"triverOpenHideLoading"
#define TRVTransitionAnimationKey     @"triverTransitionAnimation"
#define TRVTransitionTypeKey          @"triverTransitionType"

// 业务bizType
#define TRVShopSubBizType @"14"

// 小程序场景值相关定义
#define TRVChInfoBrandZonePublic  @"brandzone_public" // 店铺二路公域
#define TRVChInfoBrandZonePrivate @"brandzone_private" // 店铺二楼私域

// appInfo拓展点Key
#define TRVAILoadingConfigKey   @"appLoadingConfig"
#define TRVAINaviConfigKey      @"appNaviConfig"

// 淘侧小程序URL启动参数(EnterInfo)Key定义
#define TRVEIBrandZoneQueryKey @"query"
#define TRVEIBrandZoneSourceKey @"_shopLoftSource_" //店铺二楼投放来源
#define TRVEIBrandZoneShopIdKey @"shopId" //店铺二楼shopId
#define TRVEIBrandZoneSellerIdKey @"sellerId" //店铺二楼sellerId

@interface TRVConstants : NSObject

@end
