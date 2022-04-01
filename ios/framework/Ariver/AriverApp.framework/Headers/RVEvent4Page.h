//
//  RVKScenePreRenderProtocol.h
//  NebulaKernel
//
//  Created by theone on 2018/9/12.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKScene;
@class RVKSceneEvent;
@class RVKEvent;

/**
 Extension体系
 由Nebula中的Event衍化来，Extension是Nebula中相关实践的组合，Extension的每个方法对应了以前的一个事件
 Plugin-> Extension
 EventName -> ExtensionDefine中protocol的方法
 */
@protocol RVEvent4Page <NSObject>
@optional
- (void)sceneWillAppear:(RVKScene *)scene;
- (void)sceneDidAppear:(RVKScene *)scene;
- (void)sceneDidCreate:(RVKSceneEvent *)event;
- (void)sceneDidReady:(RVKEvent *)event;
- (void)sceneWillDisappear:(RVKScene *)scene;
- (void)sceneWillDestroy:(RVKScene *)scene;
- (void)sceneDidUnload:(RVKEvent *)event;
- (void)securityTipViewDidShow;
- (void)sceneContentViewFallback:(RVKScene *)scene;
@end
