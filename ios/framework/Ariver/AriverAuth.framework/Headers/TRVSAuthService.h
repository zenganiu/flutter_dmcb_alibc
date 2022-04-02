//
//  TRVSAuthService.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/23.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^TRVSAuthHandler)(NSDictionary *resultBizJson, NSError *error);
typedef void(^TRVSRequestCompletion)(NSDictionary *result, NSError *error);

@class TRVSScopeModel;
@interface TRVSAuthService : NSObject

+ (void)requestUserAuthSettingWithScopes:(NSArray<TRVSScopeModel*>*)scopes
                                  appKey:(NSString *)appKey
                              completion:(TRVSRequestCompletion)completionBlock;

+ (void)createNewAccessTokenWithMainAppId:(NSString *)mainAppId
                             invokerAppId:(NSString *)invokerAppId
                                 scopeNames:(NSArray<NSString*> *)scopeNames
                            completion:(TRVSRequestCompletion)completionBlock;

+ (void)updateAccessTokenWithAccessToken:(NSString *)accessToken
                              scopeDiffs:(NSDictionary*)diffs
                                   appId:(NSString *)appId
                                  appKey:(NSString *)appKey
                            invokerAppId:(NSString *)invokerAppId
                              completion:(TRVSRequestCompletion)completionBlock;

+ (void)invalidAccessToken:(NSString *)accessToken
                    appKey:(NSString *)appKey
                completion:(TRVSRequestCompletion)completionBlock;

+ (void)checkValidAuthScope:(NSString *)scopeName
                     appKey:(NSString *)appKey
                 completion:(TRVSRequestCompletion)completionBlock;

@end
