//
//  RVPJSApiReqOpenLocation.h
//  AriverApi
//
//  Created by xuyouyang on 2019/7/9.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 my.openLocation API 入参模型
 （钱包内还有一个业务属性，hidden，需要从 originParam 中获取）
 */
@interface RVPJSApiReqOpenLocation : RVKJSApiRequestBase

/**
 * 经度
 */
@property (nonatomic, strong) NSString *longitude;

/**
 * 纬度
 */
@property (nonatomic, strong) NSString *latitude;

/**
 * 位置名称
 */
@property (nonatomic, strong) NSString *name;

/**
 * 地址的详细说明
 */
@property (nonatomic, strong) NSString *address;

/**
 * 缩放比例，范围 3~19，默认为 15
 */
@property (nonatomic, strong) NSNumber *scale;

@end

NS_ASSUME_NONNULL_END
