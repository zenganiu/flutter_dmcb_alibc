//
//  NSArray+RVAPrivate.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (RVAPrivate)

- (id)rva_objectAtIndex:(NSUInteger)index defaultValue:(id)defaultValue;

@end
