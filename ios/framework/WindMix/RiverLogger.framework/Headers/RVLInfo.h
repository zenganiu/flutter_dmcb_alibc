//
//  RVLInfo.h
//  RiverLogger
//
//  Created by lianyu on 2020/4/16.
//  Copyright © 2020 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RiverLogger/RVLBuilder.h>
#import <RiverLogger/RVLDefines.h>

/**
 表示一条日志信息。
 */
@interface RVLInfo : NSObject

/**
 日志的级别。
 */
@property (nonatomic, assign) RVLLevel level;

/**
 日志的模块。
 */
@property (nonatomic, copy, nonnull, readonly) NSString * module;

/**
 日志的关联 ID。
 */
@property (nonatomic, copy, nullable) NSString * traceId;

/**
 日志的上一级关联 ID。
 */
@property (nonatomic, copy, nullable) NSString * parentId;

/**
 事件的名称。
 */
@property (nonatomic, copy, nullable) NSString * event;

/**
 事件的错误码。
 */
@property (nonatomic, copy, nullable) NSString * errorCode;

/**
 事件的错误信息。
 */
@property (nonatomic, copy, nullable) NSString * errorMsg;

/**
 事件实际发生的时间。
 */
@property (nonatomic, assign) RVLMillisecondTime timestamp;

/**
 日志的额外信息。
 */
@property (nonatomic, copy, nullable) NSString * ext;

/**
 已格式化的完整消息内容，适用于不支持按照结构化输出的场景。
 */
@property (nonatomic, copy, nullable, readonly) NSString * message;

/**
 使用指定的日志级别和模块初始化。
 */
- (instancetype _Nonnull)initWithLevel:(RVLLevel)level module:(NSString * _Nonnull)module;

@end
