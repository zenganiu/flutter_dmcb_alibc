//
//  TBARVUtils.h
//  AriverDemo
//
//  Created by zhongweitao on 2019/3/27.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TRVUtil : NSObject

#pragma mark - JSON

+ (NSString *)JSONString:(id)object;

#pragma mark - Color

+ (NSString *)hexStringFromColor:(UIColor *)color;

+ (NSString *)hexStringFromHexNum:(NSInteger)hex;

+ (NSString *)hexStringFromHexNumWithAlpha:(NSInteger)hex;

+ (NSString *)convertRunSceneToAlipay:(NSString *)sourceScene;

+ (NSString *)convertAlipayRunSceneToAppX:(NSString *)sourceScene;

#pragma mark - APP
+ (NSString *)miniProgramUrlForAppId:(NSString *)appId page:(NSString *)page params:(NSDictionary *)params;
+ (NSString *)miniProgramUrlForAppId:(NSString *)appId page:(NSString *)page versionParams:(NSDictionary *)versionParams;

#pragma mark - downgrade
+ (BOOL)downgradeWebGoBack;
+ (BOOL)forbidWebGoBackForAppId:(NSString *)appId;
+ (BOOL)closeDataPrefetch;
+ (BOOL)closeUpdatePresetAppx;
// 降级navigateToMiniProgram关闭目标App的框架loading
+ (BOOL)closeOpenAppWithHideLoading;

/// @brief 关闭清理缓存
+ (BOOL)closeClearCache;
/// @brief 关闭扫码清缓存
+ (BOOL)closeScanClearCache;

@end
