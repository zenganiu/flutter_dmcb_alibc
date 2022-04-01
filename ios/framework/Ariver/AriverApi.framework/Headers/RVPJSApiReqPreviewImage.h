//
//  RVPJSApiReqPreviewImage.h
//  AriverApi
//
//  Created by quankai on 2019/5/6.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

@interface RVPJSApiReqPreviewImage : RVKJSApiRequestBase

@property (nonatomic, copy) NSArray<NSDictionary *> *images;
// 为兼容 appx 和 jsapi，init参数从originParams 中获取
// @property (nonatomic, copy) NSNumber *init;
@property (nonatomic, assign) BOOL enablesavephoto;
@property (nonatomic, assign) BOOL enableShowPhotoDownload;

@end
