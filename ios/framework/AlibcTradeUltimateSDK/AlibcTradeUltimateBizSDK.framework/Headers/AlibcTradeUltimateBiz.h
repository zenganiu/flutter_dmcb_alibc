/*
 * AlibcTradeUltimateBiz.h 
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
#import <AlibcTradeCommonSDK/AlibcConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeUltimateBiz : NSObject

/**
 *  初始化函数,初始化成功后方可正常使用SDK中的功能
 *
 *  @param onSuccess 初始化成功的回调
 *  @param onFailure 初始化失败的回调
 */
+ (void)asyncInitWithSuccess:(void (^)(void))onSuccess
                     failure:(void (^)(NSError *error))onFailure;


+ (void)setEnvironment:(AlibcEnvironment)env;

@end

NS_ASSUME_NONNULL_END
