//
//  WMLUtilities.h
//  Weaver
//
//  Created by lianyu on 2018/7/26.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 提供一些 Weaver 中用到的工具方法。
 */
@interface WMLUtilities : NSObject

/**
 返回 1970-01-01 00:00:00 UTC 以来的秒数。
 */
+ (NSTimeInterval)currentTimeInterval;

/**
 从 .der 公钥证书文件中获取到公钥的 SecKeyRef 指针。
 */
+ (SecKeyRef _Nullable)getRSAPublicKey:(NSData * _Nonnull)certificateData;

@end

/**
 表示毫秒的时间。
 */
typedef double WMLMillisecondTime;

/**
 表示毫秒的时间段。
 */
typedef double WMLMillisecondPeriod;

/**
 返回 1970-01-01 00:00:00 UTC 以来的毫秒数。
 */
NS_INLINE WMLMillisecondTime WMLCurrentTime(void) {
	return [WMLUtilities currentTimeInterval] * 1000.0;
}
