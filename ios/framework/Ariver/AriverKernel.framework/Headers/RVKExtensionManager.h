//
//  RVKExtensionManager.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVKExtensionProxy.h"

@class RVKNode;
@protocol RVKExtensionProtocol;
@protocol RVKExtensionPointLifeCycleProtocol;
@protocol RVKExtensionPoint;
@protocol RVKExtensionFilterProtocol;
@protocol RVKExtensionSorterProtocol;


@interface RVKExtensionManager : NSObject
+ (instancetype)defaultExtensionManager;

- (id)createExtensionPoint:(Protocol *)point
                                       node:(RVKNode *)node
                                   delegate:(id<RVKExtensionPointLifeCycleProtocol>)delegate;

- (id)createExtensionPoint:(Protocol *)point
                      node:(RVKNode *)node
                     event:(RVKEvent *)event
                  delegate:(id<RVKExtensionPointLifeCycleProtocol>)delegate;

- (void)setExtensionPointFilter:(Protocol *)point
                         filter:(id<RVKExtensionFilterProtocol>)filter;

- (void)setExtensionPointSorter:(Protocol *)point
                         sorter:(id<RVKExtensionSorterProtocol>)sorter;

+ (RVKExtensionProxyContext *)extension:(Protocol *)extension
                                   node:(RVKNode *)node
                               callback:(id<RVKExtensionPointLifeCycleProtocol>)callback;

- (void)unregisterExtensions:(NSArray<NSString *> *)extensionNames;
@end
