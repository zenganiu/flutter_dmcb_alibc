//
//  RVKExtensionProtocol4JSApi.h
//  AriverKernel
//
//  Created by xuyouyang on 2019/4/15.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "RVKJsApi.h"

@protocol RVKExtensionProtocol4JSApi <NSObject>

@required
- (BOOL)canHandleApi:(NSString *)apiName;

- (void)handleApi:(NSString *)apiName params:(NSDictionary *)params responseCallback:(RVKJsApiResponseCallbackBlock)responseCallback;

@end
