//
//  WMLMonitorProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/4/23.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import "WMLMonitorAlarm.h"
#import "WMLMonitorException.h"
#import "WMLHandlerFactory.h"
#import "WMLMonitorStatProtocol.h"
#import <Foundation/Foundation.h>

/**
 表示埋点协议。
 使用 [WMLHandlerFactory handlerForProtocol:@protocol(WMLMonitorProtocol)] 获取实现。
 */
@protocol WMLMonitorProtocol <NSObject>

@required

/**
 提交指定的性能埋点。
 
 @param statInfo 性能埋点信息
 */
- (void)commitStat:(id<WMLMonitorStatProtocol> _Nonnull)statInfo;

/**
 使用指定的名称提交性能埋点，用于需要动态修改 monitorName 的场景。
 
 @param statInfo 性能埋点信息
 @param monitorName 性能埋点的名称，一般格式为 模块.监控点，如 Windmill.storage。
 */
- (void)commitStat:(id<WMLMonitorStatProtocol> _Nonnull)statInfo monitorName:(NSString * _Nullable)monitorName;

/**
 提交指定的告警埋点。
 */
- (void)commitAlarm:(WMLMonitorAlarm * _Nonnull)alarmInfo;

@optional

/**
 提交指定的异常信息。
 */
- (void)commitException:(WMLMonitorException * _Nonnull)exception;

/**
 注册指定的额外信息提供者，用于在 Crash 等场景下提供额外的信息。
 */
- (void)registerAdditionalInfoProvider:(NSDictionary<NSString *, NSString *> * _Nullable (^_Nonnull)(void))provider;

@end

/**
 提交指定的性能埋点。
 */
NS_INLINE void WMLCommitStat(id<WMLMonitorStatProtocol> _Nonnull stat) {
	id<WMLMonitorProtocol> monitor = [WMLHandlerFactory handlerForProtocol:@protocol(WMLMonitorProtocol)];
	if (monitor) {
		[monitor commitStat:stat monitorName:nil];
	}
}

/**
 提交指定的告警埋点。
 */
NS_INLINE void WMLCommitAlarm(WMLMonitorAlarm * _Nonnull alarm) {
	id<WMLMonitorProtocol> monitor = [WMLHandlerFactory handlerForProtocol:@protocol(WMLMonitorProtocol)];
	if (monitor) {
		[monitor commitAlarm:alarm];
	}
}

/**
 注册指定的 Crash 异常信息提供者。
 */
NS_INLINE void WMLRegisterAdditionalInfoProvider(NSDictionary<NSString *, NSString *> * _Nullable (^_Nonnull provider)(void)) {
	if (provider) {
		id<WMLMonitorProtocol> monitor = [WMLHandlerFactory handlerForProtocol:@protocol(WMLMonitorProtocol)];
		if (monitor && [monitor respondsToSelector:@selector(registerAdditionalInfoProvider:)]) {
			[monitor registerAdditionalInfoProvider:provider];
		}
	}
}
