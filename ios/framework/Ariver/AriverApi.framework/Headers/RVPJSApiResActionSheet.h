//
//  RVPJSApiResActionSheet.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResActionSheet : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *index; // index是用户点击的按钮在actionSheet中的位置，从0开始

@end

NS_ASSUME_NONNULL_END
