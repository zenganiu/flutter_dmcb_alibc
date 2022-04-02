//
//  TRVSAuthCacheManager.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/23.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TRVSAuthCacheManager : NSObject

+ (TRVSAuthCacheManager *)sharedManager;

#pragma mark - AccessToken
+ (void)cacheAccessTokenInfo:(NSString *)accessToken withKey:(NSString *)key;
+ (NSString *)getAccessTokenInfoWithKey:(NSString *)key;
+ (void)removeAccessTokenInfoWithKey:(NSString*)key;

#pragma mark - Scope
+ (void)cacheScopeInfo:(NSArray<NSDictionary*> *)scopes withKey:(NSString *)key;
+ (NSArray<NSDictionary*>*)getScopesInfoWithKey:(NSString *)key;
+ (void)removeScopeInfoWithKey:(NSString *)key;

@end

