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

#ifndef ARIVER_RUNTIME_COMPONENT
#define ARIVER_RUNTIME_COMPONENT

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RVTComponentCallback)(id result, BOOL success);
typedef void (^RVTComponentResourceCallback)(NSData* resource);

@protocol RVTComponentProtocol <NSObject>
// @optional是为了防止编译问题
@optional

// 初始化对应的native view的接口:必须实现
- (instancetype)initWithComponentId:(NSString*)componentId data:(NSDictionary*)data;

// 传入对应的componentView的接口:必须实现
- (UIView*)componentView;

// 组件数据发生变更时触发的事件:必须实现
- (void)componentDataDidChangeWithData:(NSDictionary*)data;

// 组件已经挂载被触发的事件:可选实现
- (void)componentDidMount;

// 组件已经卸载被触发的事件:可选实现
- (void)componentDidUnmount;

// 组件将要出现被触发的事件:可选实现
- (void)componentWillAppear;

// 组件已经出现被触发的事件:可选实现
- (void)componentDidAppear;

// 组件将要消失被触发的事件:可选实现
- (void)componentWillDisappear;

// 组件已经消失被触发的事件:可选实现
- (void)componentDidDisappear;

// 组件将要进入全屏状态被触发的事件:可选实现
- (void)componentWillEnterFullScreen;

// 组件已经进入全屏状态被触发的事件:可选实现
- (void)componentDidEnterFullScreen;

// 组件将要退出全屏状态被触发的事件:可选实现
- (void)componentWillExitFullScreen;

// 组件已经退出全屏状态被触发的事件:可选实现
- (void)componentDidExitFullScreen;

// 组件可见性发生变更被触发的事件:可选实现
- (void)componentVisibleChanged:(BOOL)visible frame:(CGRect)visibleFrame;

// 组件内存出现警告接口:可选实现
- (void)componentDidReceiveMemoryWarning;

// 组件触发布局接口:可选实现
- (void)componentLayoutSubviews;

@end

@interface RVTComponentContext : NSObject

@property(nonatomic, weak)   UIViewController *viewController;

@property(nonatomic, strong) NSURL *url;

@end

@interface RVTComponent : NSObject <RVTComponentProtocol>

// 组件获取对应WebView的接口
@property(nonatomic, weak) WKWebView* webView;

// 组件获取对应componentId的接口
@property(nonatomic, copy) NSString* componentId;

// 组件获取对应的 context上下文 
@property(nonatomic, strong) RVTComponentContext* context;

// 组件给JSAPI发送事件的接口
@property(nonatomic, copy) void (^dispatchEventHandler)(NSString* eventName, id data);

// 组件通过离线包获取资源接口
- (void)getComponentResourceDataWithUrl:(NSString*)url
                               callback:(RVTComponentResourceCallback)callback;

// 组件主动设置全屏接口
- (void)setComponentViewFullScreen:(BOOL)fullScreen shouldRotate:(BOOL)shouldRotate;

// 获取组件是否入全屏的接口
- (BOOL)shouldComponentEnterFullScreen;

// 增加ArrayBuffer接口
- (void)sendArrayBufferData:(NSString *)handlerName data:(id)data responseCallback:(RVTComponentResourceCallback)responseCallback;

@end

NS_ASSUME_NONNULL_END

#endif  // ARIVER_RUNTIME_COMPONENT
