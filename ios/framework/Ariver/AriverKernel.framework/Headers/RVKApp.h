//
//  RVKSession.h
//  NebulaKernel
//
//  Created by theone on 2018/8/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "RVKNode.h"
#import "RVKSession.h"

@interface RVKApp : RVKSession <RVKNodeProtocol>
@property(nonatomic, strong) RVKSessionParam    *sessionParamOverride;
@property(nonatomic, assign)  BOOL isRVKNode;
@end
