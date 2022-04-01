//
// UTPlugin.h
// 
// UserTrack 
// 开发团队：数据通道团队 
// UT答疑群：11791581(钉钉) 
// UT埋点平台答疑群：11779226(钉钉) 
// 
// Copyright (c) 2014-2017 Taobao. All rights reserved. 
//

#import <Foundation/Foundation.h>

/**
 UTPlugin为特殊接口，一般为UT内部自用，误用会造成重大影响，使用前必须联系@苍井、@芮奇
 */
@protocol UTPlugin <NSObject>

- (NSSet *)getAttentionEventIds;

- (NSDictionary *)onBeforeEventDispatchWithPage:(NSString *)page
                                        eventId:(NSString *)eventId
                                           arg1:(NSString *)arg1
                                           arg2:(NSString *)arg2
                                           arg3:(NSString *)arg3
                                           args:(NSString *)args;

@end
