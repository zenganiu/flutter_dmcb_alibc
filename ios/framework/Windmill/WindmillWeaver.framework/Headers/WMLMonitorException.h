//
//  WMLMonitorException.h
//  Weaver
//
//  Created by lianyu on 2018/7/5.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 异常的聚合类型。
 */
typedef NS_ENUM(NSUInteger, WMLMonitorExceptionAggregationType) {
	// 根据异常堆栈做聚合。
	WMLMonitorExceptionAggregationByStack,
	// 根据异常内容做聚合。
	WMLMonitorExceptionAggregationByContent,
};

/**
 表示异常的信息。
 */
@interface WMLMonitorException : NSObject

/**
 异常的业务类型。
 */
@property (nonatomic, copy, nullable, readonly) NSString * bizType;

/**
 异常的聚合类型。
 */
@property (nonatomic, assign, readonly) WMLMonitorExceptionAggregationType aggregationType;

/**
 异常内容，可能根据这里做聚合。
 */
@property (nonatomic, copy, nullable) NSString * content;

/**
 异常明细。
 */
@property (nonatomic, copy, nullable) NSString * detail;

/**
 业务版本信息。
 */
@property (nonatomic, copy, nullable) NSString * bizVersion;

/**
 当前堆栈。
 */
@property (nonatomic, copy, nullable) NSString * currentStack;

/**
 扩展字段 1。
 */
@property (nonatomic, copy, nullable) NSString * arg1;

/**
 扩展字段 2。
 */
@property (nonatomic, copy, nullable) NSString * arg2;

/**
 扩展字段 3。
 */
@property (nonatomic, copy, nullable) NSString * arg3;

/**
 其它扩展字段。
 */
@property (nonatomic, copy, nullable) NSDictionary * args;

/**
 使用指定的类型和聚合方式初始化。
 */
- (instancetype _Nonnull)initWithBizType:(NSString * _Nonnull)bizType aggregationType:(WMLMonitorExceptionAggregationType)aggregationType;

@end
