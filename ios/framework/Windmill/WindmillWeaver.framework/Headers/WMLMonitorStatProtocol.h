//
//  WMLMonitorStatProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/4/23.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 表示性能埋点的 Protocol，会根据包含的属性埋性能监控埋点：
   会将 NSString * 类型的属性作为维度；
   会将 BOOL 类型的属性转换为 @"true"/@"false" 作为维度。
   会将数字类型的属性作为指标；
   不会访问其它类型。
 如果不希望属性作为维度/指标使用，那么可以实现 ignoredMonitorProperties 方法。
 */
@protocol WMLMonitorStatProtocol <NSObject>

@required

/**
 性能埋点的名称，一般格式为 模块.监控点，如 Windmill.storage。
 未设置的话会忽略当前埋点。
 */
+ (NSString * _Nonnull)monitorName;

@optional

/**
 要被忽略的监控属性。
 
 @return 要被忽略的监控属性名称数组。
 */
+ (NSArray<NSString *> * _Nullable)ignoredMonitorProperties;

/**
 是否提交监控点的详细信息。
 设置为 YES 会禁止埋点通道的自动聚合等功能。
 */
+ (BOOL)isCommitDetail;

@end
