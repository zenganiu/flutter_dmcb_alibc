//
//  RVPJSApiReqDevice.h
//  AriverApi
//
//  Created by lanyao on 2019/4/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqScan : RVKJSApiRequestBase
/**
 扫码样式(默认 qr)：
 1. qr,扫码框样式为二维码扫码框
 2. bar，扫码样式为条形码扫码框
 */
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSNumber *hideAlbum; // 是否隐藏相册（不允许从相册选择图片），只能从相机扫码

@end

@interface RVPJSApiReqSnapshot : RVKJSApiRequestBase
/**
 快照范围:
 screen: 当前客户端整个屏幕
 viewport: 网页可见区域
 document: 整个网页 注意: document会截取全部网页，在安卓手机上，网页很大的时候会浏览器内存溢出，请使用screen
 */
@property (nonatomic, strong) NSString *range;
@property (nonatomic, strong) NSNumber *saveToGallery; // 是否保存到相册
/**
 结果数据格式:
 dataURL: base64编码的图片数据
 fileURL: 图片在文件系统中的url（图片存放于临时目录中，钱包退出时被清除)
 none: 不返回数据（用于保存到相册的情况）
 */
@property (nonatomic, strong) NSString *dataType;
@property (nonatomic, strong) NSString *imageFormat; // jpg / png
@property (nonatomic, strong) NSNumber *quality;  // jpg的图片质量, 取值1到100
@property (nonatomic, strong) NSNumber *maxWidth; // 图片的最大宽度. 过大将被等比缩小
@property (nonatomic, strong) NSNumber *maxHeight; // 图片的最大高度. 过大将被等比缩小

@end

NS_ASSUME_NONNULL_END
