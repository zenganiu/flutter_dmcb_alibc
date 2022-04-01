/*
 * AlibcTradeTaokeParams.h 
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
#import <AlibcTradeCommonSDK/AlibcJSONModel.h>

#ifndef AlibcTradeTaokeParams_h
#define AlibcTradeTaokeParams_h

/**
 *  统一的 key 写法
 */
static NSString *const AlibcTradeTaokeParamsPid = @"pid";
static NSString *const AlibcTradeTaokeParamsUnionID = @"unionId";
static NSString *const AlibcTradeTaokeParamsSubPid = @"subpid";

/** 淘客参数 */
@interface AlibcTradeTaokeParams : AlibcJSONModel
/** 淘客ID */
@property(nonatomic, copy) NSString *pid;

@property(nonatomic, copy) NSString *unionId;

// 三方pid
@property(nonatomic, copy) NSString *subPid;

// 媒体物料来源url
@property(nonatomic, copy) NSString *materialSourceUrl;

//渠道id
@property(nonatomic, copy) NSString *relationId;

@property(nonatomic, strong) NSDictionary *extParams;

- (NSDictionary *)taokeParamDictionary;

@end

#endif
