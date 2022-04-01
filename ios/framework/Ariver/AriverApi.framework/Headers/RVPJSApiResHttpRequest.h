//
//  RVPJSApiResHttpRequest.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResHttpRequest : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *data; // 响应数据，包含响应文本或者响应体的base64表示（取决于请求时的responseType参数）
@property (nonatomic, strong) NSNumber *status; // 响应码
@property (nonatomic, strong) NSDictionary *headers; // 响应头

@end

NS_ASSUME_NONNULL_END
