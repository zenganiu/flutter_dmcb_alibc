//
//  RVEvent4Navigation.h
//  AriverApp
//
//  Created by theone on 2019/5/10.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Webkit/Webkit.h>

@protocol RVKContentViewProtocol;

NS_ASSUME_NONNULL_BEGIN

@protocol RVEvent4Navigation <NSObject>
@optional
- (NSNumber *)webView:(id<RVKContentViewProtocol>)webView shouldStartLoadRequest:(NSURLRequest *)request navigationType:(WKNavigationType)navigationType;
- (void)webViewLoadStart:(id<RVKContentViewProtocol>)webView;
- (void)webView:(id<RVKContentViewProtocol>)webView loadcomplete:(NSURLRequest *)request;
- (void)webView:(id<RVKContentViewProtocol>)webView loadError:(NSURLRequest *)request error:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
