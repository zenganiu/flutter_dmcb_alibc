//
//  TRVSMtopServiceProtocol.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/30.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVSAuthMtopError.h"

#define RVSMtopApiKeyName           @"mtopApi"
#define RVSMtopVersionKeyName       @"mtopVersion"
#define RVSMtopAppIdKeyName         @"appId"
#define RVSMtopAppKeyKeyName        @"appKey"
#define RVSMtopAccessTokenKeyName   @"accessToken"
#define RVSMtopNeedLoginKeyName     @"needLogin"
#define RVSMtopAppKeyName           @"RVRApp"
#define RVSMtopPluginIdKeyName      @"pluginId"


typedef void(^RVSMTOPRequestComplete)(BOOL success, NSDictionary *respJsons, TRVSAuthMtopError *error);
// 新的AuthCode失效错误码，在subCode中
#define RVSTokenExpiredErrorNew @"TOPAUTH_ACCESSTOKEN_EXPIRED"
// 旧的AuthCode失效错误码，在Code中
#define RVSTokenExpiredErrorOld @"FAIL_SYS_TOPAUTH_ACCESSTOKENEXPIRED_ERROR"


@protocol RVSMTOPServiceProtocol <NSObject>

@required

/**
 发起MTOP请求
 
 @param basicParams 基础参数
 @param bizParams 业务参数
 @param isFramework 是否是框架发出
 @param completeBlock 完成回调
 */
- (void)requestWithBasicParams:(NSDictionary *)basicParams
                     bizParams:(NSDictionary *)bizParams
                   isFramework:(BOOL)isFramework
                    completion:(RVSMTOPRequestComplete)completeBlock;

@optional

/**
 获取服务端当前时间戳
 */
- (NSTimeInterval)currentServerTimeInterval;

- (NSString *)getCurrentUserId;

@end
