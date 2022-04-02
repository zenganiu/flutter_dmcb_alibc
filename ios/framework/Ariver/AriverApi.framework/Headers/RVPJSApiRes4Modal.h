//
//  RVPJSApiRes4Modal.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResAlert : RVKJSApiResponseBase

@end

@interface RVPJSApiResConfirm : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *confirm; // 点击 confirm 返回 true，点击 cancel 返回false

@end

@interface RVPJSApiResPrompt : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *ok; // 点击 ok 返回 true，点击 cancel 返回false
@property (nonatomic, strong) NSString *inputValue; // 当ok为true时，返回用户输入的内容

@end

NS_ASSUME_NONNULL_END
