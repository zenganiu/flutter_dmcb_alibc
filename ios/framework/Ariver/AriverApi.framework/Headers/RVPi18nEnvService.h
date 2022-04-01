//
//  RVPi18nEnvService.h
//  AriverApi
//
//  Created by Klueze on 2020/2/20.
//  Copyright © 2020 Alipay. All rights reserved.
//

#ifndef RVPi18nEnvService_h
#define RVPi18nEnvService_h

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>

typedef NS_ENUM(NSUInteger, RVPLayoutDirection) {
    RVPLayoutDirectionLTR = 0,
    RVPLayoutDirectionRTL
};

@protocol RVPi18nEnvService <RVAServiceProtocol>

@optional
/*
* 获取App应用当前的Region设置
* https://yuque.antfin-inc.com/kizfbk/dkxa22/he6c78#jx8uC
* @return 由接入方按ISO标准实现，不实现该接口，默认系统设置Locale区域码
* @see [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode];
*
* ISO 3166-1 alha-2 code. eg. 'CN', 'HK', 'IN'
*/
- (NSString *)regionCode;
/*
* 获取App应用当前的Region设置
* https://yuque.antfin-inc.com/kizfbk/dkxa22/he6c78#jx8uC
* @return 由接入方按ISO标准实现，不实现该接口，默认APP最优语言
* @see [[NSBundle mainBundle] preferredLocalizations] 第一个语言
*
* Follow BCP 47 language tag, consisting of a language code(ISO639) and optional region code(ISO6133-1 alpha-2) . eg. 'en', 'th-TH', 'zh-CN'
*/
- (NSString *)languageTag;
/*
* 获取App应用当前的货币设置
* https://yuque.antfin-inc.com/kizfbk/dkxa22/he6c78#jx8uC
* @return 由接入方按ISO标准实现，不实现该接口，默认系统设置Locale币种
* @see [[NSLocale currentLocale] objectForKey:NSLocaleCurrencyCode];
*
* iso-4217-currency-codes eg. 'RUB', 'USD'
*/
- (NSString *)currencyCode;

/*
* 获取App应用当前的屏幕方向
* Get the layout direction for  current language
* https://yuque.antfin-inc.com/kizfbk/dkxa22/he6c78#jx8uC
* @return 由接入方按目前APP屏幕方向实现，不实现该接口，默认系统读取App方向
* @see [UIApplication sharedApplication].userInterfaceLayoutDirection
*
* Layout direction of text, table columns, and horizontal overflow for current language.
* The valid value is 'RVPLayoutDirectionRTL' or 'RVPLayoutDirectionLTR'.
* Commonly used for 'direction' in stylesheet.
*/
- (RVPLayoutDirection)layoutDirection;

@end

#endif /* Header_h */
