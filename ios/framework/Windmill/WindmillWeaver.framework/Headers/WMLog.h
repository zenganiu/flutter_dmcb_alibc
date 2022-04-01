//
//  WMLog.h
//  Weaver
//
//  Created by lianyu on 2018/4/5.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <stdarg.h>

/**
 Windmill 日志级别。
 */
typedef NS_ENUM(NSInteger, WMLogLevel) {
	WMLogLevelOff = 0,    // 关闭日志。
	WMLogLevelError = 1,  // 错误日志。
	WMLogLevelWarn = 2,   // 警告日志。
	WMLogLevelInfo = 3,   // 信息日志。
	WMLogLevelDebug = 4,  // 调试日志。
	WMLogLevelVerbose = 5 // 冗余日志。
};

@protocol WMLogProtocol;

/**
 Windmill 日志类。
 */
@interface WMLog : NSObject

/**
 设置 Windmill 日志级别。
 */
+ (void)setLogLevel:(WMLogLevel)logLevel;

/**
 获取 Windmill 日志级别，默认为 WMLogLevelOff。
 */
+ (WMLogLevel)logLevel;

/**
 在某些场景或异常流程下，业务方主动调用，能够直接上传TLog日志，默认上传当天的日志，如果当时客户端的网站环境是非wifi,
 会把上传指令存成离线任务。等待切换到wifi再上传。
 
 @param extraInfo 上传成功后附带的业务参数，由调用方自定义传入: @{@"反馈标题":,@"反馈内容":,@"分类名称":,@"昵称":,@"utdid":}
 */
+ (void)uploadLogFile:(NSDictionary * _Nullable)extraInfo;

/**
 检查指定级别的日志是否可以输出。
 一般情况下无需调用此方法，仅当需要做复杂的日志拼接时使用。

 @param level 要检查的日志级别。

 @return 如果可以输出，则为 YES；否则为 NO。
 */
+ (BOOL)checkLogLevel:(WMLogLevel)level;

#pragma mark - 外部日志

/**
 注册指定的外部日志，多个日志间需要自行实现串联。
 */
+ (void)registerExternalLog:(id<WMLogProtocol> _Nonnull)externalLog;

/**
 返回已注册的外部日志。
 */
+ (id<WMLogProtocol> _Nullable)registeredExternalLog;

#pragma mark - 日志对接

/**
 输出 Error 日志，可用于其它日志系统对接到 WMLog。
 
 @param module 日志模块
 @param format 日志格式化信息
 */
+ (void)error:(NSString * _Nonnull)module format:(NSString * _Nonnull)format arguments:(va_list)argList NS_FORMAT_FUNCTION(2, 0);

/**
 输出 Warn 日志，可用于其它日志系统对接到 WMLog。
 
 @param module 日志模块
 @param format 日志格式化信息
 */
+ (void)warn:(NSString * _Nonnull)module format:(NSString * _Nonnull)format arguments:(va_list)argList NS_FORMAT_FUNCTION(2, 0);

/**
 输出 Info 日志，可用于其它日志系统对接到 WMLog。
 
 @param module 日志模块
 @param format 日志格式化信息
 */
+ (void)info:(NSString * _Nonnull)module format:(NSString * _Nonnull)format arguments:(va_list)argList NS_FORMAT_FUNCTION(2, 0);

/**
 输出 Debug 日志，可用于其它日志系统对接到 WMLog。
 
 @param module 日志模块
 @param format 日志格式化信息
 */
+ (void)debug:(NSString * _Nonnull)module format:(NSString * _Nonnull)format arguments:(va_list)argList NS_FORMAT_FUNCTION(2, 0);

/**
 输出 Verbose 日志，可用于其它日志系统对接到 WMLog。
 
 @param module 日志模块
 @param format 日志格式化信息
 */
+ (void)verbose:(NSString * _Nonnull)module format:(NSString * _Nonnull)format arguments:(va_list)argList NS_FORMAT_FUNCTION(2, 0);

#pragma mark - Remote Log

/**
 开启远程日志。
 
 @param params 远程服务的参数。
 @param callback 远程日志的开启回调。
 */
+ (void)openRemoteLog:(NSDictionary * _Nullable)params callback:(void(^_Nullable)(BOOL success, NSString * _Nullable message))callback;

@end

#ifdef __cplusplus
extern "C" {
#endif

/**
 输出 Error 日志。
 */
void WMLogError(NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(1, 2);

/**
 输出 Warn 日志。
 */
void WMLogWarn(NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(1, 2);

/**
 输出 Info 日志。
 */
void WMLogInfo(NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(1, 2);

/**
 输出 Debug 日志。
 */
void WMLogDebug(NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(1, 2);

/**
 输出 Verbose 日志。
 */
void WMLogVerbose(NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(1, 2);

/**
 输出模块 Error 日志。
 */
void WMLogModuleError(NSString * _Nonnull module, NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 输出模块 Warn 日志。
 */
void WMLogModuleWarn(NSString * _Nonnull module, NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 输出模块 Info 日志。
 */
void WMLogModuleInfo(NSString * _Nonnull module, NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 输出模块 Debug 日志。
 */
void WMLogModuleDebug(NSString * _Nonnull module, NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 输出模块 Verbose 日志。
 */
void WMLogModuleVerbose(NSString * _Nonnull module, NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(2, 3);
	
#ifdef __cplusplus
}
#endif
