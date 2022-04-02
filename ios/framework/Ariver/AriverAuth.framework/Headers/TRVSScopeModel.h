//
//  TRVSScopeModel.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/24.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVSAuthContext.h"


#define TRVSScopeNameKey          @"scopeName"
#define TRVSScopeDisplayNameKey   @"displayName"
#define TRVSScopeAuthRangeKey     @"authRange"
#define TRVSScopeAuthStatuKey     @"authStatu"
#define TRVSScopeAuthDescKey      @"authDesc"

#define TRVSScopeAuth @"auth"
#define TRVSScopeNoAuth @"noAuth"
#define TRVSScopeUserCancle @"userCancle"

#define TRVSAuthRangeDeviceType   @"device"
#define TRVSAuthRangeAccountType  @"taobaoAccount"


@interface TRVSScopeModel : NSObject

@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, copy) NSString *scopeName;
@property (nonatomic, copy) NSString *authDesc;
@property (nonatomic, assign) TRVSAuthRange authRange;
@property (nonatomic, assign) TRVSAuthStatus authStatus;

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)toDictionary;

@end

