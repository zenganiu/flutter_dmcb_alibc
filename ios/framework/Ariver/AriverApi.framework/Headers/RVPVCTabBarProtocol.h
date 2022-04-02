//
//  RVPVCTabBarProtocol.h
//  AriverApp
//
//  Created by hua.lu on 2019/5/30.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVAViewControllerTabBarProtocol_h
#define RVAViewControllerTabBarProtocol_h

#import <AriverKernel/RVKViewControllerProtocol.h>
#import <AriverApp/RVATabBarProtocol.h>
#import "RVPTabBarItemData.h"

@class RVPTabBarManager;
@protocol RVPVCTabBarProtocol <NSObject>

- (BOOL)isWebviewController:(UIViewController *)vc;

// 获取当前 webview 的 insets 属性
- (UIEdgeInsets)getContentEdgeInsets:(UIViewController *)vc;

// 设置 webview 的 insets 属性
// 注意：这里仅设置属性值，不做 UI 变更（区别于下面的 adjustWebviewContentInsets）
- (void)setContentEdgeInsets:(UIEdgeInsets)contentEdgeInsets forVC:(UIViewController *)vc;

// 根据 insets 修改 webview 的 ui
- (void)adjustWebviewContentInsets:(UIViewController *)vc;

// 解析 tabbar.json 文件错误时，showAlert==YES表示需要阻断流程(弹 alert)
- (void)tabbarDicParseError:(NSString *)errorLog withVC:(UIViewController *)vc showAlert:(BOOL)showAlert;

// switchTab jsapi
// --------------
// 异步拉去 tabbar.json 之前先显示 toast
// 这里需要返回 toast 实例
- (id)showToastBeforeReadTabDic:(RVKScene *)scene;

// 拉去到 tabbar.json 后隐藏 toast
- (void)hideToastAfterReadTabDic:(id)toast;

// relaunch 时，重建 tabvc
// 注意：调用 setViewControllers 最好放到下一个 runloop，防止乱栈
- (void)setNewViewController:(UIViewController *)newVC withCurrentVC:(UIViewController *)currentVC;

@optional

/// @brief 切换tab拦截
- (BOOL)forbidChangeToTabForPage:(NSString *)page currentVC:(UIViewController *)currentVC;

// optional
// 默认返回 NO
- (BOOL)shouldDisableTabBarWhenShare:(NSString *)url withVC:(UIViewController *)vc;

// 创建 tab 对应的 scene
// 可选，有默认实现
// optional
- (RVKScene *)createScene:(RVKSceneParam *)sceneParam selectedIndex:(NSInteger)index withVC:(UIViewController *)vc;

// 组装创建 scene 的参数
// 可选，有默认实现
// optional
- (RVKSceneParam *)sceneParamWithParams:(NSDictionary *)launchParams url:(NSString *)url vc:(UIViewController *)vc;

// 解析 tabBarJson 之后找到匹配 url 的 tab 之后的回调，主要做动态合并启动参数
// 无默认实现
// optional
- (void)tabDidMatch:(NSDictionary *)mergedLaunchParam withVC:(UIViewController *)vc;

// 未找到匹配的 tab 的回调，主要是记录一下埋点
// 无默认实现
// optional
- (void)tabDidMismatchWithVC:(UIViewController *)vc;

// autoPreRender
// 无默认实现
// optional
- (void)handleAutoPreRender:(RVPTabBarItemData *)itemData preRenderParams:(NSDictionary *)params withVC:(UIViewController *)vc;

// 获取当前 vc 所在 app 的 rootVC（alipay only）
// 无默认实现
// optional
- (UIViewController *)getRootVCWithFirstVC:(UIViewController *)firstVC currentVC:(UIViewController *)currentVC;

// config 开关
// --------------
// 默认 NO
// optional
- (BOOL)enableAutoRender;

// optional
// 默认 NO
- (BOOL)enableProxyOnceForAll;

// optional
// 默认 NO
- (BOOL)shouldTabChangeSupportWaitRender;

// 扩展方法
// --------------
// tabbar 切换时的回调
- (void)tabBar:(UITabBar *)tabBar willSwitchFromVC:(UIViewController *)fromVC toVC:(UIViewController *)toVC;

// tab 切换时，是否忽略每个 tab 的 navigationItem 变化
- (BOOL)tabBarShouldIgnoreNaviBarChange:(UITabBar *)tabBar;

//当前应用是否为暗黑模式
- (RVATabBarColorMode)currentColorMode:(UIViewController *)vc;

@end


#endif /* RVAViewControllerTabBarProtocol_h */
