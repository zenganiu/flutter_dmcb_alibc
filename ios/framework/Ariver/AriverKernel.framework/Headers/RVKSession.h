//
//  RVKSession.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-6.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKKernel.h"

@class RVKSessionParam;
@class RVKScene;
@class RVKPluginConfig;

//Session类：是指完成一系列动作的抽象。
@interface RVKSession : RVKKernel

@property(nonatomic, strong) NSString *sessionUUID;

- (RVKSessionParam *)createParam;

- (RVKScene *)currentScene;

/**
 *  @brief 给定一个sessionParam参数，创建一个Session对象，该session对象包含一个Scene对象
 *
 *  @date 2014-08-08
 *
 *  @param sessionParam 要创建所需的参数，不能为nil
 *
 *  @return 返回Session对象
 */
+ (instancetype)sessionWithSessionParam:(RVKSessionParam *)sessionParam
                           parentObject:(RVKKernel *)parentObject;

+ (instancetype)sessionWithSessionParam:(RVKSessionParam *)sessionParam
                                expando:(NSDictionary *)expandoDict
                           parentObject:(RVKKernel *)parentObject;

@end


//创建Session的参数类
@interface RVKSessionParam : NSObject

@property(nonatomic, strong) Class          viewControllerCls;
@property(nonatomic, strong) Class          contentViewCls;
@property(nonatomic, copy) NSString         *url;
@property(nonatomic, strong) NSDictionary   *expandParams;

@end


