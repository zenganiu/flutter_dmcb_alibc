/*
 * AlibcLog.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommonSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, ALIBCLinkErrorCode) {
    ALIBCLinkErrorCodeNoSuite = 1 << 0,               // 不在套件内唤端
    ALIBCLinkErrorCodePageInterceptor = 1 << 1,       // 页面拦截唤端
    ALIBCLinkErrorCodeTinyAppLaunchFail = 1 << 2,     // 启动失败唤端（）
    ALIBCLinkErrorCodeTradePluginLoadFail  = 1 << 3,  // 商业化插件加载失败（未分佣）
    ALIBCLinkErrorCodeTradePluginJSError  = 1 << 4,   // 商业化插件执行失败（未分佣）
    ALIBCLinkErrorCodeLiveCps  = 1 << 5,              // 没有直播间的分佣跟踪（未分佣）
    ALIBCLinkErrorCodeDetailCps  = 1 << 6,            // 没有商品详情的分佣跟踪（未分佣）
};

#define kAlibcLinkErrorCodeKey @"bcLinkCode"

#ifndef AlibcLog_h
#define AlibcLog_h

#ifdef DEBUG
#define BCAssert(condition, info) \
do { \
@try { \
if (!(condition)) { \
if(tbim_check_debugger() == 0){      \
TLOG_ERROR(info)\
[NSException raise:@"Assert" format:@"%@",info];} \
else {TLOG_ALERT(info)} \
} \
}\
@catch (NSException *exception) {} \
} while (0);
#else
#define BCAssert(condition, info) \
do { \
if (!(condition)) {TLOG_ERROR(info)}\
} while (0);
#endif

#ifdef DEBUG
#define BCAssert_F(condition, frmt, ...) \
do { \
@try { \
if (!(condition)) { \
if(tbim_check_debugger() == 0){ \
TLOG_ERROR_F(frmt,##__VA_ARGS__) \
[NSException raise:@"Assert" format:@"Assert"];} \
else {TLOG_ALERT_F(frmt,##__VA_ARGS__)} \
} \
}\
@catch (NSException *exception) {} \
} while (0);
#else
#define BCAssert_F(condition, frmt, ...) \
do { \
if (!(condition)) { \
TLOG_ERROR_F(frmt,##__VA_ARGS__) \
} \
} while (0);
#endif

#define TLOG_ALERT(info) [[AlibcLog GetInstance] showAssertAlert:__FILE__ funcName:__func__ line: __LINE__ msg:info];
#define TLOG_ALERT_F(fmt, ...) [[AlibcLog GetInstance] showAssertAlert:__FILE__ funcName:__func__ line: __LINE__ msg:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];


#define TLOG_DEBUG_EMPTY [[AlibcLog GetInstance] logDebugMsg:__FILE__ funcName:__func__ line: __LINE__ msg:@""];
#define TLOG_INFO_EMPTY  [[AlibcLog GetInstance] logInfoMsg:__FILE__ funcName:__func__ line: __LINE__ msg:@""];
#define TLOG_WARN_EMPTY [[AlibcLog GetInstance] logWarnMsg:__FILE__ funcName:__func__ line: __LINE__ msg:@""];
#define TLOG_ERROR_EMPTY [[AlibcLog GetInstance] logErrorMsg:__FILE__ funcName:__func__ line: __LINE__ msg:@""];

#define TLOG_DEBUG(info) [[AlibcLog GetInstance] logDebugMsg:__FILE__  funcName:__func__ line:__LINE__ msg:info];
#define TLOG_INFO(info)  [[AlibcLog GetInstance] logInfoMsg:__FILE__ funcName:__func__ line:__LINE__ msg:info];
#define TLOG_WARN(info)  [[AlibcLog GetInstance] logWarnMsg:__FILE__  funcName:__func__ line: __LINE__ msg:info];
#define TLOG_ERROR(info) [[AlibcLog GetInstance] logErrorMsg:__FILE__  funcName:__func__ line: __LINE__ msg:info];

#define TLOG_DEBUG_F(fmt, ...) [[AlibcLog GetInstance] logDebugMsg:__FILE__ funcName:__func__ line: __LINE__ msg:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];
#define TLOG_INFO_F(fmt, ...)  [[AlibcLog GetInstance] logInfoMsg:__FILE__ funcName:__func__ line: __LINE__ msg:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];
#define TLOG_WARN_F(fmt, ...) [[AlibcLog GetInstance] logWarnMsg:__FILE__ funcName:__func__ line: __LINE__ msg:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];
#define TLOG_ERROR_F(fmt, ...) [[AlibcLog GetInstance] logErrorMsg:__FILE__ funcName:__func__ line: __LINE__ msg:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];


int tbim_check_debugger(void);


@interface AlibcLog : NSObject

+ (instancetype)GetInstance;

- (void)showAssertAlert:(const char *)file funcName:(const char *)func line:(int)line msg:(NSString *)msg;

- (void)logDebugMsg:(const char *)file funcName:(const char *)func line:(int)line msg:(NSString *)msg;

- (void)logInfoMsg:(const char *)file funcName:(const char *)func line:(int)line msg:(NSString *)msg;

- (void)logWarnMsg:(const char *)file funcName:(const char *)func line:(int)line msg:(NSString *)msg;

- (void)logErrorMsg:(const char *)file funcName:(const char *)func line:(int)line msg:(NSString *)msg;

- (void)setDebugLogOpen:(BOOL)isDebugLogOpen;

- (void)setFileLogEnable:(BOOL)enable;

- (void)updateFileHandle;

/// @brief 清理当前链路的日志
- (void)clearAllLocalLog;

/// @brief Suite 运行时
- (void)logLocalSuiteRuntime:(NSString *)title status:(BOOL)status detail:(NSDictionary *)detail;

/// @brief OpenSuite (单次链路)
- (void)logLocalOpenSuite:(NSString *)title status:(BOOL)status detail:(NSDictionary *)detail;

/// @brief 百川配置（基础配置、套件配置）
- (void)logLocalSDKConfig:(NSString *)title status:(BOOL)status detail:(NSDictionary *)detail;

/// @brief 百川SDK初始化
- (void)logLocalSDKInit:(NSString *)title status:(BOOL)status detail:(NSDictionary *)detail;

- (void)logLocalInfo:(NSString *)stage title:(NSString *)title status:(BOOL)status stable:(BOOL)stable detail:(NSDictionary *)detail;

/// @brief 是否关闭自检工具（默认开启）
- (void)enableLocalDebug:(BOOL)enable;

/// @brief 是否开启自动显示自检工具入口（默认关闭）
- (void)enableAutoShowDebug:(BOOL)enable;

/// @brief 手动显示自检工具
- (void)showLocalDebugTool:(UIViewController *)parentViewController;

/// @brief 上传当日日志文件到指定地址
- (void)uploadLogFile4Url:(NSString *)logUrl;

@end

#endif
