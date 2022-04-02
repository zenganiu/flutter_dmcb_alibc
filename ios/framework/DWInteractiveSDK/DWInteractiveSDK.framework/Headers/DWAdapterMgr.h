//
//  DWAdapterMgr.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/7.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DWUserTrackProtocol, DWImgLoaderProtocol, DWNetWorkProtocol,DWVideoSourceProtocol,DWFollowBtnProtocol;

@interface DWAdapterMgr : NSObject

+ (DWAdapterMgr *)shareInstance;

/**
 * 注册adapter
 * @param name  :   模块名称
 * @param clazz :   模块类名
 **/
- (void)registerAdapter:(NSString *)name withClass:(id)clazz;

/**
 *  可替换的注册方式，仅测试使用
 *
 *  @param name  <#name description#>
 *  @param clazz <#clazz description#>
 */
- (void)registerNewAdapter:(NSString *)name withClass:(id)clazz;

- (id)classWithAdapterName:(NSString *)name;

@end
