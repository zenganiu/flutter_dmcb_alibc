//
//  RVKExtensionInterceptor.h
//  NebulaKernel
//
//  Created by theone on 2019/3/4.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RVKExtensionProxyContext;
@protocol RVKExtensionProtocol;

typedef id _Nullable (^RVKExtensionInterceptorCallback)(RVKExtensionProxyContext *context, NSInvocation *invocation);

@interface RVKExtensionInterceptorManager : NSObject
@property(nonatomic, copy) RVKExtensionInterceptorCallback  interceptorCallback;
+ (instancetype)defaultInterceptorManager ;
- (void)addExtensionDispatchInterceptor;
@end

NS_ASSUME_NONNULL_END
