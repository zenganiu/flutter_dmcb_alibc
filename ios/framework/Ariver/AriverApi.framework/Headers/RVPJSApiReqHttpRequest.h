//
//  RVPJSApiReqHttpRequest.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqHttpRequest : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *url; // 目标服务器url
@property (nonatomic, strong) NSDictionary *headers; // 设置请求的 HTTP 头，默认 {'content-type': 'application/json'}
@property (nonatomic, strong) NSString *method; // 默认GET，目前支持GET/POST
@property (nonatomic, strong) NSString *data; // 用于POST的请求数据，需要调用方自己编码
@property (nonatomic, strong) NSNumber *timeout; // 超时，单位为毫秒，默认 30000
@property (nonatomic, strong) NSString *responseType; // 期望返回的数据格式，默认json，支持json，text，base64

@end

NS_ASSUME_NONNULL_END
