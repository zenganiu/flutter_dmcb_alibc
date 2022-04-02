//
//  RVPPushWindowAdvisor.h
//  AriverApi
//
//  Created by 张光宇 on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>
#import <AriverApp/AriverApp.h>
#import "RVPPushWindowReq.h"
#import "RVPPushWindowTask.h"

NS_ASSUME_NONNULL_BEGIN
@class RVPSceneCreateResult;
@interface RVPPushWindowAdvisor : NSObject

- (RVPSceneCreateResult *)createScene:(UIViewController *)currentVC
                         currentScene:(RVKScene *)currentScene
                                 data:(RVPPushWindowReq *)data;

- (void)processRequestParams:(RVPPushWindowReq *)data scene:(RVKScene *)currentScene;

- (BOOL)shouldStartApp:(NSString *)url scene:(RVKScene *)currentScene;

- (void)handleCloseCurrentWindow:(UIViewController *)currentVC
                    createResult:(RVPSceneCreateResult *)createResult;

//!vc是否被标记为Evicted
- (BOOL)isViewControllerTagEvicted:(UIViewController *)vc;

//!vc包含的view 是否是内嵌webview
- (BOOL)isSubViewMode:(UIViewController *)vc;

//////////////////////////////////////
// 以下为TabBar相关实现
// 默认实现，请参考
//https://codesearch.alipay.com/source/xref/iOS_wallet_master/ios-phone-nebulabiz-git/Sources/UI/Controllers/H5WebViewController+TabBar.m
/**
 是否持有多Tab的其它子Tab
 */
- (BOOL)hasChildTab:(UIViewController *)vc;

/**
 持有的子Tab的数目
 */
- (NSUInteger)childTabCount:(UIViewController *)vc;

/**
 * 是否为多Tab的子Tab
 */

- (BOOL)isChildTab:(UIViewController *)vc;

/**
 多Tab时，是否不可见
 */
- (BOOL)isNotVisibleWhenMultiTab:(UIViewController *)vc;

/**
 * 处理非常规pushWindow
 *
 */
- (void)processAbnormalPush:(UIViewController *)currentVC
                      scene:(RVKScene *)currentScene
            viewControllers:(NSMutableArray *)viewControllers
                   animated:(BOOL)animated;

/**
 * 在pushWindowTask.run 之前，提供扩展点
 */

- (void)willRunPushWindowTask:(RVPPushWindowTask *)task
                  requestData:(RVPPushWindowReq *)data
                    paramsObj:(RVPPushWindowParamObj *)paramObj;

/// @brief 是否要
- (BOOL)forbidPushWindowForPage:(NSString *)page currentVC:(UIViewController *)currentVC;

/// @brief 公开创建Options方法（不需要重新实现）
- (RVAOptions *)createOptions:(UIViewController *)currentVC data:(RVPPushWindowReq *)data;

@end



@interface RVPSceneCreateResult : NSObject
@property(nonatomic,strong) RVKScene *sceneCreated;
@property(nonatomic,assign) BOOL transparent;
@property(nonatomic,assign) BOOL isNormalPush;
@property(nonatomic,assign) BOOL isHit;
@property(nonatomic,strong) NSMutableArray *viewControllers;

@property(nonatomic,strong) NSDictionary *errorInfo;


@property(nonatomic,assign) BOOL stopAndRunInDelayBlock;

@end
NS_ASSUME_NONNULL_END
