//
//  RVAWeakObject.h
//  RVAService
//
//  Created by chenwenhong on 15/8/24.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RVAWeakObject : NSObject

@property(nonatomic, weak) id weakValue;

+ (instancetype)weakObject:(id)weakValue;

@end
