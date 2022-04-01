//
//  TRVTraceDebugProtocol.h
//  Runtime
//
//  Created by 郑祯 on 2019/9/11.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVTraceDebugProtocol <NSObject>

#pragma mark - Event

/**
 * 接受 firstScreenPaint 首屏时间点。
 */
- (void)receiveFSP:(double)time;

/**
 * 接受小程序启动时间点。
 */
- (void)receiveOutset:(double)time;

/**
 * 接受诊断项信息（诊断成功）。
 *
 * @param name       诊断项名称。
 * @param measure    诊断项标准。
 * @param diagnosis  诊断结果。
 * @param suggestion 诊断项建议。
 */
- (void)receiveAuditDataWithName:(NSString *)name measure:(NSString *)measure diagnosis:(NSString *)diagnosis suggestion:(NSString *)suggestion;

/**
 * 接受诊断项信息（诊断失败）。
 *
 * @param name       诊断项名称。
 * @param measure    诊断项标准。
 * @param diagnosis  诊断项结果。
 * @param suggestion 诊断项建议。
 * @param titles     诊断项明细标题。（示例：["type", "size", "error"]）
 * @param values     诊断项明细列表内容。（示例：[["image", "421 kb", "load failure"],["file", "4410 kb", "no error"]]）
 */
- (void)receiveAuditDataWithName:(NSString *)name measure:(NSString *)measure diagnosis:(NSString *)diagnosis suggestion:(NSString *)suggestion titles:(NSArray *)titles values:(NSArray *)values;

/**
 * 将 CPU 时间转化为 UTC 时间。
 *
 * @param cupTime CPU 时间。
 *
 * @return UTC 时间（精确到毫秒）。
 */
+ (long long)convertTimeStandard:(double)cupTime;

@end

NS_ASSUME_NONNULL_END
