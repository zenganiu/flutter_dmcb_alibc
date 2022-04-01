// Copyright 2019 Taobao (China) Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <WindMix/WMMessageHandler.h>
#import <WebKit/WebKit.h>

FOUNDATION_EXPORT const void * _Nonnull WMRenderComponentKey;

NS_ASSUME_NONNULL_BEGIN

@interface WMixView : NSObject

// 返回指定名称的插件类。
+ (Class)pluginClassForName:(NSString*)name;

// 注册指定的 MixView 插件。
+ (void)registerPluginClass:(Class)pluginClass forName:(NSString*)name;

// 注册指定的 MixView 插件 默认为非全屏 目前仅限WebView
+ (void)registerPluginClass:(Class)pluginClass forName:(NSString*)name fullScreen:(BOOL)fullScreen;

//返回当前 WebView 绑定的 MessageHandler
+ (WMMessageHandler*)messageHandlerForWebView:(WKWebView*)webView createIfNotExists:(BOOL)createIfNotExists;

// 返回注册的 Class 是否是全屏
+ (BOOL)pluginClassIsFullScreen:(NSString*)name;

// 返回注册的 Class 是否是只依赖于DOM监听
+ (BOOL)pluginClassIsObserveDOM:(NSString*)name;

// Private Function
+ (void)swizzleClassName:(NSString*)clsName origSelectorName:(NSString*)origSelName newClass:(Class)newClass newSelector:(SEL)new;

@end

NS_ASSUME_NONNULL_END

/**
 提供 WKWebView 的同层渲染功能扩展。
 */
@interface WKWebView (WMixView)

/**
 为当前 WKWebView 扩展同层渲染能力。
 */
- (void)setupMixView;

/**
 为当前 AppX WKWebView 扩展同层渲染能力。
 */
- (void)setupMixViewForAppx;

/**
 为当前 WKWebView 打开/关闭同层渲染能力，默认为 YES。
 只有在 setupMixView 之后才能生效。
 */
- (void)enableMixView:(BOOL)enableMixView;

/**
 禁用指定名称的同层渲染组件。
 注意，这个属性目前会**全局生效（影响其它 WebView）**，使用时请谨慎，而且这个行为在后续版本可能会发生改变。
 */
- (void)addDisableMixViews:(NSString * _Nonnull)name;

/**
 移除当前 WebView 相关的所有同层渲染组件；
 一般在 webView:didCommitNavigation: 回调中调用，清空前一页面中用到的同层渲染组件，避免内存泄露。
 */
- (void)removeAllMixViews;

/**
 当前 WebView 的可见性发生了改变，用于 WebView 不可见（ViewController 切换等）时，停止同层渲染组件的相关功能。
 */
- (void)mixViewVisibleChanged:(BOOL)webViewVisible;

/**
 释放当前 WebView 相关的同层渲染功能；
 一般在 dealloc 中调用，避免 KVO 未释放导致的 Crash。
 */
- (void)disposeMixView;

/**
 返回已渲染的同层渲染组件的基本描述；
 一般在 Crash 时调用，用于捕获同层渲染组件的相关信息。
 */
- (NSString * _Nonnull)getMixViewDescription;

@end
