//
//  RVPJSApiReqChooseVideo.h
//  AriverApi
//
//  Created by quankai on 2019/5/6.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

@interface RVPJSApiReqChooseVideo : RVKJSApiRequestBase

@property (nonatomic, copy) NSArray<NSString *> *sourceType;
@property (nonatomic, copy) NSArray<NSString *> *camera;
@property (nonatomic, copy) NSNumber *maxDuration;
@property (nonatomic, copy) NSNumber *compressed;

@end
