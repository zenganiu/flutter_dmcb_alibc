//
//  TRVLogExtensionProtocol.h
//  Triver
//
//  Created by zhongweitao on 2020/7/21.
//

#import <Foundation/Foundation.h>

@protocol TRVLogExtensionProtocol <NSObject>

@optional
- (void)handleLog4EventId:(nullable NSString *)eventId
                     desc:(nullable NSString *)desc
                    stage:(nullable NSString *)stage
                    appId:(nullable NSString *)appId
                 pageName:(nullable NSString *)pageName
                     info:(nullable NSDictionary *)info;

@end
