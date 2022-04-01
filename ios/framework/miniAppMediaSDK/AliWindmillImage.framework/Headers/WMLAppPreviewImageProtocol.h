//
//  WMLAppPreviewImageProtocol.h
//  Windmill API
//
//  Created by Cai Xiaomin on 2018/8/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import <WindmillBridge/WMBridgeProtocol.h>


typedef NS_ENUM(NSUInteger, PreviewImageResultCode) {
    PreviewImageResultSuccess = 0, //成功
    PreviewImageResultNoProtocolHandler = 2, //接口没有实现
    PreviewImageResultUnknown = 3 //未知
};

UIKIT_EXTERN NSString * const kPreviewImageErrorDomain;//错误域

UIKIT_EXTERN NSString * const kPreviewImageUrlKey; //图片URL key
UIKIT_EXTERN NSString * const kPreviewImageCurrentIndexKey; //当前index key

UIKIT_EXTERN NSString * const kPreviewImageNoProtocolHandlerMessage; //接口没有实现
UIKIT_EXTERN NSString * const kPreviewImageUnknownMessage; //未知

/**
 预览图片API回调函数
 */
typedef void (^PreviewImageCallback)(void);

/**
 外部可以通过实现这个接口来实现自己程序的图片预览功能
 */
@class RVPJSApiReqPreviewImage;
@protocol WMLAppPreviewImageProtocol <NSObject>
@required
- (void)previewImage:(RVPJSApiReqPreviewImage *)request callback:(PreviewImageCallback)callback current:(NSNumber *)current;
//- (void)previewImage:(NSDictionary *)params callback:(PreviewImageCallback)callback context:(id<WMBridgeContext>)context;
@end
