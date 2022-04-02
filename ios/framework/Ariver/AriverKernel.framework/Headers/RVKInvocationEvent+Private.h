//
//  RVKInvocationEvent+Private.h
//  Poseidon
//
//  Created by chenwenhong on 15/9/2.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
#import "RVKInvocationEvent.h"

@interface RVKInvocationEvent (Private)

@property(nonatomic, copy) NSString                         *invocationName;
@property(nonatomic, strong) NSDictionary                   *invocationData; //当前携带的数据对象
@property(nonatomic, copy) NSString                         *url;
@property(nonatomic, strong) RVKJsApiResponseCallbackBlock  responseCallback;
@property(nonatomic, strong) RVKJsApi                       *jsApi;

@end
