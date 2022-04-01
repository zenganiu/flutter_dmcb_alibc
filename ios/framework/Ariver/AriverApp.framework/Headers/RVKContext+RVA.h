//
//  RVKContext+RVAService.h
//  RVAService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

//#import <NebulaPoseidon/NebulaPoseidon.h>
#import <AriverKernel/AriverKernel.h>

@class RVAViewControllerProxy;

@interface RVKContext (RVA)

- (UIViewController *)currentViewController;

- (RVAViewControllerProxy *)currentViewControllerProxy;

- (RVKSession *)currentSession;

- (RVKScene *)currentScene;

@end
