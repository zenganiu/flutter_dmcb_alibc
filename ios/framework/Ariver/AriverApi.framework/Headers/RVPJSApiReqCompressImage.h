//
//  RVPJSApiReqCompressImage.h
//  AriverApi
//
//  Created by quankai on 2019/5/6.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

@interface RVPJSApiReqCompressImage : RVKJSApiRequestBase

@property (nonatomic, copy) NSNumber *compressLevel;
@property (nonatomic, copy) NSArray<NSString *> *apFilePaths;

@end
