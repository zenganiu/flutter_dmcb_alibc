/*
 * AlibcReflectionUtil.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommonSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>

#ifndef AlibcReflectionUtil_h
#define AlibcReflectionUtil_h

@interface AlibcReflectionUtil : NSObject
+ (id)getSharedInstance:(NSString *)className;

+ (id)getInstance:(NSString *)className instanceMethodName:(NSString *)instanceMethodName;

+ (id)executeInstanceMethod:(NSString *)methodName instance:(id)instance params:(NSArray *)params;

+ (id)executeClassMethod:(NSString *)methodName clazz:(Class)clazz;

+ (id)executeInstanceMethod:(NSString *)methodName instanceAndargs:(id)instance, ...;
@end


#define BC_MAKE_SELECTOR(var_name, sel_name) _Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wundeclared-selector\"")\
SEL var_name = @selector(sel_name);\
_Pragma("clang diagnostic pop")

#define BC_FETCH_CLASS(className) [NSClassFromString(@#className) class]

#endif
