//
//  RVPJSApiResDevice.h
//  AriverApi
//
//  Created by lanyao on 2019/4/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResScan : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *code; // 扫码所得数据
@property (nonatomic, strong) NSString *qrCode; // 扫描二维码时返回二维码数据
@property (nonatomic, strong) NSString *barCode; // 扫描条形码时返回条形码数据

@end

@interface RVPJSApiResSnapshot : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *success; // 是否处理成功
@property (nonatomic, strong) NSString *fileUrl; // 图片在文件系统中的url
@property (nonatomic, strong) NSString *dataUrl; // base64编码的图片数据

@end

NS_ASSUME_NONNULL_END
