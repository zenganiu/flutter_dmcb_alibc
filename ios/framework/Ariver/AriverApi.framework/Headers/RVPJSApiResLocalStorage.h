//
//  RVPJsApiResLocalStorage.h
//  AriverDemo
//
//  Created by xuyouyang on 2019/4/10.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

@interface RVPJSApiResLocalStorageGet : RVKJSApiResponseBase
@property (nonatomic, strong) NSString *data;
@end

@interface RVPJSApiResLocalStorageSet : RVKJSApiResponseBase
@end

@interface RVPJSApiResLocalStorageRemove : RVKJSApiResponseBase
@end

@interface RVPJSApiResLocalStorageClear : RVKJSApiResponseBase
@end

@interface RVPJSApiResLocalStorageGetInfo : RVKJSApiResponseBase
@property (nonatomic, strong) NSArray *keys;
@property (nonatomic, strong) NSNumber *currentSize;
@property (nonatomic, strong) NSNumber *limitSize;
@end
