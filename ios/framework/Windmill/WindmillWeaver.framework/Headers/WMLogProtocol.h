//
//  WMLogProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/4/5.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import "WMLog.h"
#import <Foundation/Foundation.h>

/**
 Windmill 的日志 protocol，用于增加额外的日志输出通道。
 */
@protocol WMLogProtocol <NSObject>

@required

/**
 日志的级别。
 保证在输出日志前正确的检查日志级别。
 */
- (WMLogLevel)logLevel;

/**
 在某些场景或异常流程下，业务方主动调用，能够直接上传TLog日志，默认上传当天的日志，如果当时客户端的网站环境是非wifi,
 会把上传指令存成离线任务。等待切换到wifi再上传。
 
 @param extraInfo 上传成功后附带的业务参数，由调用方自定义传入: @{@"反馈标题":,@"反馈内容":,@"分类名称":,@"昵称":,@"utdid":}
 */
- (void)uploadLogFile:(NSDictionary * _Nullable)extraInfo;

/**
 输出 Error 日志。
 
 @param module 日志模块
 @param message 日志消息
 */
- (void)error:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

/**
 输出 Warn 日志。
 
 @param module 日志模块
 @param message 日志消息
 */
- (void)warn:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

/**
 输出 Info 日志。
 
 @param module 日志模块
 @param message 日志消息
 */
- (void)info:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

/**
 输出 Debug 日志。
 
 @param module 日志模块
 @param message 日志消息
 */
- (void)debug:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

/**
 输出 Verbose 日志。
 
 @param module 日志模块
 @param message 日志消息
 */
- (void)verbose:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

@end
