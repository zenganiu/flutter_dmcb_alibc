//
//  RVKExtensionProtocol4DataSource.h
//  AriverResource
//
//  Created by xuyouyang on 2019/8/20.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RVRAppResponse;
@class RVKProxyEvent;

NS_ASSUME_NONNULL_BEGIN

@protocol RVKExtensionProtocol4DataSource <NSObject>

@required
- (BOOL)handleResponse:(RVRAppResponse *)response event:(RVKProxyEvent *)event;

@end

NS_ASSUME_NONNULL_END
