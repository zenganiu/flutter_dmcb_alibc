//
//  RVPJSApiReqGetAppToken.h
//  AriverApi
//
//  Created by xuyouyang on 2019/4/16.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqGetAppToken : RVKJSApiRequestBase

// app名称
@property (nonatomic, strong) NSString *appName;
// app key
@property (nonatomic, strong) NSString *appKey;

@end

NS_ASSUME_NONNULL_END
