//
//  RVEvent4App.h
//  AriverApp
//
//  Created by hua.lu on 2019/5/1.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVEvent4App_h
#define RVEvent4App_h

@class RVKEvent;
@class RVKSession;

@protocol RVEvent4App <NSObject>
@optional
- (void)appPause:(RVKEvent *)event;
- (void)appResume:(RVKEvent *)event;
- (void)appCreated:(RVKSession *)app;
@end

#endif /* RVEvent4App_h */
