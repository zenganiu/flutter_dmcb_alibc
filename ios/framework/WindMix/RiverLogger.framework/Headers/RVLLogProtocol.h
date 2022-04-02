//
//  RVLLogProtocol.h
//  RiverLogger
//
//  Created by lianyu on 2020/3/6.
//  Copyright © 2020 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RiverLogger/RVLDefines.h>
#import <RiverLogger/RVLInfo.h>

/**
 日志的协议，用于提供额外的日志输出通道。
 */
@protocol RVLLogProtocol <NSObject>

@required

/**
 当前通道的日志级别。
 */
- (RVLLevel)logLevel;

/**
 输出指定的日志。

 @param level 日志级别
 @param module 日志模块
 @param message 日志消息
 */
- (void)log:(RVLLevel)level module:(NSString * _Nonnull)module message:(NSString * _Nonnull)message;

@optional

/**
 输出指定的结构化日志。
 
 @param info 结构化日志信息
 */
- (void)log:(RVLInfo * _Nonnull)info;

/**
 在某些场景或异常流程下，业务方主动调用，能够直接触发相关日志的上传，默认上传当天的日志。

 @param extraInfo 上传成功后附带的业务参数，由调用方自定义传入: @{@"反馈标题":,@"反馈内容":,@"分类名称":,@"昵称":,@"utdid":}
 */
- (void)uploadLogFile:(NSDictionary * _Nullable)extraInfo;

@end
