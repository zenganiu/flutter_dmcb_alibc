/*
 * AlibcChannelUrlUtils.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeUltimateBizSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcChannelUrlUtils : NSObject

+ (instancetype)shareInstance;

- (NSString *)filterURL:(NSString *)url;

- (NSString *)filterURL:(NSString *)url WithParms:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
