//
//  WMLAppCompressImageProtocol.h
//  Windmill API
//
//  Created by Cai Xiaomin on 2018/8/24.
//

#ifndef WMLAppCompressImageProtocol_h
#define WMLAppCompressImageProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, CompressImageResultCode) {
    CompressImageResultSuccess = 0, //成功
    CompressImageResultNoProtocolHandler = 2, //接口没有实现
    CompressImageResultUnknown = 3 //未知
};

typedef NS_ENUM(NSUInteger, CompressImageLevel) {
    CompressImageLevelLow = 0, //低质量
    CompressImageLevelMedium = 1, //中质量
    CompressImageLevelHigh = 2, //高质量
    CompressImageLevelNone = 3, //无压缩
    CompressImageLevelNetwork = 4 //根据网络判断
};

UIKIT_EXTERN NSString * const kCompressImageErrorDomain;//错误域

UIKIT_EXTERN NSString * const kCompressImageUrlKey; //图片URL key
UIKIT_EXTERN NSString * const kCompressImageLevelKey; //当前Compress Level key

UIKIT_EXTERN NSString * const kCompressImageNoProtocolHandlerMessage; //接口没有实现
UIKIT_EXTERN NSString * const kCompressImageUnknownMessage; //未知

/**
 压缩图片API回调函数
 */
typedef void (^CompressImageCallback)(BOOL bSuccess, NSArray<NSString *> *compressedFilePath);

/**
 外部可以通过实现这个接口来实现自己程序的图片压缩功能
 */
@protocol WMLAppCompressImageProtocol <NSObject>
@required
- (void)compressImage:(NSDictionary *)params callback:(CompressImageCallback)callback;
@end


#endif /* WMLAppCompressImageProtocol_h */
