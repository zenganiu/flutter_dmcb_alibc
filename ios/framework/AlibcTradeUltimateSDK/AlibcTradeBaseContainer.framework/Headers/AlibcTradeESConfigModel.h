/*
 * AlibcTradeESConfigModel.h 
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
#import <AlibcTradeCommonSDK/AlibcJSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeESBaseModel : AlibcJSONModel

@property(nonatomic,copy)NSString *code;
@property(nonatomic,copy)NSString *baseUrl;
@property(nonatomic,copy)NSString *type;
@property(nonatomic,copy)NSString *version;
@property(nonatomic,copy)NSString *appId;

@end

/// @brief 套件页面模块
@interface AlibcTradeESDynamicPluginModel : AlibcJSONModel

@property(nonatomic,copy)NSString *appId;
@property(nonatomic,copy)NSString *version;

@end

/// @brief 套件页面
@interface AlibcTradeESFuncsConfigModel : AlibcTradeESBaseModel

@property(nonatomic,copy)NSString *appType;
@property(nonatomic,copy)NSArray<AlibcTradeESDynamicPluginModel *> *dynamicPlugins;

@end

/// @brief 套件
@interface AlibcTradeESSuitConfigModel : AlibcTradeESBaseModel

@property(nonatomic,copy)NSArray<AlibcTradeESFuncsConfigModel *>*funcs;

@end

@interface AlibcTradeESMiscModel:AlibcJSONModel

@property (nonatomic,copy) NSString *logEnable;
@property (nonatomic,copy) NSString *logUrl;

@end

@interface AlibcTradeESConfigModel : AlibcJSONModel

@property (nonatomic,copy) NSArray<AlibcTradeESSuitConfigModel *>*suites;
@property (nonatomic,strong) AlibcTradeESMiscModel *misc;
@property (nonatomic,copy) NSString *sign;

@end

NS_ASSUME_NONNULL_END
