//
//  RVASessionFactory.h
//  RVAService
//
//  Created by chenwenhong on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVASession;
@class RVASessionContext;

@interface RVASessionFactory : NSObject

- (RVASession *)createSession:(RVASessionContext *)context;

@end
