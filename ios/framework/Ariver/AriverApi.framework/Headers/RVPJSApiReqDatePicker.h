//
//  RVPJSApiReqDatePicker.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqDatePicker : RVKJSApiRequestBase

/**
 返回的日期格式
 
 HH:mm
 yyyy-MM-dd (默认)
 yyyy-MM-dd HH:mm
 yyyy-MM
 yyyy
 
 */
@property (nonatomic, strong) NSNumber *mode;

@property (nonatomic, strong) NSString *beginDate; // 初始选择的日期时间，默认当前时间
@property (nonatomic, strong) NSString *minDate; // 最小日期时间
@property (nonatomic, strong) NSString *maxDate; // 最大日期时间

@end

NS_ASSUME_NONNULL_END
