/*
 * AlibcOpenNativeFailedMode.h 
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

/**
 拉起手淘失败后的处理策略
 - AlibcOpenAliAppDownloadPage: 当拉起手淘/天猫失败, 则跳转对应 App
 下载页面;默认选项
 - AlibcOpenInAppByCustomerDegradeUrl: 当拉起手淘/天猫失败,
 则在媒体App内以自定义降级URL降级打开
 - AlibcOpenDoNothing: 当拉起手淘/天猫失败, 不做额外操作
 */
typedef NS_ENUM(NSInteger, AlibcOpenByAliAppFailedMode) {
  AlibcOpenAliAppDownloadPage = 0,
  AlibcOpenInAppByCustomerDegradeUrl = 1,
  AlibcOpenDoNothing = 2
};

@interface AlibcOpenNativeFailedMode : NSObject

@end

NS_ASSUME_NONNULL_END
