//
//  RVPJSApiReqToast.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqToast : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *content; // 文字内容
@property (nonatomic, strong) NSString *type; // none / success / fail / exception。 excption类型必须传文案。
@property (nonatomic, strong) NSNumber *duration; // 显示时长，单位为毫秒。

@end

@interface RVPJSApiReqHideToast : RVKJSApiRequestBase

@end

NS_ASSUME_NONNULL_END
