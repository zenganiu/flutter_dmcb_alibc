//
//  RVKExtensionProxyContext.h
//  NebulaKernel
//
//  Created by theone on 2018/8/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RVKExtensionPointLifeCycleProtocol;
@class RVKNode;
@class RVKEvent;

@interface RVKExtensionProxyContext : NSObject
@property(nonatomic, strong)  NSArray *targetList;
@property(nonatomic) Protocol *point;
@property(nonatomic) id<RVKExtensionPointLifeCycleProtocol>  delegate;
//for dataStorage
@property(nonatomic, weak)    RVKNode   *node;
@property(nonatomic, weak)    RVKEvent  *event;
@end
