//
//  TRVExternalJSApiProtocol.h
//  Runtime
//
//  Created by xuyouyang on 2019/8/14.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVExternalJSApiProtocol <NSObject>

- (BOOL)canHandleApi:(NSString *)apiName;

- (void)handleApi:(NSString *)apiName params:(NSDictionary *)params responseCallback:(RVKJsApiResponseCallbackBlock)responseCallback;

@end

NS_ASSUME_NONNULL_END
