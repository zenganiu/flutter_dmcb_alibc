/*
 * AlibcTradeOpenUrlHandleCenter.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeContainer 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "AlibcTradeOpenUrlContextModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeOpenUrlHandleCenter : NSObject

/**
 *  AlibcTradeOpenUrlHandleCenter 的单例对象
 */
+ (instancetype)sharedInstance;

- (void)openUrl:(nullable NSString *)url
        WithContext:(AlibcTradeOpenUrlContextModel *)context
    successCallBack:(nullable void (^)(NSDictionary *result))onSuccess
     failedCallBack:(nullable void (^)(NSError *__nullable error))onFailure;

@end

NS_ASSUME_NONNULL_END
