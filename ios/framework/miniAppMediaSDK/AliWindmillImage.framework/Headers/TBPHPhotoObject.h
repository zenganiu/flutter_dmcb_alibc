//
//  TBPHPhotoObject.h
//  TBPhotoKit
//
//  Created by 彦尘 on 2017/8/7.
//  Copyright © 2017年 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TBPHPhotoResult){
    TBPHPhotoResultSuccess = 1,
    TBPHPhotoResultFail = 2,
    TBPHPhotoResultCancel = 3
};

typedef NS_ENUM(NSInteger, TBPHPhotoFilterOption){
    TBPHPhotoFilterNone              = 0,            //不做滤镜操作
    TBPHPhotoFilterDefault           = 1             //默认滤镜
};

typedef NS_ENUM(NSInteger, TBPHPhotoWatermarkOption){
    TBPHPhotoWaterMarkNone           = 0,            //无水印
    TBPHPhotoWaterMarkDefault        = 1             //默认水印
};

typedef enum : NSUInteger {
    TBPHLargeImageOptionDefault,                    // 支持原图选项
    TBPHLargeImageOptionOrign,                      // 所有大图均为原图
    TBPHLargeImageOptionEdit                        // 非原图，等比例缩放图片，减小图片大小.
} TBPHLargeImageOption ;


@interface TBPHPhotoObject : NSObject

/// 图片本地地址.
@property (nonatomic, copy) NSString *localPath ;
/// 缩略图路径.
@property (nonatomic, copy) NSString *thumPath ;
/// 是否为原图
@property (nonatomic, assign) BOOL isOrign ;

@end
