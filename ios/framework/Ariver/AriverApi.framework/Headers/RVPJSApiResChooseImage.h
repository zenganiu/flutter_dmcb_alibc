//
//  RVPJSApiResChooseImage.h
//  AriverApi
//
//  Created by quankai on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

@interface RVPJSApiResChooseImage : RVKJSApiResponseBase

@property (nonatomic, copy) NSArray<NSString *> *apFilePaths;

@end

