//
//  NSDictionary+RVAPrivate.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/2.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (RVAPrivate)

- (id)rva_objectForKey:(id)aKey defaultValue:(id)defaultValue;

@end
