//
//  RVPJSApiResTradePay.h
//  AriverApi
//
//  Created by xuyouyang on 2019/4/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResTradePay : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *resultCode;
@property (nonatomic, strong) NSNumber *result;
@property (nonatomic, strong) NSString *callbackUrl;
@property (nonatomic, strong) NSString *memo;

@end

NS_ASSUME_NONNULL_END
