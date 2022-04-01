//
//  RVPJSApiReqTradePay.h
//  AriverApi
//
//  Created by xuyouyang on 2019/4/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqTradePay : RVKJSApiRequestBase
/**
 对应 http://jsapi.alipay.net/jsapi/native/trade-pay.html 中的“使用方法1”
 */
@property (nonatomic, strong) NSString *tradeNO;
@property (nonatomic, strong) NSString *bizType;
@property (nonatomic, strong) NSString *bizSubType;
@property (nonatomic, strong) NSString *bizContext;

/**
 对应 http://jsapi.alipay.net/jsapi/native/trade-pay.html 中的“使用方法2”
 */
@property (nonatomic, strong) NSString *orderStr;

@end

NS_ASSUME_NONNULL_END
