//
//  RVKExtension.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVKExtensionDataAwareProtocol.h"

#import "RVKNode.h"

@protocol RVKSchedulableProtocol;
@protocol RVKExtensionDataAwareProtocol;
@protocol RVKExtensionDataStorageProtocol;

@protocol RVKResultDeliverableProtocol <NSObject>
@property(nonatomic) id previousExtensionResult;
@end

@protocol RVKInterruptableProtocol <NSObject>
@property(nonatomic, assign)  BOOL shouldStopPropagation;
@property(nonatomic, assign)  BOOL shouldPreventDefault;
@end

@protocol RVKExtensionProtocol <NSObject>
@property(nonatomic, assign)  BOOL  didInited;
@property(nonatomic, strong)  id<RVKExtensionDataStorageProtocol>  dataStorage;
@property(nonatomic, weak)    RVKNode  *currentTargetNode;
@property(nonatomic, weak)    RVKEvent *currentEvent;
- (void)onInit;
@end

@interface RVKExtension : NSObject <RVKExtensionProtocol, RVKInterruptableProtocol, RVKResultDeliverableProtocol,RVKExtensionDataAwareProtocol>
@property(nonatomic, assign)  BOOL didInited;
@property(nonatomic, strong)  id<RVKExtensionDataStorageProtocol>  dataStorage;
@property(nonatomic)          id previousExtensionResult;
@property(nonatomic, assign)  BOOL shouldStopPropagation;
@property(nonatomic, assign)  BOOL shouldPreventDefault;
@property(nonatomic, weak)    RVKNode  *currentTargetNode;
@property(nonatomic, weak)    RVKEvent *currentEvent;
@end
