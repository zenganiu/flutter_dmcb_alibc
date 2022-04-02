//
//  RVASessionManager.h
//  RVAService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVASession;
@class RVASessionContext;

@interface RVASessionManager : NSObject

// 使用Nebula的startSession模式

- (RVASession *)session4Context:(RVASessionContext *)context createIfNoExist:(BOOL)createIfNoExist;

- (BOOL)startSession:(RVASession *)session params:(NSDictionary *)params animated:(BOOL)animated;

- (void)exitSession:(RVASession *)session animated:(BOOL)animated;

// 使用session

- (RVASession *)createSession:(RVASessionContext *)context;

- (void)pushSession:(RVASession *)session;

- (void)popSession:(RVASession *)session;

/**
 * 显示栈中添加session
 * @param session
 */
- (void)showSession:(RVASession *)session;

/**
 * 从session的显示栈中移除session
 * @param session
 */
- (void)hideSession:(RVASession *)session;

// 

- (RVASession *)currentSession;

- (NSArray *)sessions;

@end
