//
//  TRVAppKeepAliveManager.h
//  Triver
//
//  Created by zhongweitao on 2019/7/3.
//

#import <Foundation/Foundation.h>
#import "TRVAppContainer.h"

@interface TRVAppKeepAliveManager : NSObject

+ (TRVAppKeepAliveManager *)sharedInstance;

- (TRVAppContainer *)getAppWithAppId:(NSString *)appId;

/// @brief 删除单个保活实例
- (void)removeAppWithAppId:(NSString *)appId;

/// @brief 是否开启保活
- (BOOL)enableAppKeepAlive;

/// @brief 添加保活App
- (void)addAliveApp:(TRVAppContainer *)appContainer;

/// @brief 删除所有保活App
- (void)clearAllAliveApps;

/// @brief 获取所有保活appIds
- (NSArray<NSString *> *)keepAliveAppIds;

@end
