//
//  RVPJSApiReqVerifyIdentity.h
//  AriverApi
//
//  Created by xuyouyang on 2019/5/9.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqVerifyIdentity : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *verifyId;

@property (nonatomic, strong) NSString *verifyData;

@property (nonatomic, strong) NSDictionary *extParams;

@end

NS_ASSUME_NONNULL_END
