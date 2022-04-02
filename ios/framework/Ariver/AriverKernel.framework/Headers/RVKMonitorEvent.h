//
//  RVKMontorEvent.h
//  NebulaPoseidon
//
//  Created by Glance on 2017/7/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#define kRVKLifeEventInit @"init"
#define kRVKLifeEventDealloc @"dealloc"

extern NSString * const RVKLifeEventInit;
extern NSString * const RVKLifeEventDealloc;


@interface RVKMonitorEvent : RVKEvent

@property (nonatomic, strong) NSString *lid; //支持传入较短的开关名供客户端动态开关使用
@property (nonatomic, strong) NSString *seedId;
@property (nonatomic, strong) NSString *bizType;
@property (nonatomic, copy) NSArray *params;

+ (RVKMonitorEvent *)logBeforeEvent:(NSString *)seedId bizType:(NSString *)bizType params:(NSArray *)params;
+ (RVKMonitorEvent *)logBeforeEvent:(NSString *)seedId bizType:(NSString *)bizType params:(NSArray *)params lid:(NSString *)lid;
+ (void)reportLifeEvent:(NSString *)lifeEvent withInstance:(NSObject *)instance;
+ (void)reportLifeEvent:(NSString *)lifeEvent withInstance:(NSObject *)instance extInfo:(NSString *)extInfo;

@end
