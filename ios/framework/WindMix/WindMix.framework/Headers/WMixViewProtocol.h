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

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <WindMix/WMixViewContext.h>
#import <WindMix/WMixViewParam.h>

@protocol WMixViewProtocol <NSObject>

@required

/**
 初始化同层渲染组件，总是在主线程调用。
 */
- (instancetype _Nonnull)initWithViewId:(NSString * _Nonnull)viewId;

/**
 返回同层渲染组件的 UIView，总是在主线程调用。
 */
- (UIView * _Nonnull)view;

/**
 在 View 从视图移除后触发，请在此时释放 View，避免占用内存，总是在主线程调用。
 */
- (void)viewDidUnmount;

typedef void (^WMCallback)(id _Nonnull result, BOOL successOrNot);

@optional

#pragma mark - 上下文信息

/**
 关联到的 WKWebView，必须使用弱引用，会在同层渲染组件创建后设置进去。
 */
@property (nonatomic, weak, nullable) WKWebView * webView;

/**
 当前组件的上下文信息，会在同层渲染组件创建后设置进去。
 */
@property (nonatomic, strong, nullable) WMixViewContext * context;

/**
 前端设置了同层渲染组件的参数，总是在主线程调用。
 */
- (void)setParams:(NSDictionary<NSString *, WMixViewParam *> * _Nonnull)params;

/**
 前端移除了同层渲染组件的参数（恢复默认值），总是在主线程调用。
 */
- (void)removeParams:(NSArray<NSString *> * _Nonnull)params;

/**
 前端注册了同层渲染组件的事件监听，总是在主线程调用。
 */
- (void)addEvent:(NSString * _Nonnull)eventName;

/**
 前端移除了同层渲染组件的事件监听，总是在主线程调用。
 */
- (void)removeEvent:(NSString * _Nonnull)eventName;

/**
 向前端发送事件的 Handler，会在同层渲染组件创建后设置进去。
 */
@property (nonatomic, copy, nonnull) void (^dispatchEventHandler)(NSString * _Nonnull eventName, id _Nullable data);

#pragma mark - 生命周期

/**
 在 View 已经附加到视图后触发。总是在主线程调用。
 */
- (void)viewDidMount;

/**
 重新布局子 View 时触发。总是在主线程调用。
 */
- (void)layoutSubviews;

/**
 View 的可见部分发生了变化，总是在主线程调用。
 @param visible 当前是否可见。如果 visibleFrame 的宽或高为 0，或者 WebView 本身不可见时为 NO；否则为 YES。
 @param visibleFrame 可见部分的 Frame，相对于 MixView.view 本身。由于 CGFloat 计算精度的问题，visibleFrame 的 size 与 MixView 自身的 size 可能并不完全一致。
 */
- (void)visibleChanged:(BOOL)visible frame:(CGRect)visibleFrame;

/**
 View 将要出现时触发，保证时机晚于 viewDidMount，总是在主线程调用。
 包括 WebView 从不可见变为可见，或者 View 滚入 WebView 范围。
 */
- (void)viewWillAppear;

/**
 View 已经可见时触发，保证时机晚于 viewDidMount，总是在主线程调用。
 包括 WebView 从不可见变为可见，或者 View 滚入 WebView 范围。
 */
- (void)viewDidAppear;

/**
 View 将要消失时触发，总是在主线程调用。
 包括 WebView 从可见变为不可见，或者 View 滚出 WebView 范围。
 */
- (void)viewWillDisappear;

/**
 View 已经消失时触发，总是在主线程调用。
 包括 WebView 从可见变为不可见，或者 View 滚出 WebView 范围。
 */
- (void)viewDidDisappear;

/**
 View 接收到内存警告时触发。
 */
- (void)didReceiveMemoryWarning;

#pragma mark - 供小程序使用的接口

/**
 在小程序中初始化同层渲染组件，总是在主线程调用。
 */
- (instancetype _Nonnull)initWithViewId:(NSString * _Nonnull)viewId data:(NSDictionary * _Nonnull)data;

/**
 组件数据发生变更时触发的事件。
 */
- (void)componentDataDidChangeWithData:(NSDictionary * _Nonnull)data;

/**
 接受到 NBComponent.sendMessage 过来的消息。
 */
- (void)componentOnReceiveMessage:(NSString * _Nullable)message data:(NSDictionary * _Nullable)data callback:(void (^_Nullable)(id _Nullable result, BOOL success))callback;

@end
