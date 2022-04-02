//
//  RVLBuilder.h
//  RiverLogger
//
//  Created by lianyu on 2020/2/28.
//  Copyright © 2020 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RiverLogger/RVLDefines.h>

@class RVLBuilder;

/**
 传入指定的错误信息
 
 @param errorCode 错误码，可以是 NSString * 或 NSNumber * 或 NSError *
 @param errorMsg 错误消息，可以带有格式化参数。
 */
typedef RVLBuilder * _Nonnull (^RVLBuilderErrorHandler)(id _Nonnull errorCode, NSString * _Nullable errorMsg, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 用于构造结构化日志，最后请通过调用 done() 方法立即发出日志。
 具体日志结构可以参见 https://yuque.antfin-inc.com/cross_platform/dwrts1/oxtefg#KzTDQ
 */
@interface RVLBuilder : NSObject

/**
 向日志中附加指定的事件和关联 ID。
 */
- (RVLBuilder * _Nonnull (^_Nonnull)(NSString * _Nonnull eventName, NSString * _Nullable traceId))event;

/**
 向日志中附加指定的父级标识符。
 */
- (RVLBuilder * _Nonnull (^_Nonnull)(NSString * _Nonnull parentID))parentID;

/**
 向日志中附加指定的错误信息。
 */
- (RVLBuilderErrorHandler _Nonnull)error;

/**
 向日志中附加指定的时间戳信息（为 1970 年 1 月 1 日距今的毫秒）。
 */
- (RVLBuilder * _Nonnull (^_Nonnull)(RVLMillisecondTime timestamp))timestamp;

/**
 向日志中附加指定的键值对。
 */
- (RVLBuilder * _Nonnull (^_Nonnull)(NSString * _Nonnull name, id _Nullable value))append;

/**
 向日志中附加指定的键值对。
 */
- (RVLBuilder * _Nonnull (^_Nonnull)(NSDictionary * _Nullable value))appendExt;

/**
 上报日志。
 */
- (void (^_Nonnull)(void))done;

/**
 已废弃，统一使用 event 方法。
 */
- (RVLBuilder * _Nonnull (^_Nonnull)(NSString * _Nonnull pointName, ...))point DEPRECATED_ATTRIBUTE;

@end

#ifdef __cplusplus
extern "C" {
#endif

/**
 构造指定日志级别和模块名称的日志，最后请通过调用 done() 方法立即发出日志。
 */
RVLBuilder * _Nonnull RVLBuild(RVLLevel logLevel, NSString * _Nonnull moduleName);

/**
 生成 prefix_{ID} 格式的全局唯一 ID。这里采用全局自增的 ID，而非 prefix 独立的 ID。
 */
NSString * _Nonnull RVLGenerateID(NSString * _Nonnull prefix);

#ifdef __cplusplus
}
#endif
