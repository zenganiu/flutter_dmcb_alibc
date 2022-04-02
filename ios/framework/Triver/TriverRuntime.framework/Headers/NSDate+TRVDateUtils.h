//
//  NSDate+TRVDateUtils.h
//  Runtime
//
//  Created by AllenHan on 2020/1/20.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TRVDateUtils)

/**
 * 将特定格式的日期转换成NSDate
 * 支持的三种日期的格式
 * yyyyMMddHHmmss 如：20161111080000
 * RFC-1123格式 EEE, dd MMM yyyy HH:mm:ss zzz 如：Wed, 05 Apr 2017 11:32:35 GMT
 * yyyy-MM-dd HH:mm:ss，如 2016-11-11 20:00:00

 @param dateString 日期
*/
+ (NSDate *)trv_dateResolveFromDateString:(NSString *)dateString;

/**
 * 转化成特定的格式的日期

 @param formatter 日期格式
*/
- (NSString *)trv_stringForDateFormatter:(NSDateFormatter *)formatter;

@end

NS_ASSUME_NONNULL_END
