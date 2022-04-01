//
//  RVKNode.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AriverKernel/RVKKernel.h>

@protocol RVKNodeProtocol <NSObject>
@property(nonatomic, assign)  BOOL isRVKNode;
@end


@interface RVKNode : RVKKernel <RVKExpandoProtocol,RVKNodeProtocol>
@property(nonatomic, assign)  BOOL isRVKNode;
@end
