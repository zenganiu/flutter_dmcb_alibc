/*
 * AlibcURL.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommonSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#ifndef ALiURL_h
#define ALiURL_h

#import <Foundation/Foundation.h>

@interface AlibcURL : NSObject

+ (NSString *)urlEncoded:(NSString *)string;

+ (NSString *)urlDecoded:(NSString *)string;

/**
 * 移除 URL 中的查询参数和 Fragment。
 */
+ (NSString *)urlWithoutQueryAndFragment:(NSString *)url;
@end

#endif /* ALiURL_h */
