//
//  NBWKURLSchemeTaskManager.h
//  TestScreen
//
//  Created by theone on 2018/7/15.
//  Copyright © 2018年 theone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

API_AVAILABLE(ios(11.0))
@interface RVKProxyWKURLSchemeTaskManager : NSObject <WKURLSchemeHandler>
+ (instancetype)sharedInstance;
+ (NSString *)WKURLSchemeJSSource;
@end
