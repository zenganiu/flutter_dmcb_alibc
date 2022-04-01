//
//  RVPPushWindowAdvisor+SubClass.h
//  AriverApi
//
//  Created by 张光宇 on 2019/4/29.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "RVPPushWindowAdvisor.h"

@interface RVPPushWindowAdvisor(Protected)

/**
 * 创建 RVKScene
 * 默认实现会通过
 * <code>
 *  [RVKServicecreateSceneWithSceneParam:sceneParam parentObject:session];
 * </code>
 * 创建Scene
 *
 * 若要实现预渲染，可重载此方法
 *
 * Optional
 */
- (RVKScene *)createSceneWithParams:(RVKSceneParam *)sceneParam
                            request:(RVPPushWindowReq *)request
                       currentScene:(RVKScene *)currentScene
                       createResult:(RVPSceneCreateResult *)createResult;

/**
 * 组装参数类RVKSceneParam
 *
 * Optional
 */
- (RVKSceneParam *)composeSceneParams:(RVAOptions *)options request:(RVPPushWindowReq *)request;


/**
 * 检查navigationController的视图栈，是否执行当前操作
 *
 * Optional
 */
- (void)checkNavigationState:(UIViewController *)vc sceneResult:(RVPSceneCreateResult *)sceneResult;


/**
 * 创建RVAOptions前， 可通过重写此方法修改创建参数
 *
 * Optional
 */
- (void)modifyParamsBeforeCreateOptions:(UIViewController *)vc
                                request:(RVPPushWindowReq *)request
                                    url:(NSString *)url;

/**
 * 处理CloseCurrentWindow
 *
 * Required
 */
- (void)handleCloseCurrentWindow:(UIViewController *)currentVC
                    createResult:(RVPSceneCreateResult *)createResult;


/**
 * 处理abnormal push
 * 有以下参数时，会被当成abnormal push处理:
 * closeAllWindow/closeCurrentWindow/PopToIndex
 *
 * Required
 */
- (void)processAbnormalPush:(UIViewController *)currentVC_
                      scene:(RVKScene *)currentScene
            viewControllers:(NSMutableArray *)viewControllers
                   animated:(BOOL)animated;
@end
