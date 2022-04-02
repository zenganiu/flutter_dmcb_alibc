//
//  RVPJSApiResChooseVideo.h
//  AriverApi
//
//  Created by quankai on 2019/5/6.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

@interface RVPJSApiResChooseVideo : RVKJSApiResponseBase

@property (nonatomic, copy) NSString *tempFilePath;
@property (nonatomic, copy) NSNumber *duration;
@property (nonatomic, copy) NSNumber *size;
@property (nonatomic, copy) NSNumber *width;
@property (nonatomic, copy) NSNumber *height;


@end
