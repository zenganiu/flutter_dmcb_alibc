//
//  RVKExtensionProxy.h
//  NebulaKernel
//
//  Created by theone on 2018/8/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVKNode.h"

@protocol RVKExtensionPointLifeCycleProtocol;
@class RVKExtensionProxyContext;

@interface RVKExtensionProxy<ProtocolType> : NSProxy
@property(nonatomic, readonly)  RVKExtensionProxyContext *context;
- (instancetype)initWithContext:(RVKExtensionProxyContext *)context;

- (ProtocolType)proxyWithExtension:(Protocol *)extension
                              node:(RVKNode *)node
                          callback:(id<RVKExtensionPointLifeCycleProtocol>)callback;

- (ProtocolType)proxyWithExtension:(Protocol *)extension
                              node:(RVKNode *)node
                             event:(RVKEvent *)event
                          callback:(id<RVKExtensionPointLifeCycleProtocol>)callback;
@end
