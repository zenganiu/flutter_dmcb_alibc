//
// UTOirginalCustomHitBuilder.h
// 
// UserTrack 
// 开发团队：数据通道团队 
// UT答疑群：11791581(钉钉) 
// UT埋点平台答疑群：11779226(钉钉) 
// 
// Copyright (c) 2014-2017 Taobao. All rights reserved. 
//

#import <Foundation/Foundation.h>
#import "UTHitBuilder.h"
@interface UTOirginalCustomHitBuilder : UTHitBuilder

-(void) setPageName:(NSString *) pPage;

-(void) setEventId:(NSString *) pEventId;

-(void) setArg1:(NSString *) pArg1;

-(void) setArg2:(NSString *) pArg2;

-(void) setArg3:(NSString *) pArg3;

-(void) setArgs:(NSDictionary *) pArgs;

@end
