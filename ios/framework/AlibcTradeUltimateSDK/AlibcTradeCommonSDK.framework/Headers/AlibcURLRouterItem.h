//
//  AlibcURLRouterItem.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/11/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 接入方可通过 openByCode方法打开提供对应服务的功能模块。
 */
@interface AlibcURLRouterItem : NSObject

@property (nonatomic, readonly, copy) NSString *handlerClsName;
@property (nonatomic, readonly, copy) NSString *host; //处理协议的host

@property (nonatomic, readonly, assign) BOOL isSingleton;

- (instancetype)initWithHandler:(NSString *)handlerClsName
                           host:(NSString *)host
                    isSingleton:(BOOL)isSingleton NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
