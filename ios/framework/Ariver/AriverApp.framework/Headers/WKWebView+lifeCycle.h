//
//  WKWebView+lifeCycle.h
//  TestWebKit
//
//  Created by theone on 16/9/15.
//  Copyright © 2016年 theone. All rights reserved.
//

#import <WebKit/WebKit.h>
#import <AriverApp/RVANebulaViewProtocol.h>

@interface WKWebView (RVAlifeCycle) <RVAContentViewProtocol,RVAWKLifeCycleDelegate>
@end
