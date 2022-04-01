//
//  RVPJSApiResGetClientInfo.h
//  AriverApi
//
//  Created by xuyouyang on 2019/4/15.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResGetClientInfo : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *client_version;
@property (nonatomic, strong) NSString *os_name;
@property (nonatomic, strong) NSString *os_version;
@property (nonatomic, strong) NSString *device_id;

@end

NS_ASSUME_NONNULL_END
