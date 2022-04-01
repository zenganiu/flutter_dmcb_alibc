//
//  RVLDefines.h
//  RiverLogger
//
//  Created by lianyu on 2020/3/6.
//  Copyright © 2020 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 日志级别。
 */
typedef NS_ENUM(NSInteger, RVLLevel) {
	RVLLevelOff = 0,    // 关闭日志。
	RVLLevelError = 1,  // 错误日志。
	RVLLevelWarn = 2,   // 警告日志。
	RVLLevelInfo = 3,   // 信息日志。
	RVLLevelDebug = 4,  // 调试日志。
	RVLLevelVerbose = 5 // 冗余日志。
};

/**
 表示自 1970-01-01 00:00:00 UTC 以来的毫秒数。
 */
typedef double RVLMillisecondTime;

#ifdef __cplusplus
extern "C" {
#endif

/**
 返回指定日志级别的字符串。
 */
NSString * _Nonnull RVLGetLevelString(RVLLevel logLevel);
	
/**
 返回 1970-01-01 00:00:00 UTC 以来的毫秒数。
 */
RVLMillisecondTime RVLCurrentTime(void);

#ifdef __cplusplus
}
#endif
