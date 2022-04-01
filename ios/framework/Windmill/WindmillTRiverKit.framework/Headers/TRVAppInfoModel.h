//
//  TRVAppInfoModel.h
//  AppContainer
//
//  Created by AllenHan on 2019/3/28.
//  Copyright © 2019年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>


#define WMLAppContainerEnterParamNeedBackKey @"wml_needBack"

// 业务类型定义
#define TRVBrandZoneBizType @"4"
#define TRVBrandZoneSubBizType @"16"

@interface TRVAppBizInfoModel : NSObject
@property (nonatomic, assign) BOOL specialFavor; // 是否是默认关注小程序
@property (nonatomic, assign) BOOL favorEnable; // 是否支持收藏
@property (nonatomic, assign) BOOL drawerEnable; // 是否支持抽屉坑位
@property (nonatomic, copy) NSString *frameTempType; // "pubArea"/"priArea"/"priTool"
//bizType和subBizType是业务标识；譬如bizType=2、subBizType=13是轻店业务的标识
@property (nonatomic, copy) NSString *bizType;
@property (nonatomic, copy) NSString *subBizType;
@property (nonatomic, assign) BOOL isShopMiniApp;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
// 是否是轻应用
- (BOOL)isTinyApp;
// 是否是轻店铺
- (BOOL)isTinyShop;
// 是否是小工具 & 购物小程序
- (BOOL)isTinyTool;
// 是否是店铺二楼
- (BOOL)isBrandZone;
@end

@interface TRVAppInfoModel : NSObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appSimpleName;
@property (nonatomic, copy) NSString *appLogo;
@property (nonatomic, copy) NSString *appDesc;
@property (nonatomic, strong) TRVAppBizInfoModel *bizInfo;
@end



