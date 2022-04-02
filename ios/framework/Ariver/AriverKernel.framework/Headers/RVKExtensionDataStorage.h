//
//  RVKExtensionDataStorage.h
//  NebulaKernel
//
//  Created by theone on 2018/8/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKNode;

@protocol RVKExtensionDataStorageProtocol <NSObject>
@property(nonatomic, weak) RVKNode      *node;
@property(nonatomic) Class    dataTypeClass;
- (id)getData;
@end

@interface RVKExtensionDataStorage : NSObject <RVKExtensionDataStorageProtocol>
@property(nonatomic, weak) RVKNode  *node;
@property(nonatomic)       Class    dataTypeClass;
- (id)getData;
- (instancetype)initWithNode:(RVKNode *)node dataTypeClass:(Class)dataTypeClass;
@end
