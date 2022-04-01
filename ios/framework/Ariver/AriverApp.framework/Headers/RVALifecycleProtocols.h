//
//  Header.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#ifndef RVAService_Header_h
#define RVAService_Header_h

@class RVKSession;
@class RVKScene;
@class RVKView;

@protocol RVAViewControllerLifecycleProtocol <NSObject>

- (void)lifecycle_loadView;
- (void)lifecycle_viewDidLoad;
- (void)lifecycle_viewWillAppear:(BOOL)animated;
- (void)lifecycle_viewDidAppear:(BOOL)animated;
- (void)lifecycle_viewWillDisappear:(BOOL)animated;
- (void)lifecycle_viewDidDisappear:(BOOL)animated;
- (void)lifecycle_viewDidLayoutSubviews;
- (void)lifecycle_viewWillDestroy;

@end

@protocol RVANavigationControllerLifecycleProtocol <NSObject>

@required
- (NSMutableArray *)lifecycle_currentViewControllers;

@end

#endif
