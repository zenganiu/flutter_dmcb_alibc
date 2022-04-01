//
//  TRVLogProtocol.h
//  Triver
//
//  Created by zhongweitao on 2019/8/7.
//

#import <Foundation/Foundation.h>

@protocol TRVLogProtocol <NSObject>

/// @brief 主动上报日志
- (void)uploadLogFileForBizInfo:(NSDictionary*)bizInfo;

@end
