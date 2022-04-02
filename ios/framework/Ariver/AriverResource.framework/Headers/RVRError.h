//
//  RVRError.h
//  NebulaResource
//
//  Created by 扶瑶 on 16/3/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVRErrorCode.h"

@interface RVRError : NSObject

+ (NSError *)errorCode:(NXRErrorCode)code
               message:(NSString *)message
               options:(id)options;

@end
