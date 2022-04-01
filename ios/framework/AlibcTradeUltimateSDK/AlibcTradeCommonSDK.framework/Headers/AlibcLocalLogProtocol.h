//
//  AlibcLocalLogProtocol.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/7/6.
//

#import <Foundation/Foundation.h>

@protocol AlibcLocalLogProtocol <NSObject>

@optional
/// @brief 记录日志
- (void)logLocalInfo:(NSString *)stage title:(NSString *)title status:(BOOL)status stable:(BOOL)stable detail:(NSDictionary *)detail;

/// @brief 清理日志
- (void)clearAllLocalLog;

/// @brief 是否关闭自检工具（默认开启）
- (void)enableLocalDebug:(BOOL)enable;

/// @brief 是否开启自动显示自检工具入口（默认关闭）
- (void)enableAutoShowDebug:(BOOL)enable;

/// @brief 手动显示自检工具
- (void)showLocalDebugTool:(UIViewController *)parentViewController;

@end
