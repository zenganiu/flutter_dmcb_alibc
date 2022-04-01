//
//  RVKProxyMonitorEvent.h
//  Poseidon
//
//  Created by chenwenhong on 15-1-29.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

@class RVKConnectionProfile;

@interface RVKProxyMonitorEvent : RVKEvent

@property(nonatomic, readonly, copy) NSString   *channelId;
@property(nonatomic) RVKConnectionProfile       *profile;

+ (instancetype)monitorEvent:(NSString *)channelId profile:(RVKConnectionProfile *)profile;

@end
