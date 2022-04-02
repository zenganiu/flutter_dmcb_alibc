//
//  NSObject+WMLObjectProperty.h
//  Weaver
//
//  Created by lianyu on 2018/7/24.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import "WMLObjectProperty.h"
#import <Foundation/Foundation.h>

/**
 支持获取对象所有属性的扩展。
 */
@interface NSObject (WMLObjectProperty)

/**
 使用方根据需要重写，标记指定的属性是私有属性，不会被 wmlGetObjectProperties 方法获取。
 
 @return 私有属性的名称数组。
 */
+ (NSArray<NSString *> * _Nonnull)wmlPrivateProperties;

/**
 返回当前类型包含的所有自定义属性。
 */
+ (NSArray<WMLObjectProperty *> * _Nonnull)wmlGetObjectProperties;

@end
