/*
 * AlibcTradeContainerProcessUrlResult.h 
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

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeContainerProcessUrlResult : NSObject

/**
 是否已被其他容器处理
 */
@property (nonatomic,assign)BOOL isHandled;


/**
 是否需要刷新
 */
@property (nonatomic,assign)BOOL isNeedReload;

/**
 是否需要smartGoBack
 */
@property (nonatomic,assign)BOOL isNeedGoBack;

/**
 url是否已被更改
 */
@property (nonatomic,assign)BOOL isChangedUrl;

/**
 处理后的url
 */
@property (nonatomic,copy)NSURL *resultUrl;

@end

NS_ASSUME_NONNULL_END
