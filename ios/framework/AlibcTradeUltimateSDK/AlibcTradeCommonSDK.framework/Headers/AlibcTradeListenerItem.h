/*
 * AlibcTradeListenerItem.h 
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

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeListenerItem : NSObject

/**
 Handler 实例。
 */
@property (nonatomic, strong, readonly, nonnull) id instance;

/**
 Handler 类型。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * instanceType;

/**
 使用指定的实例初始化。
 */
- (instancetype _Nonnull)initWithInstance:(id _Nonnull)instance;

/**
 使用指定的实例类型初始化。
 */
- (instancetype _Nonnull)initWithClass:(Class _Nonnull)handlerClass isSingleton:(BOOL)singleton;

@end

NS_ASSUME_NONNULL_END
