//
//  WMLMonitorResolvedStat.h
//  Weaver
//
//  Created by lianyu on 2018/7/25.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import "WMLMonitorStatProtocol.h"
#import <Foundation/Foundation.h>

/**
 表示解析后的性能埋点信息。
 */
@interface WMLMonitorResolvedStat : NSObject

/**
 性能埋点的模块名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * monitorModule;

/**
 性能埋点的监控点名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * monitorPoint;

/**
 维度属性名称列表。
 */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> * dimensions;

/**
 布尔维度属性名称列表。
 */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> * boolDimensions;

/**
 指标属性名称列表。
 */
@property (nonatomic, copy, readonly, nonnull) NSArray<NSString *> * measures;

/**
 埋点属性的总个数。
 */
@property (nonatomic, assign, readonly) NSUInteger count;

/**
 是否提交详细信息。
 */
@property (nonatomic, assign, readonly, getter=isCommitDetail) BOOL commitDetail;

/**
 性能埋点是否已完成初始化。
 */
@property (atomic, assign) BOOL initialized;

/**
 返回解析后的性能埋点信息。
 
 @return 埋点类的信息，如果是无效的埋点类，则返回 nil。
 */
+ (instancetype _Nullable)getResolvedStat:(id<WMLMonitorStatProtocol> _Nonnull)statInfo monitorName:(NSString * _Nullable)monitorName;

@end
