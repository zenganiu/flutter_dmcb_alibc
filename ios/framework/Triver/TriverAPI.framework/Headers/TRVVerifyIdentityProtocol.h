//
//  TRVVerifyIdentityProtocol.h
//  API
//
//  Created by xuyouyang on 2019/5/29.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApi/RVPJSApiReqVerifyIdentity.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TRVVerifyIdentityCompleteBlock)(NSDictionary *params);

@protocol TRVVerifyIdentityProtocol <NSObject>

@required
- (void)verifyIdentityWithRequest:(RVPJSApiReqVerifyIdentity *)request complete:(TRVVerifyIdentityCompleteBlock)complete;

@end

NS_ASSUME_NONNULL_END
