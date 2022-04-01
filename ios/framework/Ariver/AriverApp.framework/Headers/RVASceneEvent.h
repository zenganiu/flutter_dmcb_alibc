//
//  RVASceneEvent.h
//  AriverApp
//
//  Created by chenwenhong on 15/12/28.
//  Copyright © 2015年 Alipay. All rights reserved.
//

//#import <NebulaPoseidon/NebulaPoseidon.h>

@interface RVASceneEvent : RVKEvent

// create before
@property(nonatomic, copy) NSString *url;
@property(nonatomic, strong) RVASessionContext *sessionContext;
@property(nonatomic, strong) Class  viewControllerCls; // 可以设置
@property(nonatomic, strong) Class  contentViewCls; // 可以设置

+ (instancetype)createBeforeEvent:(NSString *)url sessionContext:(RVASessionContext *)sessionContext;

@end
