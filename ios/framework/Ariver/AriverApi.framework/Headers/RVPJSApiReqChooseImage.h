//
//  RVPJSApiReqChooseImage.h
//  AriverApi
//
//  Created by quankai on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

@interface RVPJSApiReqChooseImage : RVKJSApiRequestBase

@property (nonatomic, copy) NSNumber *count;
@property (nonatomic, copy) NSArray<NSString *> *sizeType;
@property (nonatomic, copy) NSArray<NSString *> *sourceType;

@end
