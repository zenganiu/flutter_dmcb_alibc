/*
 * AlibcTradeContainerContextModel.h 
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
#import <WebKit/WebKit.h>
#import <AlibcTradeCommonSDK/AlibcOpenNativeFailedMode.h>
#import <AlibcTradeCommonSDK/AlibcLog.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTradeContainerContextModel : NSObject

@property (nonatomic,weak)UIViewController *parentViewController;
@property (nonatomic,copy)NSString *url;
@property (nonatomic,copy)NSString *containerTag;
@property (nonatomic,copy)NSString *originalUrl;
@property (nonatomic,assign)BOOL isiFrame;// 是否为ifame web专用

// 用户默认唤起目标客户端
@property(nonatomic, strong) NSString *linkKey;

/**
 唤起阿里App失败处理模式 默认唤端失败会拉起对应AliApp下载页
 */
@property(nonatomic, assign) AlibcOpenByAliAppFailedMode failMode;

@property(nonatomic, strong) NSString *backUrl;

/**
 媒体自定义降级url；注 failMode 需要设置 AlibcOpenInAppByCustomerDegradeUrl
 */
@property(nonatomic, copy)NSString *degradeUrl;

/** 使用百川webView支持push、present两种方式打开 默认为 present webView */
@property(nonatomic, assign)BOOL isPushBCWebView;

/**
 淘客参数
 */
@property(nonatomic,strong)id taokeParams;

@property(nonatomic,strong) NSDictionary *bizExtParams;


@property(nonatomic,strong) NSDictionary *frontParam;

/**
 业务参数
 */
@property(nonatomic,strong)NSDictionary* bizParams;

/** 链路跟踪参数 */
@property(nonatomic,strong)NSDictionary *trackParam;

/**
 扩展参数
 */
@property(nonatomic,strong)NSDictionary *extParam;

/** 套件类型 */
@property (nonatomic,copy)NSString *suitType;
@property (nonatomic,copy)NSString *suiteCode;

/** 页面类型 */
@property (nonatomic,copy)NSString *pageType;
@property (nonatomic,copy)NSString *pageCode;


/// @brief 单词链路
@property (nonatomic,copy) NSString *recoveryId;

/// @brief 唤端前的百川出错状态
@property (nonatomic,assign) ALIBCLinkErrorCode linkErrorCode;

@end

NS_ASSUME_NONNULL_END
