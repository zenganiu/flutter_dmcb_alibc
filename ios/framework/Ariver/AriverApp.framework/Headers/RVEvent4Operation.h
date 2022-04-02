
//
//  RVEvent4Operation.h
//  AriverApp
//
//  Created by 浪浪 on 2020/2/20.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RVKSessionEvent;

@protocol RVEvent4Operation <NSObject>
@optional
- (void)appClickedClose:(RVKSessionEvent *)app;
@end

NS_ASSUME_NONNULL_END
