/*
 * AlibcTradeShowParams.h 
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
#import <AlibcTradeCommonSDK/AlibcOpenNativeFailedMode.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeShowParams : NSObject

/**
 是否需要用aliApp打开相关页面，目前支持 淘宝、天猫
 */
@property(nonatomic, assign) BOOL isNeedOpenByAliApp;

/**
 * applink使用，优先拉起的linkKey，手淘：@"taobao" 天猫:@"tmall"
 * 其中当设置天猫时发现未安装，如果安装手淘会拉起手淘
 */
@property(nonatomic, strong) NSString *linkKey;

/**
 唤起阿里App失败处理模式 默认唤端失败会拉起对应AliApp下载页
 */
@property(nonatomic, assign) AlibcOpenByAliAppFailedMode failMode;

/**
 媒体自定义降级url；注 failMode 需要设置 AlibcOpenInAppByCustomerDegradeUrl
 */
@property(nonatomic, copy)NSString *degradeUrl;


/** 使用百川webView支持push、present两种方式打开 默认为 present webView */
@property(nonatomic, assign)BOOL isPushBCWebView;

@property(nonatomic, copy) NSString *backUrl;

@end

NS_ASSUME_NONNULL_END
