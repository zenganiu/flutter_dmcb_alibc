//
//  RVRConfigCenter+Private.h
//  AriverResource
//
//  Created by nico on 2019/4/21.
//  Copyright © 2019 Alipay. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "RVRProtocol.h"
#import "RVRConfigCenter.h"

@interface RVRConfigCenter (Private)
//日志监控相关，根据需要设置
@property(nonatomic, weak)__nullable id<RVRLogManagerDelegate> logManagerDelegate;
@property(nonatomic, weak)__nullable id<RVRMonitorDelegate> monitorDelegate;
@property(nonatomic, weak)__nullable id<RVRRequestCenterDelegate> requestCenterDelegate;
//业务相关配置，可不设置
@property(nonatomic, weak)__nullable id<RVRConfigManagerDelegate> configManagerDelegate;
@property(nonatomic, weak)__nullable id<RVRAppInterfaceDelegate> appInterfaceDelegate;
@end

