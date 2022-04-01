//
//  TRVLifeCycleProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/10.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVBaseViewController.h"


@protocol TRVLifeCycleProtocol <NSObject>

@optional
- (void)trv_closeMiniApp:(UIViewController *)miniApp completion:(void (^)(void))completion;

- (void)trv_didRenderPageView:(UIView *)pageView forPage:(TRVBaseViewController *)page;

- (void)trv_pageWillAppear:(TRVBaseViewController *)page;
- (void)trv_pageDidAppear:(TRVBaseViewController *)page;

- (void)trv_willClosePage:(TRVBaseViewController *)page;
- (void)trv_didClosePage:(TRVBaseViewController *)page;

- (void)trv_willCloseApp:(UIViewController *)rootVC;
- (void)trv_didCloseApp:(UIViewController *)rootVC;

@end
