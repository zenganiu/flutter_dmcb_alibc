//
//  DWPlayerAdapterManager.h
//  DWPlayerSDK
//
//  Created by zzqiltw on 16/4/18.
//  Copyright © 2016年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DWPlayerAdapterManager : NSObject

+ (DWPlayerAdapterManager *)shareInstance;

/**
 * 注册adapter
 * @param name  :   模块名称
 * @param clazz :   模块类名
 **/
- (void)registerAdapter:(NSString *)name withClass:(id)clazz;

- (id)classWithAdapterName:(NSString *)name;

@end
