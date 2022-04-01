//
//  RVPJSApiResGetAppToken.h
//  AriverApi
//
//  Created by xuyouyang on 2019/4/16.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, RVPJSApiGetAppTokenError) {
	// 获取token的时候网络出错
	RVPJSApiGetAppTokenConnectionError = 11,
	// 传入的appName或者appKey无效
	RVPJSApiGetAppTokenInvalidParamError = 12,
};

@interface RVPJSApiResGetAppToken : RVKJSApiResponseBase

// app名称
@property (nonatomic, strong) NSString *appToken;

@end

NS_ASSUME_NONNULL_END
