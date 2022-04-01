//
//  RVAContext.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVASession.h"
#import "RVASessionManager.h"

@class RVAServiceManager;

//容器Service协议
@protocol RVAServiceProtocol <NSObject>

@optional
- (void)start;

@end

@class RVASessionContext;

@interface RVAContext : NSObject

@property(nonatomic, weak) UIWindow                   *window;
@property(nonatomic, weak) UINavigationController     *navigationController;
@property(nonatomic, strong) RVASessionManager           *sessionManager;
@property(nonatomic, strong) RVAServiceManager           *serviceManager;

+ (instancetype)alloc UNAVAILABLE_ATTRIBUTE;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (id)copy UNAVAILABLE_ATTRIBUTE;

+ (instancetype)allocWithZone:(struct _NSZone *)zone UNAVAILABLE_ATTRIBUTE;

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

+ (instancetype)sharedContext;

- (RVASession *)createSession:(RVASessionContext *)context;

- (BOOL)startSession:(NSDictionary *)params animated:(BOOL)animated;

- (void)exitSession:(RVASession *)session animated:(BOOL)animated;

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

- (NSArray *)sessions;

/**
 * 获取当前正在运行的应用对象。
 */
- (RVASession *)currentSession;


/**
 * 根据指定的名称查到一个服务。
 *
 * @param name 服务名
 *
 * @return 如果找到指定名称的服务，则返回一个服务对象，否则返回空。
 */
- (id)findServiceByName:(NSString *)name;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    RVAContext * RVAContextGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
