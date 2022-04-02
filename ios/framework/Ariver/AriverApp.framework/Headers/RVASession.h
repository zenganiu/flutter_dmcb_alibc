//
//  RVASession.h
//  RVAService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVASessionContext.h"

@class RVASessionDelegate;
@protocol RVRAppResponseProtocol;

@interface RVASession : NSObject

@property(nonatomic, strong) RVASessionDelegate          *delegate;
@property(nonatomic, readonly, strong) RVASessionContext *context;

/**
 *  @brief 返回当前资源管理中指定url的离线缓存
 *  @return 自定义离线数据源(子类重写该方法，返回新容器的离线数据)
 */
- (id<RVRAppResponseProtocol>)appResponseForUrl:(NSString *)url;
@end
