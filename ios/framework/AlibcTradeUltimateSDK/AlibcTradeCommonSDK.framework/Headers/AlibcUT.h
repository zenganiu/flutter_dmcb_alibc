/*
 * AlibcUT.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommonSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

UIKIT_EXTERN NSString * const kAlibcMonitorInitPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorEntrancePoint;
UIKIT_EXTERN NSString * const kAlibcMonitorOpenURLPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorOpenCodePoint;
UIKIT_EXTERN NSString * const kAlibcMonitorOpenComponentPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorOpenInterceptPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorContainerLoadPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorBCConfigPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorSuiteConfigPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorApplinkPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorTaokeBizPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorLoginPoint;
UIKIT_EXTERN NSString * const kAlibcMonitorConvertUrlPoint;

#define kAlibcRecoveryIdChange @"kAlibcRecoveryIdChange"
#define kAlibcRecoveryIdKey @"bcRecoveryId"

#ifndef AlibcUT_h
#define AlibcUT_h

#define ALiTRADE_TRACE_TRACKER_ID @"aliTradesdk"

typedef NSString AlibcUTEventID;
@class UIViewController;

FOUNDATION_EXTERN NSString *AlibcUTGlobalPropertySdkVersion;
FOUNDATION_EXTERN NSString *AlibcUTGlobalPropertyTTID;


/*
 * @brief 用于透出事件埋点
 */
FOUNDATION_EXTERN AlibcUTEventID *const AlibcUTEventID$2201;

/*
 * @brief 用于点击事件埋点
 */
FOUNDATION_EXTERN AlibcUTEventID *const AlibcUTEventID$2101;

FOUNDATION_EXTERN NSString *const AlibcUTArgsKeyYBHPSS;

FOUNDATION_EXTERN NSString *const AlibcUTArgsKeyYBHPSS_LABEL;

#define AlibcTradeSDKVersion @"5.0.0.7"

@interface AlibcUT : NSObject


/**
 初始化 ALiUT
 */
+ (void)initUT;


/**
 功能是否可用, 是否有 adapter 支撑功能

 @return 是否可用
 */
+ (BOOL)isAvailable;


/**
 是否三方ut

 @return 是否三方ut
 */
+ (BOOL)isThird;

/// @brief 更新用户信息
+ (void)updateUserAccount:(NSString *)pNick userid:(NSString *)pUserId;
+ (void)updateUserCount:(NSString *)uid andUserNick:(NSString *)userNick andDigest:(NSString *)uidDigest;

/**
 添加打点记录的便捷方法

 @param page pageName
 @param label arg1
 @param interval 无效兼容字段
 @param propertyDict args
 */
+ (void)addTraceLog:(NSString *)page
              label:(NSString *)label
           interval:(NSInteger)interval
          propertys:(NSDictionary *)propertyDict;

/**
 添加打点记录的便捷方法

 @param label arg1
 @param customParams args
*/
+ (void)addTraceLog:(NSString *)label customParams:(NSDictionary *)customParams;

/**
  添加打点记录的便捷方法

 @param label arg1
 @param propertyDict args
 */
+ (void)addTraceLog:(NSString *)label propertys:(NSDictionary *)propertyDict;


/**
 添加打点记录的便捷方法

 @param label arg1
 */
+ (void)addTraceLog:(NSString *)label;


/**
 添加打点记录的便捷方法

 @param eventID eventID
 @param arg1 arg1
 @param args args
 */
+ (void)addTradeLogWithEventID:(AlibcUTEventID *)eventID arg1:(NSString *)arg1 args:(NSDictionary *)args;


/**
 添加打点记录的便捷方法
 
 @param trackerID trackerID
 @param eventLabel arg1
 @param properties args
 */
+ (void)addTrackToTracker:(NSString *)trackerID eventLabel:(NSString *)eventLabel properties:(NSDictionary *)properties;


