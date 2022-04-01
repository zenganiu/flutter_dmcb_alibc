//
//  TRVSAuthContext.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/23.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define AliWML_PC_LICENSE_NET_ERROR     @"PC_LICENSE_NET_ERROR"
#define AliWML_PC_UNSUPPORTED_API       @"PC_UNSUPPORTED_API"
#define AliWML_PC_NO_LICENSE            @"PC_NO_LICENSE"
#define AliWML_PC_PARAM_ERROR           @"PC_PARAM_ERROR"
#define AliWML_PC_NO_APP_KEY            @"PC_NO_APP_KEY"
#define AliWML_PC_SYS_ERROR             @"PC_SYS_ERROR"
#define AliWML_PC_TOKEN_EXPIRED         @"PC_TOKEN_EXPIRED"
#define AliWML_PC_USER_CANCEL           @"PC_USER_CANCEL"
#define AliWML_PC_AUTHINFO_NET_ERROR    @"PC_AUTHINFO_NET_ERROR"
#define AliWML_PC_TOKEN_NET_ERROR       @"PC_TOKEN_NET_ERROR"

// errorType
typedef NS_ENUM(NSUInteger, TRVSAuthErrorType)
{
    PC_ERROR_TYPE_SUCCESS = 0,        // 调用成功
    PC_ERROR_TYPE_PARAM_ERROR = 1,    // 参数错误
    PC_ERROR_TYPE_UNKNOWN = 2,        // 未知错误
};

typedef NS_ENUM(NSInteger, TRVSAuthStatus) {
    TRVSAuthStatusNoAuth,
    TRVSAuthStatusAuth,
    TRVSAuthStatusUserCancle
};

typedef NS_ENUM(NSInteger, TRVSAuthRange) {
    TRVSAuthRangeAccount,
    TRVSAuthRangeDevice,
    TRVSAuthRangeAll
};

@class TRVSAuthResult;
typedef void(^TRVSAuthCompleteBlock)(TRVSAuthResult *result);

@interface TRVSAuthError : NSObject
// 错误类型
@property (nonatomic, assign) TRVSAuthErrorType type;
// 错误码 (和具体操作相关)
@property (nonatomic, strong) NSString *code;
// 错误消息提示
@property (nonatomic, strong) NSString *message;

+ (TRVSAuthError *)errorWithType:(TRVSAuthErrorType)type code:(NSString *)code message:(NSString *)message;
+ (TRVSAuthError *)errorWithCode:(NSString *)code message:(NSString *)message;
@end

@interface TRVSAuthResult : NSObject
@property (nonatomic, assign) BOOL isSuccess;
@property (nonatomic, strong) id responseData;
@property (nonatomic, strong) TRVSAuthError *error;
@property (nonatomic, copy) NSString *scopeName;
@end


@interface TRVSAuthContext : NSObject
@property (nonatomic, copy) NSString *mainAppId;
@property (nonatomic, copy) NSString *invokerAppId;
@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, copy) NSString *authChannel;
@property (nonatomic, copy) NSString *scopeName;
@property (nonatomic, copy) NSString *scopeDisplayName;
@property (nonatomic, copy) NSString *pageName;
@property (nonatomic, assign) TRVSAuthRange authRange;
@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, assign) BOOL needSilenceAuth;//是否需要静默授权
@end

