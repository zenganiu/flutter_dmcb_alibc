/*
 * NSURL+ALIURL.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommonSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#ifndef NSURL_ALIURL_h
#define NSURL_ALIURL_h



#import <Foundation/Foundation.h>

@interface NSURL (ALIURL)

/*
 * 判断是否相同url，会比较host，path，query 以及hash参数
 */
- (BOOL)alibc_isSameUrl:(NSURL *)url;


/*
 * 判断是否相同url，会比较host，path，忽略query 以及hash参数
 */
- (BOOL)alibc_isSameTypeUrl:(NSURL *)url isMiniApp:(BOOL)isMiniApp;

@end

#endif /* NSURL_ALIURL_h */
