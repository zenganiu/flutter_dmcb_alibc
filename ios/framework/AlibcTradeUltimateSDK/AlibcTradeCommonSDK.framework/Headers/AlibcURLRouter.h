//
//  AlibcURLRouter.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/11/30.
//

#import <Foundation/Foundation.h>
#import "AlibcURLActionRequest.h"
#import "AlibcURLActionResponse.h"
#import "AlibcURLActionHandlerProtocol.h"

@interface AlibcURLRouter : NSObject

+ (instancetype)sharedInstance;

/**
 注册URL处理类
 @param handlerClass 处理类名
 @param host 处理的url.host
 @param isSingleton 是否单例
 */
- (void)registerURLHandler:(NSString *)handlerClass host:(NSString *)host isSingleton:(BOOL)isSingleton;

/**
 判断是否能处理
 @param url 路由url
 @return 是否能处理
 */
- (BOOL)canHandleURL:(NSURL *)url;

#pragma mark - Init

/**
 路由处理函数
 @param urlActionRequest 路由Request
 @param completion 回调
 */
- (void)processURLActionRequest:(AlibcURLActionRequest *)urlActionRequest completion:(AlibcURLActionCompeltion)completion;

#pragma mark - Init

/**
 初始化所有模块
 @param params 初始化参数
 */
- (void)setupAllModules:(NSDictionary *)params;

@end
