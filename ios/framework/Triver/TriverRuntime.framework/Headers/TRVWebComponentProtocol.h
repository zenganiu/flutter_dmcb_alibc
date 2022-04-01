//
//  TRVWebComponentProtocol.h
//  Runtime
//
//  Created by xuyouyang on 2019/12/19.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVWebComponentProtocol <NSObject>

@required
/**
 <web-view> 组件格外处理加载的 url
 */
- (NSURL *)extHandleURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
