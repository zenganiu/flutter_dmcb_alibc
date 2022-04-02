//
//  RVPJsApiReqLocalStorage.h
//  AriverDemo
//
//  Created by xuyouyang on 2019/4/10.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

#pragma mark - LocalStorageGet
@interface RVPJSApiReqLocalStorageGet : RVKJSApiRequestBase
@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *business;
@end

#pragma mark - LocalStorageSet
@interface RVPJSApiReqLocalStorageSet : RVKJSApiRequestBase
@property (nonatomic, strong) NSString *data;
@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSString *value;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *business;
@end

#pragma mark - LocalStorageRemove
@interface RVPJSApiReqLocalStorageRemove : RVKJSApiRequestBase
@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *business;
@end

#pragma mark - LocalStorageClear
@interface RVPJSApiReqLocalStorageClear : RVKJSApiRequestBase
@property (nonatomic, strong) NSString *business;
@end

#pragma mark - LocalStorageGetInfo
@interface RVPJSApiReqLocalStorageGetInfo : RVKJSApiRequestBase
@end
