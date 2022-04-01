//
//  WMLProcedureTrackProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/9/17.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 过程跟踪。
 */
@protocol WMLProcedureTrackProtocol <NSObject>

@required

#pragma mark - 过程跟踪

/**
 开始一个过程。

 @param procedureName 过程名。
 @param properties 过程的相关属性。
 @param uuid 过程的唯一标识
 @param timestamp 过程的起始时间点。
 */
- (void)onProcedureBegin:(NSString * _Nonnull)procedureName properties:(NSDictionary * _Nullable)properties uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 触发过程的事件。
 
 @param procedureName 过程名。
 @param event 事件名。
 @param uuid 过程的唯一标识
 @param timestamp 事件的时间点。
 */
- (void)onProcedureEvent:(NSString * _Nonnull)procedureName event:(NSString * _Nonnull)event uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 触发过程的阶段。
 
 @param procedureName 过程名。
 @param stage 阶段名。
 @param uuid 过程的唯一标识
 @param timestamp 阶段的时间点。
 */
- (void)onProcedureStage:(NSString * _Nonnull)procedureName stage:(NSString * _Nonnull)stage uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 过程失败。
 
 @param procedureName 过程名。
 @param errorInfo 错误信息。
 @param uuid 过程的唯一标识
 @param timestamp 过程的结束时间点。
 */
- (void)onProcedureFailure:(NSString * _Nonnull)procedureName errorInfo:(NSDictionary<NSString *, NSString *> * _Nullable)errorInfo uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 过程成功。
 
 @param procedureName 过程名。
 @param properties 过程的相关属性。
 @param uuid 过程的唯一标识
 @param timestamp 过程的结束时间点。
 */
- (void)onProcedureSuccess:(NSString * _Nonnull)procedureName properties:(NSDictionary<NSString *, NSString *> * _Nullable)properties uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 暂停指定过程。
 
 @param procedureName 过程名。
 @param uuid 过程的唯一标识
 @param timestamp 过程的暂停时间点。
 */
- (void)onProcedurePause:(NSString * _Nonnull)procedureName uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 继续指定过程。
 
 @param procedureName 过程名。
 @param uuid 过程的唯一标识
 @param timestamp 过程的继续时间点。
 */
- (void)onProcedureResume:(NSString * _Nonnull)procedureName uuid:(NSString * _Nonnull)uuid timestamp:(NSTimeInterval)timestamp;

/**
 为指定过程添加属性。
 
 @param procedureName 过程名。
 @param properties 过程的相关属性。
 @param uuid 过程的唯一标识
 */
- (void)addProcedureProperties:(NSString * _Nonnull)procedureName properties:(NSDictionary<NSString *, NSString *> * _Nonnull)properties uuid:(NSString * _Nonnull)uuid;

/**
 为指定过程添加统计信息。
 
 @param procedureName 过程名。
 @param properties 过程的相关统计信息。
 @param uuid 过程的唯一标识
 */
- (void)addProcedureStatistic:(NSString * _Nonnull)procedureName properties:(NSDictionary<NSString *, NSString *> * _Nonnull)properties uuid:(NSString * _Nonnull)uuid;

#pragma mark - 子过程

/**
 开始一个子过程。
 
 @param procedureName 子过程名。
 @param parentPrecedureName 父过程名。
 @param parentUUID 父过程的唯一标识
 */
- (void)onSubProcedureBegin:(NSString * _Nonnull)procedureName parentPrecedureName:(NSString * _Nonnull)parentPrecedureName parentUUID:(NSString * _Nonnull)parentUUID;

/**
 子过程失败。
 
 @param procedureName 子过程名。
 @param parentPrecedureName 父过程名。
 @param parentUUID 父过程的唯一标识
 */
- (void)onSubProcedureFailure:(NSString * _Nonnull)procedureName parentPrecedureName:(NSString * _Nonnull)parentPrecedureName parentUUID:(NSString * _Nonnull)parentUUID;

/**
 子过程成功。

 @param procedureName 子过程名。
 @param parentPrecedureName 父过程名。
 @param parentUUID 父过程的唯一标识
 */
- (void)onSubProcedureSuccess:(NSString * _Nonnull)procedureName parentPrecedureName:(NSString * _Nonnull)parentPrecedureName parentUUID:(NSString * _Nonnull)parentUUID;

/**
 开始一个子过程。
 
 @param procedureName 子过程名。
 @param properties 携带的参数。
 @param parentPrecedureName 父过程名。
 @param parentUUID 父过程的唯一标识
 */
- (void)onSubProcedureBegin:(NSString * _Nonnull)procedureName properties:(NSDictionary<NSString *, NSString *> * _Nonnull)properties parentPrecedureName:(NSString * _Nonnull)parentPrecedureName parentUUID:(NSString * _Nonnull)parentUUID;

/**
 子过程失败。
 
 @param procedureName 子过程名。
 @param properties 携带的参数。
 @param parentPrecedureName 父过程名。
 @param parentUUID 父过程的唯一标识
 */
- (void)onSubProcedureFailure:(NSString * _Nonnull)procedureName properties:(NSDictionary<NSString *, NSString *> * _Nonnull)properties parentPrecedureName:(NSString * _Nonnull)parentPrecedureName parentUUID:(NSString * _Nonnull)parentUUID;

/**
 子过程成功。
 
 @param procedureName 子过程名。
 @param properties 携带的参数。
 @param parentPrecedureName 父过程名。
 @param parentUUID 父过程的唯一标识
 */
- (void)onSubProcedureSuccess:(NSString * _Nonnull)procedureName properties:(NSDictionary<NSString *, NSString *> * _Nullable)properties parentPrecedureName:(NSString * _Nonnull)parentPrecedureName parentUUID:(NSString * _Nonnull)parentUUID;

@end
