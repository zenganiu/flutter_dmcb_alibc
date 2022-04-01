//
//  TRVEnterInfoModel.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/8.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>

#define WMLAppContainerEnterParamNeedBackKey @"wml_needBack"
#define WMLEnterInfoEnterParamsExtraDataKey @"extraData"

typedef NS_ENUM(NSUInteger, TRVEnterLoadingType) {
    TRVEnterLoadingTypeDefault,
    TRVEnterLoadingTypeSecondPage
};

@interface TRVEnterInfoModel : NSObject
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appLogo;
@property (nonatomic, copy) NSString *appUrl;
@property (nonatomic, copy) NSString *frameTempType;
@property (nonatomic, copy) NSString *loadingType;
@property (nonatomic, strong) NSMutableDictionary *enterParams;
@property (nonatomic, strong) NSDictionary *loadingParams;// loading页参数
@property (nonatomic, assign) BOOL isDebugApp;
@property (nonatomic, copy) NSString *chInfo;// 场景值

/// @brief 轻应用
- (BOOL)isTinyApp;
/// @brief 轻店铺
- (BOOL)isTinyShop;
/// @brief 小工具
- (BOOL)isTinyTool;
/// @brief 品牌Zone
- (BOOL)isBrandZone;
/// @brief 店铺
- (BOOL)isShop;
- (TRVEnterLoadingType)enterLoadingType;
@end

