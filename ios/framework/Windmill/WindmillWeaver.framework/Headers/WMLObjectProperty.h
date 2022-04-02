//
//  WMLObjectProperty.h
//  Monitor
//
//  Created by lianyu on 2018/4/24.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

/**
 表示对象属性信息。
 */
@interface WMLObjectProperty : NSObject

/**
 属性的名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * name;

/**
 属性的类型字符串。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * typeString;

/**
 属性的类型代码。
 */
@property (nonatomic, assign, readonly) unichar typeCode;

/**
 若属性是对象类型（非 id），则为对应的 Class，否则为 nil。
 */
@property (nonatomic, assign, readonly, nullable) Class type;

/**
 返回是否是布尔类型。
 由于不同环境下，BOOL 可能是 bool 也可能是 signed char，因此这里可能会将 signed char 误认为 BOOL。
 */
- (BOOL)isBOOLType;

/**
 返回是否是数字类型。
 */
- (BOOL)isNumberType;

/**
 返回指定属性的 WMLObjectProperty 包装。
 */
+ (WMLObjectProperty * _Nullable)propertyWithObjcProperty:(objc_property_t _Nonnull)property;

@end
