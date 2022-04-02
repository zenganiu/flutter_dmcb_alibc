//
//  RVKJSApiResponseBase.h
//  AriverKernel
//
//  Created by hua.lu on 2019/4/10.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVKJSApiResponseBase : NSObject

@property(nonatomic, strong) NSNumber *error;
@property(nonatomic, copy) NSString *errorMessage;

@end

NS_ASSUME_NONNULL_END