/**
 打点的标准实现

 @param trackerID track id
 @param eventID 事件 id
 @param pageName pageName
 @param arg1 arg1 == label
 @param arg2 arg2 description
 @param arg3 arg3 description
 @param args args == propertirs
 */
+ (void)addTradeLog:(NSString *)trackerID
            eventID:(NSString *)eventID
               page:(NSString *)pageName
               arg1:(NSString *)arg1
               arg2:(NSString *)arg2
               arg3:(NSString *)arg3
               args:(NSDictionary *)args;


/**
 供jsbridge打点

 @param dataDict dataDict
 @param pView webView
 @param pViewController vc
 @return return value
 */
+ (BOOL)h5UT:(NSDictionary *)dataDict view:(WKWebView *)pView viewController:(UIViewController *)pViewController;


/**
 设置 channel

 @param channel channel
 */
+ (void)setChannel:(NSString *)channel;


/**
 读取全局字段

 @param key 字段名
 @return 值
 */
+ (NSString *)globalPropertyForKey:(NSString *)key;


/**
 设置全局字段

 @param property 值
 @param key 字段名
 */
+ (void)setGlobalProperty:(NSString *)property forKey:(NSString *)key;

+ (void)setKeySampling:(NSUInteger)sampling;
+ (void)setNormalSampling:(NSUInteger)sampling;

#pragma mark - AppMonitor
/// @brief 计数埋点
+ (void)commitCountWithPoint:(NSString *)monitorPoint value:(double)value args:(NSDictionary *)args;

/// @brief 告警埋点
+ (void)commitAlarmWithPoint:(NSString *)pointName args:(NSDictionary *)args success:(BOOL)success errorCode:(NSString *)errorCode errorMsg:(NSString *)errorMsg;

/// @brief 性能埋点
+ (void)commitStatWithPoint:(NSString *)monitorPoint dimensionValues:(NSDictionary *)dictDimensionValues measureValues:(NSDictionary *)dictMeasureValues;

@end

@protocol AlibcUTAdapter <NSObject>

#pragma mark - Initialize

@required

- (void)initWithAppkey:(NSString *)appkey;


#pragma mark - Configure

@required
- (void)setChannel:(NSString *)channel;

@required
- (NSString *)globalPropertyForKey:(NSString *)key asTracker:(NSString *)trackerID;

@required
- (void)setGlobalProperty:(NSString *)property forKey:(NSString *)key asTracker:(NSString *)trackerID;


#pragma mark - Commit

@required
- (void)addTradeLog:(NSString *)trackerID
            eventID:(NSString *)eventID
               page:(NSString *)pageName
               arg1:(NSString *)arg1
               arg2:(NSString *)arg2
               arg3:(NSString *)arg3
               args:(NSDictionary *)args;

@optional
- (void)h5UT:(NSDictionary *)dataDict view:(WKWebView *)pView viewController:(UIViewController *)pViewController;

@optional
- (void)setAppVersion:(NSString *)appVersin;

@optional
- (void)updateUserAccount:(NSString *)pNick userid:(NSString *)pUserId;
@optional
- (void)updateUserCount:(NSString *)uid andUserNick:(NSString *)userNick andDigest:(NSString *)uidDigest;

#pragma mark - Other

@optional
- (BOOL)isThird;

#pragma mark - AppMonitor
/// @brief 计数埋点
- (void)commitCountWithPoint:(NSString *)monitorPoint value:(double)value args:(id)args;

/// @brief 告警埋点
- (void)commitAlarmWithPoint:(NSString *)pointName args:(id)args success:(BOOL)success errorCode:(NSString *)errorCode errorMsg:(NSString *)errorMsg;

/// @brief 性能埋点
- (void)commitStatWithPoint:(NSString *)monitorPoint dimensionValues:(NSDictionary *)dictDimensionValues measureValues:(NSDictionary *)dictMeasureValues;

@end


#define AlibcNSStringify(a) @#a
#define AlibcAppendUTSuffixUtil AlibcNSStringify(_aliTradesdk_)AlibcTradeSDKVersion

#endif
