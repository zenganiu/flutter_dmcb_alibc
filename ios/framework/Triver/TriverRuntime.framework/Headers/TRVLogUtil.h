//
//  TRVLogUtil.h
//  Triver
//
//  Created by zhongweitao on 2019/7/18.
//

#import <Foundation/Foundation.h>

/**
 小程序启动链路的模块名。
 */
FOUNDATION_EXPORT NSString * const TRVLogLaunchModuleName;
/**
 小程序信息中，传递 traceId 的键。
 */
FOUNDATION_EXPORT NSString * const TRVLogTraceIdKey;

@interface TRVLogUtil : NSObject

/**
 为小程序启动生成唯一跟踪 ID。
 */
+ (NSString *)generateLaunchTraceId;

/**
 记录指定 AppID 关联到的唯一跟踪 ID。
 */
+ (void)recordTraceId:(NSString *)traceId forAppId:(NSString *)appId;

+ (BOOL)logInfoForEventId:(NSString *)eventId
                     desc:(NSString *)desc
                    stage:(NSString *)stage
                    appId:(NSString *)appId
                 pageName:(NSString *)pageName
                     info:(NSDictionary *)info;

+ (BOOL)logSuccessForEventId:(NSString *)eventId
                        desc:(NSString *)desc
                       appId:(NSString *)appId
                       stage:(NSString *)stage
                    pageName:(NSString *)pageName
                        info:(NSDictionary *)info;

/// @brief 只进入本地localDebug工具，不输出到TLog
+ (BOOL)localLogForEventId:(NSString *)eventId
                      desc:(NSString *)desc
                     stage:(NSString *)stage
                     appId:(NSString *)appId
                  pageName:(NSString *)pageName
                      info:(NSDictionary *)info;

/**
 输出小程序启动链路的事件日志。
 */
+ (void)logLaunchEvent:(NSString *)event desc:(NSString *)desc stage:(NSString *)stage appId:(NSString *)appId pageName:(NSString *)pageName info:(NSDictionary *)info;

@end
