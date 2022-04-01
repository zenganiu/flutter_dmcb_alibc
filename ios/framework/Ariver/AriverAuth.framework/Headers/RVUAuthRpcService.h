//
//  RVUAuthRpcService.h
//  AriverAuth
//
//  Created by CaiXiaomin on 2019/5/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVUAuthRpcService_h
#define RVUAuthRpcService_h

@class RVKContext;
typedef void(^rvsAuthcodeCallback)(id data);

@protocol RVUAuthRpcService <NSObject>

- (void)authWithParams:(NSDictionary *)params  callback:(rvsAuthcodeCallback)callback;
- (void)auth:(RVKContext *)context withParams:(NSDictionary *)params  callback:(rvsAuthcodeCallback)callback supportH5Mode:(BOOL)supportH5Mode;

@end

#endif /* RVUAuthRpcService_h */
