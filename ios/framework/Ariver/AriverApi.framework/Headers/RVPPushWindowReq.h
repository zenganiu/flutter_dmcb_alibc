//
//  RVPPushWindowReq.h
//  AriverApi
//
//  Created by 张光宇 on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RVPPushWindowAnimationType)
{
    RVPPushWindowAnimationPush,
    RVPPushWindowAnimationNone
};
@class RVPPushWindowParamObj;

NS_ASSUME_NONNULL_BEGIN

@interface RVPPushWindowReq : NSObject

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property(nonatomic,strong)NSString *url;

@property(nonatomic,strong)NSMutableDictionary *param;

@property(nonatomic,readonly)NSNumber *popToIndex;

@property(nonatomic,readonly)NSString *launchParamsTag;

@property(nonatomic,readonly)NSTimeInterval waitRender;

@property(nonatomic,readonly)BOOL isRequestValid;


- (RVPPushWindowParamObj *)parseParmObj;

- (NSDictionary *)writeToDictionary;


@end



@interface RVPPushWindowParamObj : NSObject
@property(nonatomic,readonly)BOOL closeAllWindow;
@property(nonatomic,readonly)BOOL closeCurrentWindow;
@property(nonatomic,readonly)RVPPushWindowAnimationType animationType;

//支付宝自有
@property(nonatomic,readonly)NSString *endJS;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
NS_ASSUME_NONNULL_END
