//
//  PluginProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14/7/17.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RVKEvent;
@class RVKKernel;

//插件协议
@protocol RVKPluginProtocol <NSObject>

@property(nonatomic, readonly, copy) NSString   *name; // 插件名称

@required
- (void)handleEvent:(RVKEvent *)event; // 插件事件处理函数

@optional
- (void)associateWeakTarget:(RVKKernel *)weakTarget; // 请用weak，每添加一个事件调用一次

- (int)priority; // 每添加一个事件调用一次

@end
