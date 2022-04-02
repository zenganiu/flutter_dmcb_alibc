/*
 * AlibcTradeContainerPageLifeCycleEventListenerProtocol.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeBaseContainer 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "AlibcTradeContainerEventListenerBaseProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AlibcTradeContainerPageLifeCycleEventListenerProtocol <AlibcTradeContainerEventListenerBaseProtocol>

/**
 页面将要加载
*/
- (void)pageWillLoad:(AlibcTradeContainerContextModel *)context;

/**
 页面加载完成
*/
- (void)pageDidLoad:(AlibcTradeContainerContextModel *)context;

/**
 页面加载失败
*/
- (void)pageLoadFailed:(AlibcTradeContainerContextModel *)context;

/**
 页面将要展现
*/
- (void)pageWillAppear:(AlibcTradeContainerContextModel *)context;

/**
 页面已经展现
*/
- (void)pageDidAppear:(AlibcTradeContainerContextModel *)context;

/**
 页面将要关闭
*/
- (void)pageWillDisAppear:(AlibcTradeContainerContextModel *)context;

/**
 页面已经关闭
*/
- (void)pageDidDisAppear:(AlibcTradeContainerContextModel *)context;

@end

NS_ASSUME_NONNULL_END
