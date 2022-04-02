//
//  WMLAppGetImageInfoProtocol.h
//  Windmill API
//
//  Created by Cai Xiaomin on 2018/8/27.
//

#ifndef WMLAppGetImageInfoProtocol_h
#define WMLAppGetImageInfoProtocol_h
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, GetImageInfoResultCode) {
    GetImageInfoResultSuccess = 0, //成功
    GetImageInfoResultNoProtocolHandler = 2, //接口没有实现
    GetImageInfoResultUnknown = 3 //未知
};

//GetImageInfo
UIKIT_EXTERN NSString * const kGetImageInfoErrorDomain;//错误域

UIKIT_EXTERN NSString * const kGetImageInfoLocationKey; //图片位置 key
UIKIT_EXTERN NSString * const kGetImageInfoOutputWidthKey; //图片宽度 key
UIKIT_EXTERN NSString * const kGetImageInfoOutputHeightKey; //图片高度 key
UIKIT_EXTERN NSString * const kGetImageInfoOutputPathKey; //图片路径 key
UIKIT_EXTERN NSString * const kGetImageInfoOutputOrientationKey; //图片朝向

UIKIT_EXTERN NSString * const kGetImageInfoUnknownMessage; //未知
UIKIT_EXTERN NSString * const kGetImageInfoNoProtocolHandlerMessage;
/**
 获取图片信息API回调函数
 */
typedef void (^GetImageInfoCallback)(BOOL, NSDictionary *);

/**
 外部可以通过实现这个接口来实现自己程序的获取图片信息功能
 */
@protocol WMLAppGetImageInfoProtocol <NSObject>
@required
- (void)getImageInfo:(NSDictionary *)params callback:(GetImageInfoCallback)callback;
@end
#endif /* WMLAppGetImageInfoProtocol_h */
