//
//  TBMPBUtil.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 3/31/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifdef DEBUG
#define debugLog(...) NSLog(__VA_ARGS__)
#define debugMethod() NSLog(@"%s", __func__);
#else
#define debugLog(...)
#define debugMethod()
#endif

#define TBMPB_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

@interface NSTimer (TBMPBUtil)
+ (NSTimer *)TBMPBUtil_scheduledTimerWithTimeInterval:(NSTimeInterval)interval block:(void(^)())block repeats:(BOOL)repeats;
@end

typedef NS_ENUM(NSInteger, TBMPBDeviceDisplay) {
    TBMPBDeviceDisplayUnknown = 0,
    TBMPBDeviceDisplay3p5Inch,
    TBMPBDeviceDisplay4Inch,
    TBMPBDeviceDisplay4p7Inch,
    TBMPBDeviceDisplay5p5Inch,
    TBMPBDeviceDisplay7p9Inch,
    TBMPBDeviceDisplay9p7Inch,
    TBMPBDeviceDisplay12p9Inch,
};

#define TBMPBLogInfoKeyModule @"module"
#define TBMPBLogInfoKeyLevel @"level"
#define TBMPBLogInfoKeyContent @"content"

typedef NS_ENUM (NSInteger, TBMPBLogLevel) {
    TBMPBLogLevelOff = 0,
    TBMPBLogLevelError = 1,
    TBMPBLogLevelWarning = 2,
    TBMPBLogLevelInfo = 3,
    TBMPBLogLevelDebug = 4
};


#define TBMPBPerformanceDataKeyModule @"module"
#define TBMPBPerformanceDataKeyPoint @"point"
#define TBMPBPerformanceDataKeyType @"type"
#define TBMPBPerformanceDataKeyDimension @"dimension"
#define TBMPBPerformanceDataKeyPerformance @"performance"

typedef NS_ENUM(int32_t, TBMPBPerformanceDataType) {
    TBMPBPerformanceDataTypeFirstVideoFrame = 0,
    TBMPBPerformanceDataTypeFirstAudioFrame = 1,
    TBMPBPerformanceDataTypeBufferLoad = 2,
    TBMPBPerformanceDataTypePTSDTS = 3,
    TBMPBPerformanceDataTypeNetworkShake = 4,
    TBMPBPerformanceDataTypePlayerError = 5,
    TBMPBPerformanceDataTypePlayExperience = 6,
    TBMPBPerformanceDataTypeStalled = 7,
    TBMPBPerformanceDataTypePlaying = 8,
    TBMPBPerformanceDataTypeSwitchResolution = 9,
    // SeqNO=9999, use as net shake stats
    TBMPBPerformanceDataTypeBtnRtcStreamStatsDetail = 10,
    // SeqNO=9998
    TBMPBPerformanceDataTypeBtnRtcStreamStatsInfo = 11,
    // SeqNO=9997
    TBMPBPerformanceDataTypeBtnRtcStreamStatsDegrade = 12,
    TBMPBPerformanceDataTypeLiveHeartBeat = 13,
    TBMPBPerformanceDataTypeBWAdaptInfoBeat = 14,
};


#define TBMPBAlarmDataKeyModule @"module"
#define TBMPBAlarmDataKeyPoint @"point"
#define TBMPBAlarmDataKeyType @"type"
#define TBMPBAlarmDataKeyArg @"arg"
#define TBMPBAlarmDataKeyErrorCode @"errorCode"
#define TBMPBAlarmDataKeyErrorMessage @"errorMessage"

typedef NS_ENUM(int32_t, TBMPBAlarmDataType) {
    TBMPBAlarmDataTypeLoadDynamicLibrary = 0,
    TBMPBAlarmDataTypeIsVideoOutInTime = 1,
    TBMPBAlarmDataTypeVideoCache = 2,
    TBMPBAlarmDataTypeAudioCache = 3,
    TBMPBAlarmDataTypeAVDiff = 4,
    TBMPBAlarmDataTypePlayerStatus = 5,
    TBMPBAlarmDataTypePlayerRefresh = 6,
    TBMPBAlarmDataTypeURLNoScheme = 7,
    TBMPBAlarmDataTypeQueryPolicyIP = 8,
    TBMPBAlarmDataTypeSEI = 9,
    TBMPBAlarmDataTypeCacheDuration = 10
};


