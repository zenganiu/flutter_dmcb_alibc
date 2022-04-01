//
//  DWNetWorkProtocol.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/7.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DWNetWorkRequest : NSObject
/**
 * 请求类型
 **/
@property (nonatomic, strong) NSString *        requestType;
/**
 * 请求URL
 **/
@property (nonatomic, strong) NSString *        requestURL;
/**
 * api名称
 **/
@property (nonatomic, strong) NSString *        apiName;
/**
 * api版本
 **/
@property (nonatomic, strong) NSString *        apiVersion;
/**
 * 是否需要登录
 **/
@property (nonatomic, assign) BOOL              needLogin;
/**
 * 是否需要缓存
 **/
@property (nonatomic, assign) BOOL              needCache;
/**
 * 是否需要安全签名
 **/
@property (nonatomic, assign) BOOL              needSign;
/**
 * 是否需要WUA
 **/
@property (nonatomic, assign) BOOL              isEnableWUA;
/**
 * 用户参数，返回带回
 **/
@property (nonatomic, strong) id                userInfo;
/**
 * 参数列表
 **/
@property (nonatomic, strong) NSDictionary *    requestParams;
/**
 * 超时时间，单位秒
 **/
@property (nonatomic, assign) double timeoutSeconds;

/**
 * 请求初始化
 * @param data  :   初始化数据
 **/
- (instancetype)initWithData:(NSMutableDictionary *)data;

@end

@interface DWNetWorkResponse : NSObject
/**
 * 状态参数
 **/
@property (nonatomic, strong) NSString *    statusCode;
/**
 * 返回数据
 **/
@property (nonatomic, strong) NSDictionary *    responseData;
/**
 * 错误码
 **/
@property (nonatomic, strong) NSString *    errorCode;
/**
 * 错误信息
 **/
@property (nonatomic, strong) NSString *    errorMsg;
/**
 * 扩展参数
 **/
@property (nonatomic, strong) id            userInfo;

/**
 * 初始化响应
 **/
- (instancetype)initWithData:(NSDictionary *)responseData;

@end

@protocol DWNetWorkProtocol <NSObject>

@required
/**
 * 发送数据请求,响应
 * @param request   :   请求对象
 * @param onResponse:   响应回调
 **/
- (void)sendRequest:(DWNetWorkRequest *)request onComplete:(void (^)(BOOL success, DWNetWorkResponse *response))onComplete;
- (void)queryAliBaoCardFreeFlow:(NSString *)bizCode result:(void (^)(BOOL,NSString *, NSString *))result;
- (BOOL)isChinaUnicom;

@optional //废弃 quanlitao用的
- (void)uploadImage:(UIImage *)image onComplete:(void (^)(BOOL success, NSURL *successURL))onComplete;


@end
