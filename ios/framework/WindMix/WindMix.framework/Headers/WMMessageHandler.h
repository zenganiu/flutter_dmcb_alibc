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

#import <WebKit/WebKit.h>
#import <WindMix/WMixProxyProtocol.h>

typedef void (^WMRenderComponentHandler)(BOOL result);
typedef void (^WMComponentCallback)(id _Nullable result, BOOL success);

NS_ASSUME_NONNULL_BEGIN

@interface WMMessageHandler : NSObject

// 当前 WebView 是否可见，默认为 YES。
@property(nonatomic, assign) BOOL webViewVisiable;

//使用指定的 WKWebView 初始化。
- (instancetype)initWithWebView:(WKWebView*)webView;

// 接收到 JS 传递过来的消息列表。
- (void)receiveMessageList:(NSArray*)messageList;

// 给mixview.JS发送消息
- (void)dispatchEventToJS:(NSString*)eventName viewId:(NSString*)viewId data:(id)data;

// 移除特定的component
- (void)removeElement:(NSString*)viewId args:(NSArray*)args;

// 移除所有的组件
- (void)removeAllElements;

// 释放 Mixview
- (void)disposeMixView;

// 获取 MixView渲染器的描述
- (NSString*)getRenderDesc;

// RVTComponent JSAPI
// 设置对应的Data数据
- (void)setDataList:(NSDictionary*)data viewId:(NSString*)viewId;

// 渲染组件的接口
- (void)renderComponent:(NSString*)componentId
                   data:(NSDictionary*)data
         viewController:(UIViewController*)viewController
            callHandler:(id<WMixProxyProtocol>)proxy
      completionHandler:(WMRenderComponentHandler)handler;

// 调用方法
- (void)callMethod:(NSString *)methodName
            viewId:(NSString *)viewId
              data:(NSDictionary *)data
          callback:(WMComponentCallback)callback;

#pragma mark - 已废弃，预计于 2021.05.01 移除

- (void)setFullScreen:(BOOL)fullScreen shouldRotate:(BOOL)shouldRotate viewId:(NSString *)viewId DEPRECATED_MSG_ATTRIBUTE("全屏功能已废弃");

@end

NS_ASSUME_NONNULL_END
