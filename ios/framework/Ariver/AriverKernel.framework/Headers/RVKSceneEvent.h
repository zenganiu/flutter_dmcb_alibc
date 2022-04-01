//
//  RVKSceneEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKEvent.h"

@interface RVKSceneEvent : RVKEvent

+ (instancetype)allEvent;

+ (instancetype)createEvent;

+ (instancetype)appearBeforeEvent;

+ (instancetype)appearAfterEvent;

+ (instancetype)loadEvent;

+ (instancetype)didLoadEvent;

+ (instancetype)readyEvent;

+ (instancetype)layoutEvent;

+ (instancetype)didUnLoadEvent;

+ (instancetype)disappearBeforeEvent;

+ (instancetype)disappearAfterEvent;

+ (instancetype)destroyEvent;

+ (instancetype)destroyBeforeEvent;

+ (instancetype)startFirstRequestEvent;

+ (instancetype)paramsInitEvent;
@end
