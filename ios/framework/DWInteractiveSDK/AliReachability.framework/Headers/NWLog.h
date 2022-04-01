//
//  NWLog.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 3/24/15.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//


#import <Foundation/Foundation.h>


// -----------------------------------------------------------------------------
// 网络SDK版本号，每次有新版本集成都需要变更
#define NETWORK_V @"6.2.1.29"


#define TLOG_MODEL_NAME @"NetworkSDK"
// -----------------------------------------------------------------------------
// NWLog宏定义
#define NW_LOG_ERROR(...) \
[NWLog log:NW_LOG_ERROR file:__FILE__ func:__func__ line:__LINE__ module:TLOG_MODEL_NAME msg:__VA_ARGS__]

#define NW_LOG_WARNING(...) \
[NWLog log:NW_LOG_WARNING file:__FILE__ func:__func__ line:__LINE__ module:TLOG_MODEL_NAME msg:__VA_ARGS__]

#define NW_LOG_INFO(...) \
[NWLog log:NW_LOG_INFO file:__FILE__ func:__func__ line:__LINE__ module:TLOG_MODEL_NAME msg:__VA_ARGS__]

#define NW_LOG_DEBUG(...) \
[NWLog log:NW_LOG_DEBUG file:__FILE__ func:__func__ line:__LINE__ module:TLOG_MODEL_NAME msg:__VA_ARGS__]

// -----------------------------------------------------------------------------
// 不拼装

#define NW_LOG_ERROR_NO_FORMAT(log) [NWLog log:NW_LOG_ERROR msg:log]
#define NW_LOG_WARNING_NO_FORMAT(log) [NWLog log:NW_LOG_WARNING msg:log]
#define NW_LOG_INFO_NO_FORMAT(log) [NWLog log:NW_LOG_INFO msg:log]
#define NW_LOG_DEBUG_NO_FORMAT(log) [NWLog log:NW_LOG_DEBUG msg:log]

/**
 * 日志级别
 */
typedef enum {
    NW_LOG_NONE    = -1,
    NW_LOG_ERROR   = 0,
    NW_LOG_WARNING = 1,
    NW_LOG_INFO    = 2,
    NW_LOG_DEBUG   = 3,
    NW_LOG_ALL     = 4,
} NW_LOG_LEVEL;


@interface NWLog : NSObject

+ (void)log:(NSInteger)level file:(const char *)file func:(const char *)func line:(int)line module:(NSString *)module msg:(NSString *)fmt, ...;

+ (void)log:(NSInteger)level msg:(NSString *)msg;

+ (void)setUserLogDelegate:(id)delegate;

+ (NW_LOG_LEVEL)currentLevel;

+ (void)setLogLevel:(NW_LOG_LEVEL)level;

@end

