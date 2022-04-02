//
//  WMLProcedureTrackInfo.h
//  Weaver
//
//  Created by lianyu on 2018/9/17.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 过程跟踪信息。
 */
@interface WMLProcedureTrackInfo : NSObject

/**
 过程的名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * name;

/**
 过程的唯一 ID。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * uuid;

/**
 使用指定的过程名称和唯一 ID 初始化。
 */
+ (WMLProcedureTrackInfo * _Nullable)procedureTrackInfoWithName:(NSString * _Nonnull)name uuid:(NSString * _Nonnull)uuid;

/**
 添加过程属性，请在过程开始之后再添加属性。
 */
- (void)addProperties:(NSDictionary<NSString *, NSString *> * _Nonnull)properties;

#pragma mark - 过程跟踪

/**
 开始当前过程。
 
 @param properties 过程的相关属性。
 */
- (void)onBegin:(NSDictionary<NSString *, NSString *> * _Nullable)properties;

/**
 触发事件。
 
 @param event 事件名。
 */
- (void)onEvent:(NSString * _Nonnull)event;

/**
 触发阶段。
 
 @param stage 阶段名。
 */
- (void)onStage:(NSString * _Nonnull)stage;

/**
 过程失败。
 
 @param errorInfo 错误信息。
 */
- (void)onFailure:(NSDictionary<NSString *, NSString *> * _Nullable)errorInfo;

/**
 过程成功。
 
 @param properties 过程的相关属性。
 */
- (void)onSuccess:(NSDictionary<NSString *, NSString *> * _Nullable)properties;

/**
 暂停当前过程。
 */
- (void)onPause;

/**
 继续当前过程。
 */
- (void)onResume;

#pragma mark - 过程跟踪（带时间戳）

/**
 开始当前过程。
 
 @param properties 过程的相关属性。
 @param timestamp 过程的起始时间点。
 */
- (void)onBegin:(NSDictionary<NSString *, NSString *> * _Nullable)properties timestamp:(NSTimeInterval)timestamp;

/**
 触发事件。
 
 @param event 事件名。
 @param timestamp 事件的时间点。
 */
- (void)onEvent:(NSString * _Nonnull)event timestamp:(NSTimeInterval)timestamp;

/**
 触发阶段。
 
 @param stage 阶段名。
 @param timestamp 阶段的时间点。
 */
- (void)onStage:(NSString * _Nonnull)stage timestamp:(NSTimeInterval)timestamp;

/**
 过程失败。
 
 @param errorInfo 错误信息。
 @param timestamp 过程的结束时间点。
 */
- (void)onFailure:(NSDictionary<NSString *, NSString *> * _Nullable)errorInfo timestamp:(NSTimeInterval)timestamp;

/**
 过程成功。
 
 @param properties 过程的相关属性。
 @param timestamp 过程的结束时间点。
 */
- (void)onSuccess:(NSDictionary<NSString *, NSString *> * _Nullable)properties timestamp:(NSTimeInterval)timestamp;

/**
 暂停当前过程。
 
 @param timestamp 过程的暂停时间点。
 */
- (void)onPause:(NSTimeInterval)timestamp;

/**
 继续当前过程。
 
 @param timestamp 过程的继续时间点。
 */
- (void)onResume:(NSTimeInterval)timestamp;

#pragma mark - 子过程

/**
 开始一个子过程。
 
 @param procedureName 子过程名。
 */
- (void)onSubProcedureBegin:(NSString * _Nonnull)procedureName;

/**
 子过程失败。
 
 @param procedureName 子过程名。
 */
- (void)onSubProcedureFailure:(NSString * _Nonnull)procedureName;

/**
 子过程成功。
 
 @param procedureName 子过程名。
 */
- (void)onSubProcedureSuccess:(NSString * _Nonnull)procedureName;

@end
