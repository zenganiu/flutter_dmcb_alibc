//
//  RVFullLinkStore.h
//  NebulaLogging
//
//  Created by 张光宇 on 2018/12/19.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AriverKernel/AriverKernel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVFullLinkStore : NSObject
@property(nonatomic,weak)UIViewController *currentViewController;
/*
 * scene级别的埋点，请调用此接口
 * 实现逻辑：
 *   若是首页面，则直接调[NBFullLinkStore store:appId]
 *   否则，从[scene getExpando:kFLStoreSceneExpandoKey]获取
 */
+ (instancetype)appStore:(NSString *)appId scene:(RVKScene * _Nullable)scene;
+ (instancetype)appStore:(NSString *)appId;

- (void)addTimeStub:(NSString *)phase withTime:(CFTimeInterval)mediaTime;

- (void)addTimeStub:(NSString *)phase;

- (void)addCostAttr:(NSString *)key value:(NSUInteger)costInMs;

- (void)addBizAttr:(NSString *)key value:(NSString *)value;

- (void)addAttributesFromDictionary:(NSDictionary *)dictionary;

- (NSString *)appId;

- (NSDictionary *)gatherDataAndClearCache;

+ (void)clearStore:(RVFullLinkStore *)store;

@end

NS_ASSUME_NONNULL_END
