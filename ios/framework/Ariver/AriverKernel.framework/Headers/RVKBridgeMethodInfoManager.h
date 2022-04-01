//
//  RVKBridgeMethodInfoManager.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class RVKBridgeMethodInfo;

@interface RVKBridgeMethodInfoManager : NSObject
+ (instancetype)defaultMethodInfoManager;
- (void)addMethodInfo:(RVKBridgeMethodInfo *)info;
- (RVKBridgeMethodInfo *)findBridgeMethodInfoWithJsapiName:(NSString *)jsapiName;
@end

NS_ASSUME_NONNULL_END
