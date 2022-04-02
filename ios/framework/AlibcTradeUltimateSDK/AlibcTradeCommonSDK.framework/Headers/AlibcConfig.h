/*
 * AlibcConfig.h 
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
#import "AlibcOpenNativeFailedMode.h"

#ifndef AlibcConfig_h
#define AlibcConfig_h

#define YBHPSS @"ybhpss" //全链路打通数据参数

/** 环境,测试和预发,只有内网有效,外部使用只能用线上环境 */
typedef NS_ENUM(NSInteger, AlibcEnvironment) {
  /** 未定义环境 */
  AlibcEnvironmentNone = -1,
  /** 测试环境 */
  AlibcEnvironmentDaily = 0,
  /** 预发环境 */
  AlibcEnvironmentPreRelease,
  /** 线上环境 */
  AlibcEnvironmentRelease
};

/** 日志级别 */
typedef NS_ENUM(NSUInteger, AlibcLogLevel) {
  AlibcLogLevelDebug = 0,
  AlibcLogLevelInfo = 1,
  AlibcLogLevelPerf = 2,
  AlibcLogLevelWarn = 3,
  AlibcLogLevelError = 4,
};

/** SDK当前状态 */
typedef NS_ENUM(NSUInteger, AlibcSDKState) {
  /** SDK未进行初始化 */
  AlibcSDKStateUnInit = 0,
  /** SDK初始化当中 */
  AlibcSDKStateIniting = 1,
  /** SDK初始化完成 */
  AlibcSDKStateInitSucc = 2,
  /** SDK初始化失败 */
  AlibcSDKStateInitFailed = 3
};

NS_ASSUME_NONNULL_BEGIN

/** 配置 */
@interface AlibcConfig : NSObject
/** sdk初始化标识 */
@property(nonatomic, assign) AlibcSDKState sdkState;
/** sdk是否需要升级 */
@property(nonatomic, assign) BOOL isNeedUpdateSDK;
/** sdk强制升级文案 */
@property(nonatomic, copy) NSString *_Nullable errorMsg;
/** sdk是否允许唤端 */
@property(nonatomic,assign)BOOL isAllowLinkTaobao;

@property(atomic, assign) AlibcEnvironment environment;
@property(nonatomic, assign) AlibcLogLevel logLevel;
@property(nonatomic, strong) NSString *utdId;

@property(nonatomic, strong) NSString *appKey;
@property(nonatomic, strong) NSString *appVersion;
@property(nonatomic, strong) NSString *appName;
@property(nonatomic, copy) NSString *bcUA;
@property(nonatomic, copy) NSString *extUserAgent;
@property(nonatomic, copy, readonly) NSString *sdkVersion;

/** 百川ttid */
@property(nonatomic, copy, readonly) NSString *ttid;
/** 渠道相关 */
@property(nonatomic, copy, readwrite) NSString *channelName;
@property(nonatomic, copy, readwrite) NSString *channelType;
/* isvCode，tag*/
@property(nonatomic, copy, readwrite) NSString *isvCode;

@property(nonatomic, strong) NSString *openId;


/** 登录相关 */
@property(nonatomic,assign, readwrite)double lastAutoLoginTime;
@property(nonatomic,assign,readwrite)NSInteger loginFailedCount;
@property(nonatomic,assign,readwrite)NSInteger loginRetryCount;

@property (nonatomic, strong) NSDictionary *customUTParams;

+ (instancetype)sharedConfig;

/** 写入插件上下文 */
- (void)setValue:(nullable id)value forKey:(NSString *)key forModule:(NSString *)module;

/** 读取插件上下文 */
- (id)valueForKey:(NSString *)key forModule:(NSString *)module;

- (void)setDictionary:(NSDictionary *)dic forModule:(NSString *)module;

@end

NS_ASSUME_NONNULL_END

#endif
