/*
 * AlibcTradeUrlHandleModel.h 
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
#import <UIKit/UIKit.h>
#import "AlibcTradeShowParams.h"
#import "AlibcTradeTaokeParams.h"
#import "AlibcTradeUrlParams.h"

#define kAlibcInnerNativeScheme @"bcnative"

/**
 *  原始页面类型
 */
typedef NS_ENUM(NSUInteger, AlibcPageType) {
    /** h5 */
    AlibcH5Page,
    /** 小程序 */
    AlibcMiniAppPage,
    /* Native*/
    AlibcNative
};


NS_ASSUME_NONNULL_BEGIN
@interface AlibcURLHandRequest : NSObject

/** 父页面VC */
@property(nonatomic,weak)UIViewController *parentViewController;

/** 待处理URL */
@property (nonatomic,strong)NSURL *URL;

/** 待匹配URL */
@property (nonatomic,strong)NSURL *matchURL;

/** 用户传入页面打开设置 */
@property (nonatomic,strong)AlibcTradeShowParams *showParams;

/** 用户传入的淘客参数 */
@property(nonatomic,strong)AlibcTradeTaokeParams *taokeParams;

@property (nonatomic,strong) NSDictionary *bizExtParams;

/** code */
@property (nonatomic,copy)NSString *code;

/** code url 参数列表*/
@property (nonatomic,copy)NSDictionary *paramDic;

/** trackParam 链路跟踪参数*/
@property (nonatomic,copy)NSDictionary *trackParam;

/// @brief 构建Reqeust如果传入recoveryId，就不会重新创建recoveryId
@property (nonatomic,copy)NSString *recoveryId;

@end

@interface AlibcURLOpenAction : NSObject

/** 处理业务容器标识 */
@property(nonatomic,copy) NSString *containerTag;

/** 打开目标URL */
@property(nonatomic,strong)NSURL *url;

/** 打开页面 URL 业务属性 */
@property(nonatomic,copy) NSString *bizCode;

/** 唤端module 业务参数 detail 为 itemId, shop 时 为 shopId*/
@property(nonatomic,copy)NSString *bizParam;

/** 唤端参数 */
@property(nonatomic,copy) NSString *linkKey;

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

@end

@interface AlibcURLProcessResult : NSObject

/** 原始URL */
@property(strong,nonatomic) NSURL *originalURL;

/** URL 页面类型 */
@property(nonatomic,assign) AlibcPageType urlType;
@property (nonatomic,copy) NSString *urlTypeStr;

/** 父页面VC */
@property(nonatomic,weak)UIViewController *parentViewController;

/** URL 打开方式集合 */
@property(nonatomic,copy)NSArray<AlibcURLOpenAction *>*actions;

/** 上层媒体打开设置参数 */
@property(nonatomic,strong)AlibcTradeShowParams *showParams;

/** 上层媒体传入的淘客参数 */
@property(nonatomic,strong)AlibcTradeTaokeParams *taokeParams;

@property (nonatomic,strong) NSDictionary *bizExtParams;

/** 上层媒体传入的业务参数 */
@property(nonatomic,strong)NSDictionary *urlParams;

/** 链路跟踪参数 */
@property(nonatomic,strong)NSDictionary *trackParam;

/** request 处理过程中 逻辑错误 直接返回上层 */
@property (nonatomic,strong)NSError *error;

/** sourceType(二跳) :web / miniapp*/
@property (nonatomic,copy)NSString *sourceType;

/** 是否是iframe */
@property (nonatomic,assign)BOOL isiFrame;

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

@property (nonatomic,copy)NSString *recoveryId;

@end


@interface AlibcTradeUrlHandleModel : NSObject

@end

NS_ASSUME_NONNULL_END
