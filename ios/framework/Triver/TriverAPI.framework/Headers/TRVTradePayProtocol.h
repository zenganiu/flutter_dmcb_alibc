//
//  TRVTradePayProtocol.h
//  API
//
//  Created by xuyouyang on 2019/5/29.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApi/RVPJSApiReqTradePay.h>
#import <AriverApi/RVPJSApiResTradePay.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TRVTradePayCompleteBlock)(RVPJSApiResTradePay *response);

@protocol TRVTradePayProtocol <NSObject>

@required
- (void)tradePayWithRequest:(RVPJSApiReqTradePay *)request originParam:(NSDictionary *)originParam complete:(TRVTradePayCompleteBlock)complete;

@end

NS_ASSUME_NONNULL_END
