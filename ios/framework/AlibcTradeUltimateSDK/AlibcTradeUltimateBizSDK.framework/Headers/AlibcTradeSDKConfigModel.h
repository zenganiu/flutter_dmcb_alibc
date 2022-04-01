/*
 * AlibcTradeSDKConfigModel.h 
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
#import "AlibcTradeSDKCodeConfigModel.h"
#import "AlibcTradeSDKUrlTypeConfigModel.h"
#import "AlibcTradeRouterConfigModel.h"
#import "AlibcTradeSDKUrlTypeConfigModel.h"
#import "AlibcTradeUrlBizModel.h"

@interface AlibcTradeMiscConfigModel:AlibcJSONModel

@property(nonatomic,copy)NSString* failMode;
@property(nonatomic,copy)NSString* isNeedAlizf;
@property(nonatomic,copy)NSString* sampling;
@property(nonatomic,copy)NSString* monitorSampling;
@property(nonatomic,copy)NSString* loginDegarade;
@property(nonatomic,copy)NSString* isSyncForTaoke;
@property(nonatomic,copy)NSString* urlApi;
@property(nonatomic,copy)NSString* miniConf;
@property(nonatomic,copy)NSString* al;
@property(nonatomic,copy)NSString* extConfigApi;
@property(nonatomic,copy)NSString* closeFileLog; // 老开关，目前线上全部为NO,新版本不在使用
@property(nonatomic,copy)NSString* enableFileLog; // 没有值默认开启，可通过线上配置关闭日志写文件

@end

@interface AlibcTradeSDKConfigModel : AlibcJSONModel

@property(nonatomic,copy)NSString *version;
@property(nonatomic,copy)NSString *sign;
@property(nonatomic,assign)NSInteger st;
@property(nonatomic,copy)NSString *em;
@property(nonatomic,copy)NSArray *forbidByCode;
@property(nonatomic,copy)NSArray *addParamUrls;
@property(nonatomic,strong)AlibcTradeMiscConfigModel *misc;
@property(nonatomic,strong)NSArray<AlibcTradeUrlBizModel *>*bizPattern;
@property(nonatomic,strong)NSArray<AlibcTradeSDKCodeConfigModel *>*codeConfig;
@property(nonatomic,strong)NSArray<AlibcTradeSDKUrlTypeConfigModel *>*urlTypeConfig;
@property(nonatomic,strong)NSArray<AlibcTradeRouterConfigModel *>*routeConfig;

@end

