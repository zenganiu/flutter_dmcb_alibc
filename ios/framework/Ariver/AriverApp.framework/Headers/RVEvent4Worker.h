//
//  RVEvent4Worker.h
//  AriverApp
//
//  Created by xuyouyang on 2019/5/14.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/RVKSession.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RVEvent4Worker <NSObject>

- (void)workerWillLoadJS:(RVKSession *)session;

@end

NS_ASSUME_NONNULL_END
