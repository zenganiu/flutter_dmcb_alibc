//
//  RVASessionParam.h
//  RVAService
//
//  Created by chenwenhong on 15/8/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>

@class RVRDataSourceManager;
@class RVAAppConfigManager;

typedef enum : NSUInteger {
    RVASessionType_Online = 0,
    RVASessionType_Offline,
} RVASessionType;

@interface RVASessionContext : NSObject

@property(nonatomic, copy) NSString                     *nbl_id;
@property(nonatomic, assign) RVASessionType              sessionType;
@property(nonatomic, strong) Class                      viewControllerClass;
@property(nonatomic, strong) Class                      contentViewClass;
@property(nonatomic, strong) NSDictionary               *params;
@property(nonatomic, weak) UIViewController             *rootViewController; // 根vc
@property(nonatomic, weak) RVKSession                   *rvkSession; // 对应的session
@property(nonatomic, strong) RVRDataSourceManager     *appDataSourceManager; // app离线资源包数据源
@property(nonatomic, strong) RVAAppConfigManager         *appConfigManager; //app配置源
@property(nonatomic, strong) NSDictionary               *expando;

@end
