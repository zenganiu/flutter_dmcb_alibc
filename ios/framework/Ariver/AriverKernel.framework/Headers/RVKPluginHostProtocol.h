//
//  PluginHostProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//插件管理协议
@protocol RVKPluginHostProtocol <NSObject>

- (void)addPlugin:(id<RVKPluginHostProtocol>)plugin;

- (void)removePlugin:(id<RVKPluginProtocol>)plugin;

@end
