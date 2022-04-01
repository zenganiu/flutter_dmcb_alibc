//
//  AliWMLMtopRequest.h
//  AlibabaAuthBind
//
//  Created by ali_liuhui on 2019/3/12.
//

#import <Foundation/Foundation.h>

@interface AliWMLMtopRequest : NSObject
//需要鉴权的小程序发起的请求
@property (nonatomic, assign) BOOL licenseEnable;
//发起请求的小程序的appId
@property (nonatomic, strong) NSString *appId;
//发起请求的小程序的appKey
@property (nonatomic, strong) NSString *appKey;
@property (nonatomic, copy) NSString *api;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSNumber *needWua;
@property (nonatomic, copy) NSString *ttid;
@property (nonatomic, copy) NSString *sessionOption;
@property (nonatomic, copy) NSString *customHost;
@property (nonatomic, copy) NSNumber *needLogin;
@property (nonatomic, copy) NSNumber *usePost;
@property (nonatomic, copy) NSNumber *secType;
@property (nonatomic, copy) NSNumber *timeout;
@property (nonatomic, copy) NSNumber *source;

@property (nonatomic, strong) NSMutableDictionary *bizParams;
@property (nonatomic, strong) NSMutableDictionary *extParams;
@property (nonatomic, strong) NSMutableDictionary *extHeaders;
@property (nonatomic, strong) NSMutableDictionary *protocolParams;
@property (nonatomic, strong) NSMutableDictionary *extQuerys;
- (instancetype)initWithApiName:(NSString *)apiName apiVersion:(NSString *)apiVersion;
- (void)addBizParameter:(id)value forKey:(NSString *)key;
- (void)addExtParameter:(id)value forKey:(NSString *)key;
- (void)addProtocolParameter:(NSString *)value forKey:(NSString *)key;
- (void)addHttpHeader:(id)value forKey:(NSString *)key;

@end
