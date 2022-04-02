//
//  RVLLog.h
//  RiverLogger
//
//  Created by lianyu on 2020/3/6.
//  Copyright © 2020 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RiverLogger/RVLDefines.h>
#import <RiverLogger/RVLLogProtocol.h>

@interface RVLLog : NSObject

/**
 设置日志级别。
 */
+ (void)setLogLevel:(RVLLevel)logLevel;

/**
 获取日志级别，默认为 RVLLevelInfo。
 */
+ (RVLLevel)logLevel;

/**
 在某些场景或异常流程下，业务方主动调用，能够直接触发相关日志的上传，默认上传当天的日志。

 @param extraInfo 上传成功后附带的业务参数，由调用方自定义传入: @{@"反馈标题":,@"反馈内容":,@"分类名称":,@"昵称":,@"utdid":}
 */
+ (void)uploadLogFile:(NSDictionary * _Nullable)extraInfo;

/**
 注册指定的外部日志。
 */
+ (void)registerExternalLog:(id<RVLLogProtocol> _Nonnull)externalLog;

/**
 输出指定级别的日志，建议优先使用 RVLBuilder 构造标准格式的日志。
 
 @param level 日志级别
 @param module 日志模块
 @param message 日志消息
 */
+ (void)log:(RVLLevel)level module:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

#pragma mark - 远程日志

/**
 开启远程日志。
 
 @param params 远程服务的参数。
 @param callback 远程日志的开启回调。
 */
+ (void)openRemoteLog:(NSDictionary * _Nullable)params callback:(void (^_Nullable)(BOOL success, NSString * _Nullable message))callback;

/**
 提供远程日志的额外信息，用于在连接远程日志时供日志平台提取额外信息。
 
 @param info 远程日志的额外信息。
 */
+ (void)addRemoteLogInfo:(NSDictionary * _Nullable)info;

/**
 注册远程操作。
 
 @param action 远程操作。
 @param name 远程操作的名称。
 */
+ (void)registerRemoteAction:(void (^_Nonnull)(NSDictionary * _Nullable params))action withName:(NSString * _Nonnull)name;

@end
