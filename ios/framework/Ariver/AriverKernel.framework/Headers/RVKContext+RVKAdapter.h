//
//  RVKContext+NXKAdapter.h
//  NebulaKernel
//
//  Created by theone on 2018/9/9.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AriverKernel/AriverKernel.h>

@class RVAViewControllerProxy;
@class RVKSession;
@class RVKScene;

@interface RVKContext (NXKAdapter)
- (UIViewController *)currentViewController;

- (RVAViewControllerProxy *)currentViewControllerProxy;

- (RVKSession *)currentSession;

- (RVKScene *)currentScene;

@end
