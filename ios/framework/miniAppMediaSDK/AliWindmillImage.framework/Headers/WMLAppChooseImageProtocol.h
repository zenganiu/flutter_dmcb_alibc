//
//  WMLAppChooseImageProtocol.h
//  Windmill API
//
//  Created by Cai Xiaomin on 2018/8/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WMLAppImage.h"

UIKIT_EXTERN NSString * const kChooseImageErrorDomain;//错误域

typedef NS_ENUM(NSUInteger, ChooseImageResultCode) {
    ChooseImageResultSuccess = 0, //成功
    ChooseImageResultNoPermission = 1, //无权限
    ChooseImageResultNoProtocolHandler= 2, //接口没有实现
    ChooseImageResultUnknown = 3, //未知
    ChooseImageResultUserCancelled = 11 //same as alipay
};

UIKIT_EXTERN NSString * const kChooseImagePathKey; //图片路径key
UIKIT_EXTERN NSString * const kChooseImageCountKey; //图片个数key
UIKIT_EXTERN NSString * const kChooseImageSourceTypeKey; //选择源key
UIKIT_EXTERN NSString * const kChooseImageExtraParamsKey; //额外参数key

UIKIT_EXTERN NSString * const kChooseImageSourceTypeCamera; //相机
UIKIT_EXTERN NSString * const kChooseImageSourceTypeAlbum; //相册

UIKIT_EXTERN NSString * const kChooseImageExtraParamsCrop; //裁剪
UIKIT_EXTERN NSString * const kChooseImageExtraParamsCropRatio; //裁剪比例
UIKIT_EXTERN NSString * const kChooseImageExtraParamsFilter; //滤镜

UIKIT_EXTERN NSString * const kChooseImageNoProtocolHandlerMessage; //接口没有实现
UIKIT_EXTERN NSString * const kChooseImageUserCancelledMessage; //用户取消
UIKIT_EXTERN NSString * const kChooseImageNoPermissionMessage; //没有访问权限
UIKIT_EXTERN NSString * const kChooseImageUnknownMessage; //未知

/**
 选图回调函数，第一个参数是 返回值，第二个成功时返回图像对象（包含thumbPath, localPath, isOrigin) 数组
 */
typedef void (^ChooseImageCallback)(ChooseImageResultCode, NSArray <WMLAppImageObject *> *);

/**
 外部可以通过实现这个接口来实现自己程序的选择图片和拍照实现
 */
@protocol WMLAppChooseImageProtocol <NSObject>
@optional
- (void)chooseFromCamera:(NSDictionary *)params callback:(ChooseImageCallback)callback;
- (void)chooseFromAlbum:(NSDictionary *)params callback:(ChooseImageCallback)callback;
- (void)chooseFromCamera:(NSDictionary *)params callback:(ChooseImageCallback)callback parentVC:(UIViewController *)parentVC;
- (void)chooseFromAlbum:(NSDictionary *)params callback:(ChooseImageCallback)callback parentVC:(UIViewController *)parentVC;
@end
