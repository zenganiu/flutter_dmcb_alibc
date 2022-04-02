//
//  RVPJSApiResGetServerTime.h
//  AriverApi
//
//  Created by xuyouyang on 2019/5/10.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResGetServerTime : RVKJSApiResponseBase

/**
 * 服务器时间，毫秒数
 */
@property (nonatomic, strong) NSString *time;

@end

NS_ASSUME_NONNULL_END