#define TBMPBAlarmDataKeyStatus @"status"

typedef NS_ENUM(int32_t, TBMPBAlarmStatus) {
    TBMPBAlarmStatusFail = 0,
    TBMPBAlarmStatusSuccess = 1
};

typedef struct {
    NSUInteger major; // Major device model. e.g. 13 for iMac13,2
    NSUInteger minor; // Minor device model. e.g. 2 for iMac13,2
} TBMPBDeviceVersion;

@interface TBMPBUtil : NSObject

#pragma mark - Monitor
/*!
 * @abstract 上报性能式埋点数据。
 * 
 * @param data 性能埋点数据。数据格式包括：
 * - dimension：性能埋点维度信息(NSDictionary *)。维度信息的具体格式参加具体埋点。
 * - performance：性能埋点指标信息(NSDictionary *)。指标信息的具体格式参加具体埋点。
 *
 * @param type 监控点类型。可选值见枚举：TBMPBPerformanceDataType。
 *
 */
+ (void)commitPerformanceData:(NSDictionary *)data forType:(TBMPBPerformanceDataType)type forBusiness:(NSString *)businessID;

/*!
 * @abstract 上报告警埋点。
 *
 * @param data 告警埋点数据。数据格式可包括：
 * - arg：说明信息(NSString *)。
 * - errorCode：错误码(NSString *)。当上报失败状态时附带的错误码。
 * - errorMessage：错误信息(NSString *)。当上报失败状态时附带的错误信息。
 *
 * @param status 告警类型。可选值见枚举：TBMPBAlarmStatus。
 * @param type 监控点类型。可选值见枚举：TBMPBAlarmDataType。
 * @param businessID 业务 ID。
 */
+ (void)commitAlarmData:(NSDictionary *)data forStatus:(TBMPBAlarmStatus)status forType:(TBMPBAlarmDataType)type forBusiness:(NSString *)businessID;

#pragma mark - Log
/*!
 * @abstract 上报日志。
 * @param info 日志信息。
 * @param level 日志级别。
 * @param token 日志标识。
 * @param businessID 业务 ID。
 */
+ (void)logInfo:(NSString *)info withLogLevel:(TBMPBLogLevel)level logToken:(NSString *)token forBusiness:(NSString *)businessID;

#pragma mark - Config
/*!
 * @abstract 获取 Orange 配置。
 */
+ (NSDictionary *)orangeConfig;

+ (NSNumber *)currentNetworkStatus;
+ (NSString *)networkIMSI;
+ (NSString *)policyIPForHost:(NSString *)host;
+ (NSArray *)policyIPsForHost:(NSString *)host withProtocol:(NSString*)protocol;
+ (NSString *)userAgentInfo;
+ (NSString *)ABTestBucketInfoWithParameters:(NSDictionary*)parameters;
+ (BOOL) didMacroDefined:(NSString*)macro;

#pragma mark - Utility
+ (BOOL)loadFramework;
//+ (BOOL)loadDNAPlayerFramework;
+ (NSTimeInterval)timeStamp;
+ (TBMPBDeviceDisplay)deviceScreenSizeInInches;
+ (TBMPBDeviceVersion)deviceVersion;
+ (BOOL)RenderDegradeByDevice;
@end

@interface TBMPBScreenLockController : NSObject
+ (instancetype)sharedObject;
- (void)setSreenOn:(BOOL)on;
@end

@interface TBMPBDispatchOnceUtility : NSObject
+ (instancetype)sharedObject;
- (void) preloadHTTPDNSService;
- (void) preloadHTTPDNSServiceForAll;
@property (atomic, assign) int liveStreamBWInfoOfLastTenSeconds;
@end

@interface TBMPBPCDNManager : NSObject
+ (instancetype)sharedObject;
- (NSString*) getPCDNUrl:(NSString*) originalUrl;
@end
