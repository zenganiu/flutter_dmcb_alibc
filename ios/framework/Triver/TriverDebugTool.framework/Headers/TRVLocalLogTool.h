//
//  TRVLocalLogTool.h
//  Triver
//
//  Created by zhongweitao on 2020/7/2.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//#import "TRVFloatingView.h"
#import <TriverDebugTool/TRVFloatingView.h>

@interface TRVLog : NSObject

@property (nonatomic, strong) NSString *group; // 分组
@property (nonatomic, strong) NSString *stage; // 阶段
@property (nonatomic, strong) NSString *title; // 标题
@property (nonatomic, assign) BOOL status;     // 成功失败
@property (nonatomic, strong) NSDictionary *logDetail; // 具体信息
@property (nonatomic, assign) BOOL stable;     // 是否驻留
@property (nonatomic, assign) NSTimeInterval timestamp;     // 日志时间戳

+ (TRVLog *)logInfoWithDic:(NSDictionary *)logDic;

- (NSString *)getLogDetailStr;

- (BOOL)containFailMsg:(NSString *)message;

@end

@interface TRVLogStage : NSObject

@property (nonatomic, strong) NSString *stage;
@property (nonatomic, assign) BOOL status;     // 成功失败
@property (nonatomic, strong) NSArray<TRVLog *> *logArray;
@property (nonatomic, assign) NSTimeInterval timestamp;     // 日志时间戳，该阶段最早时间

@end

@interface TRVLogGroup : NSObject

@property (nonatomic, strong) NSString *group;
@property (nonatomic, strong) NSArray<TRVLogStage *> *stageArray;

@end

@interface TRVLocalLogTool : NSObject<TRVFloatingViewDelegate>

@property (nonatomic, assign) BOOL enableLocalLog;

@property (nonatomic, assign) BOOL enableAutoShowFloating; // 套件内是否自动开启入口

@property (nonatomic, assign) BOOL enableDetailLog;

/// @brief 返回当前类型的共享实例。
+ (TRVLocalLogTool *)sharedInstance;

- (void)appendLocalLogInfo:(TRVLog *)logInfo;

- (void)appendLocalLogDic:(NSDictionary *)logDic;

- (void)clearAllLocalLog:(BOOL)clearStable;

- (void)clearAllLocalLog4Group:(NSString *)group;

/// @brief 获取方便用于展示的日志结构
- (NSArray<TRVLogGroup *> *)allLocalLogGroup;

/// @brief 打开悬浮按钮，通过parentViewController 打开调试工具
- (void)showFloatingInView:(UIView *)superView parentViewController:(UIViewController *)parentViewController;
/// @brief 关闭悬浮按钮
- (void)hideFloatingInView:(UIView *)superView;

/// @brief 直接打开调试工具
- (void)showLocalDebugTool:(UIViewController *)parentViewController;

@end
