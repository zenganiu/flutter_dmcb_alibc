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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// WMixProxyProtocol
@protocol WMixProxyProtocol <NSObject>

- (void)callHandler:(NSString*)handlerName data:(id)data responseCallback:(void (^)(id responseData))callback;

@end

// WMixPageViewControllerLifeCycleDelegate
@protocol WMixPageViewControllerLifeCycleDelegate <NSObject>
@optional

- (void)pageViewControllerLoadView:(UIViewController *)pageViewController;

- (void)pageViewControllerViewDidLoad:(UIViewController *)pageViewController;

- (void)pageViewControllerViewDidLayoutSubviews:(UIViewController *)pageViewController;

- (void)pageViewControllerViewWillAppear:(UIViewController *)pageViewController;

- (void)pageViewControllerViewDidAppear:(UIViewController *)pageViewController;

- (void)pageViewControllerViewWillDisappear:(UIViewController *)pageViewController;

- (void)pageViewControllerViewDidDisappear:(UIViewController *)pageViewController;

@end

NS_ASSUME_NONNULL_END
