//
//  TRVUtils.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/4.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - NSUserDefaultKey
static NSString * const WMLUserDefaultKey = @"windmill_user_default_key";

@interface TRVUtils : NSObject

#pragma mark - 通用
+ (BOOL)trv_isIPhoneXSeries;
+ (NSString *)md5:(NSString *)input;

#pragma mark - Bundle
+ (NSBundle *)getCurrentBundle;
+ (NSBundle *)getMainBundle;

#pragma mark - AboutPage
+ (NSString *)getAboutPageUrl;
+ (BOOL)isAboutPage:(NSString *)pageUrl;

#pragma mark - AuthSetting Page
+ (NSString *)getAuthSettingPageUrl;
+ (BOOL)isAuthSettingPage:(NSString *)pageUrl;

#pragma mark - NSUserDefault
/**
 读取NSUserDefault中Windmill结构下的相关Key对应的值
 */
+ (id)getUserDefaultObjectForKey:(NSString *)key;
/**
 设置NSUserDefault中Windmill结构下的相关Key对应的值
 */
+ (void)setUserDefaultObject:(id)object forKey:(NSString *)key;
/**
 删除NSUserDefault中Windmill结构下的相关Key对应的值
 */
+ (void)removeUserDefaultObjetcForKey:(NSString *)key;
/**
 删除NSUserDefault中Windmill结构下的一组Key对应的值
 */
+ (void)removeUserDefaultObjetcForKeys:(NSArray<NSString*>*)keys;

#pragma mark - 降级
+ (BOOL)downgradeShare;

+ (NSString *)trv_standardEncodeString:(NSURLComponents *)urlComponents;

@end

