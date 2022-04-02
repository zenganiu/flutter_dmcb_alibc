//
//  RVKPluginManager+Private.h
//  NebulaPoseidon
//
//  Created by chenwenhong on 15/9/30.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface RVKPluginManager (Private)

- (id<RVKPluginProtocol>)RVKPlugin:(NSString *)pluginName; // 查找plugin，按照添加分组的逆序查找，直到默认分组

@end
