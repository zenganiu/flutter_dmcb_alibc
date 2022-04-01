//
//  RVPSystemInfoConfigService.h
//  AriverApi
//
//  Created by zhongweitao on 2019/8/12.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>

@protocol RVPSystemInfoConfigService <RVAServiceProtocol>

@optional
- (NSString *)clientName;
- (NSString *)clientVersion;
- (NSString *)currentLanguage;
- (NSNumber *)fontSize;

- (NSNumber *)customTitleBarHeightForScene:(RVKScene *)scene;

@end

