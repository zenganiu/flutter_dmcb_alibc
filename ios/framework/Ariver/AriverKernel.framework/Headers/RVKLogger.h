//
//  RVKLogger.h
//  NebulaPoseidon
//
//  Created by theone on 16/11/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RVKLogInfo(logType,fmt, ...)  RVKLog(nil, logType,fmt, ##__VA_ARGS__)
#define RVKLogDebug(logType,fmt, ...) RVKLog(RVKLocalLogLevelDebug, logType, fmt, ##__VA_ARGS__)
#define RVKLogLevel(level, logType, fmt, ...) RVKLog(level, logType, fmt, ##__VA_ARGS__)
#define RVKLog(level, logType, fmt, ...) [[RVKLogger shareInstance] localLogWithLevel:level type:logType content:[NSString stringWithFormat:fmt,  ##__VA_ARGS__]]

typedef NSString * RVKLocalLogType;
typedef NSString * RVKLocalLogSubType;
typedef NSString * RVKLocalLogLevel;

extern RVKLocalLogLevel const _Nonnull RVKLocalLogLevelDebug;
extern RVKLocalLogLevel const _Nonnull RVKLocalLogLevelInfo;
extern RVKLocalLogLevel const _Nonnull RVKLocalLogLevelWarn;
extern RVKLocalLogLevel const _Nonnull RVKLocalLogLevelError;

extern RVKLocalLogType const _Nonnull RVKLocalLogTypeConnection;
extern RVKLocalLogType const _Nonnull RVKLocalLogTypeAPI;
extern RVKLocalLogType const _Nonnull RVKLocalLogTypeEvent;
extern RVKLocalLogType const _Nonnull RVKLocalLogTypePage;


@interface RVKLogger : NSObject
+ (instancetype)shareInstance;
- (void)doLogWithLogId:(NSString *)logId params:(NSDictionary *)params;

// for diagnose purpose
- (void)localLogWithLevel:(nullable RVKLocalLogLevel)level type:(nullable RVKLocalLogType)logType content:(NSString *_Nullable)content;
- (void)localLogWithLevel:(nullable RVKLocalLogLevel)level type:(nullable RVKLocalLogType)logType parentTraceId:(NSString *_Nullable)parentTraceId groupTraceId:(NSString *_Nullable)groupTraceId content:(NSString *_Nullable)content;

@end
