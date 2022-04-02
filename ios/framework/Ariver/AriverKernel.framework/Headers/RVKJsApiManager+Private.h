//
//  RVKJsApiManager+Private.h
//  NebulaPoseidon
//
//  Created by chenwenhong on 15/9/30.
//  Copyright © 2015年 Alipay. All rights reserved.
//


@interface RVKJsApiManager (Private)

- (RVKJsApi *)RVKJsApi:(NSString *)jsApiName; // 查找api，按照添加分组的逆序查找，直到默认分组

@end
