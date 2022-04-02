//
//  RVPJSApiResGetImageInfo.h
//  AriverApi
//
//  Created by quankai on 2019/5/6.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

@interface RVPJSApiResGetImageInfo : RVKJSApiResponseBase

@property (nonatomic, copy) NSNumber *width;
@property (nonatomic, copy) NSNumber *height;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *orientation;
@property (nonatomic, copy) NSString *type;


@end
