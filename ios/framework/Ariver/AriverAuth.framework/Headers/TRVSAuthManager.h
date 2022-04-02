//
//  RVSAuthManager4TB.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/23.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVSAuthContext.h"
#import "TRVSScopeModel.h"

#import <AriverKernel/AriverKernel.h>

#define TRVSAuthViewControllerKey @"TRVSAuthViewControllerKey"

@interface TRVSAuthStorageInstance : NSObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *invokerAppId;
@property (nonatomic, copy) NSString *appKey;
@end

typedef void(^TRVSGetAuthSettingComplete)(NSArray<TRVSScopeModel*>* models, NSError *error);
@interface TRVSAuthManager : NSObject

+ (instancetype)sharedManager;

#pragma mark - 授权主流程
+ (void)startAuthorizeWithData:(NSDictionary *)data context:(RVKContext *)context callBack:(RVKJsApiResponseCallbackBlock)callBack completion:(TRVSAuthCompleteBlock)completion;
+ (void)userAuth:(TRVSAuthContext *)context invokeParams:(NSDictionary *)invokeParams completion:(TRVSAuthCompleteBlock)completion;

#pragma mark - 授权信息

/**
 获取当前本地存储的授权状态，不会和服务端进行同步
 */
+ (NSArray<TRVSScopeModel*> *)getLocalAuthSettingWithInstance:(TRVSAuthStorageInstance *)instance;

/**
 获取当前的授权状态，会和服务端进行同步
 */
+ (void)getCurrentAuthSettingWithInstance:(TRVSAuthStorageInstance *)instance completionBlock:(TRVSGetAuthSettingComplete)completion;

/**
 更新当前的授权状态
 */
+ (void)updateAuthInfo:(NSArray<TRVSScopeModel*>*)scopes forInstance:(TRVSAuthStorageInstance *)instance;

@end

