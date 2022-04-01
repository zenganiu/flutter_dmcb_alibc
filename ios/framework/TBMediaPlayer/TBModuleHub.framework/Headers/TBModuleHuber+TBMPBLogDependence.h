//
//  TBModuleHuber+TBMPBLogDependence.h
//  TBModuleHub
//
//  Created by qiufu on 12/5/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <TBModuleHub/TBModuleHub.h>

@interface TBModuleHuber (TBMPBLogDependence)

/*!
 * @abstract 接收日志并发送给日志处理模块。
 * @param info 日志信息。日志信息的数据格式：
 * - module：模块名(NSString *)。根据接入方在使用 TBMPBPlayerView 时传入的 businessId 拼接而成，比如当 businessId = @"xxx" 时，对应的 module 为 @"TBMediaPlayerBundle-xxx"。
 * - level：日志级别(NSNumber *)->(NSInteger)。包括 0：Off；1：Error；2：Warning；3：Info；4：Debug。
 * - content：日志内容(NSString *)。
 */
- (void)TBModuleHuber_TBMPBLogDependence_logInfo:(NSDictionary *)info;

@end
