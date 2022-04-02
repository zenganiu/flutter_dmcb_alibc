/*
 * AlibcTradeOpenUrlContextModel.h 
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
#import <UIKit/UIKit.h>
#import <AlibcTradeUltimateBizSDK/AlibcTradeShowParams.h>
#import <AlibcTradeUltimateBizSDK/AlibcTradeTaokeParams.h>
#import <AlibcTradeUltimateBizSDK/AlibcTradeUrlParams.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeOpenUrlContextModel : NSObject

@property (nonatomic, weak) UIViewController *parentViewController;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *containerTag;
@property (nonatomic, copy) NSString *originalUrl;
@property (nonatomic, copy) NSString *code;

// 用户传参透传
/** 用户传入页面打开设置 */
@property (nonatomic, strong) AlibcTradeShowParams *showParams;

/** 用户传入的淘客参数 */
@property (nonatomic, strong) AlibcTradeTaokeParams *taokeParams;

@property (nonatomic, strong) NSDictionary *bizExtParams;

/** 链路跟踪参数 */
@property (nonatomic, copy) NSDictionary *trackParam;

/** url 参数列表*/
@property (nonatomic, copy) NSDictionary *paramDic;

@end

NS_ASSUME_NONNULL_END
