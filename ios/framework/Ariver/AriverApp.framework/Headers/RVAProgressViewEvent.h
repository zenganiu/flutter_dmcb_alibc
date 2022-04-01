//
//  RVAProgressViewEvent.h
//  AriverApp
//
//  Created by chenwenhong on 15/10/13.
//  Copyright © 2015年 Alipay. All rights reserved.
//

//#import <NebulaPoseidon/NebulaPoseidon.h>
#import "RVAProgressViewProtocol.h"

@interface RVAProgressViewEvent : RVKEvent

@property(nonatomic, strong) id<RVAProgressViewProtocol> progressView;

+ (instancetype)allEvent:(id<RVAProgressViewProtocol>)progressView;

+ (instancetype)createBeforeEvent:(id<RVAProgressViewProtocol>)progressView;

+ (instancetype)createAfterEvent:(id<RVAProgressViewProtocol>)progressView;

@end

