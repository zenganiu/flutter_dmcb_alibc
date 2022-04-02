//
//  RVKPageEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKEvent.h"

@interface RVKPageEvent : RVKEvent

@property(nonatomic, strong) NSError *error;

+ (instancetype)allEvent;

+ (instancetype)createEvent;

+ (instancetype)loadStartEvent;

+ (instancetype)loadFirstByteEvent;

+ (instancetype)loadProgressEvent;

+ (instancetype)loadDomReadyEvent;

+ (instancetype)loadCompleteEvent;

+ (instancetype)loadErrorEvent:(NSError *)error;

+ (instancetype)destroyEvent;

@end
