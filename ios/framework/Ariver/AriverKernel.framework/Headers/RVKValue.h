//
//  RVKValue.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-18.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RVKValue : NSObject

+ (RVKValue *)valueWithWeakObject:(id)anObject;

- (id)weakObjectValue;

+ (RVKValue *)valueWithObject:(id)anObject;

- (id)objectValue;

@end
