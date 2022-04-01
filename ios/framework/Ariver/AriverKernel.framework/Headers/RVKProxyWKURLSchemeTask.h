//
//  NBWKURLSchemeTask.h
//  TestScreen
//
//  Created by theone on 2018/7/15.
//  Copyright © 2018年 theone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#define kRVKWKURLSchemeTaskWeakTask   @"kRVKWKURLSchemeTaskWeakTask"


API_AVAILABLE(ios(11.0))
@interface RVKProxyWKURLSchemeTask : NSObject <NSURLConnectionDataDelegate>
@property(nonatomic, weak, readonly) id<WKURLSchemeTask> task;
- (instancetype)initWithURLSchemeTask:(id<WKURLSchemeTask>)task webView:(WKWebView *)webView API_AVAILABLE(ios(11.0));
- (void)cancelTask;
@end
