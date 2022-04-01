//
//  AlibcURLActionHandlerProtocol.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/12/1.
//

#import <Foundation/Foundation.h>
#import "AlibcURLActionRequest.h"
#import "AlibcURLActionResponse.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^AlibcURLActionCompeltion)(AlibcURLActionResponse *response);

@protocol AlibcURLActionHandlerProtocol <NSObject>

@optional
/**
 初始化路由模块

 @param params 初始化参数
 */
- (void)setupModule:(NSDictionary *)params;

/**
 URL路由处理类遵循接口

 @param urlActionRequest 路由Request
 @param completion 回调
 */
- (void)handleURLActionRequest:(AlibcURLActionRequest *)urlActionRequest completion:(AlibcURLActionCompeltion)completion;

@end

NS_ASSUME_NONNULL_END
