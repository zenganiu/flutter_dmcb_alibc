//
//  TBPKSetting.h
//  TBPhotoKit
//
//  Created by 彦尘 on 2017/7/17.
//  Copyright © 2017年 Taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "TBPHImageLoaderProtocol.h"
//#import "TBPHRequestLoaderProtocol.h"
#import "TBPHPhotoObject.h"
//#import "TBPHBundleLoaderProtocol.h"
//#import "TBPHTrackProtocol.h"

@class TBPHSetting ;
typedef void(^TBPHPhotoOperationCallback)(TBPHPhotoResult resultCode, NSArray<TBPHPhotoObject *> *selectImages) ;


@interface TBPHPublisher: NSObject

/**
 弹出选择框，选择相册与相机的选项.
 
 @param fromVC 来源VC.
 @param setting 配置对象.
 @param callback 回调 @see PhotoOperationCallback.
 */
+ (void) showMenuOptionsFromViewController:(UIViewController *) fromVC
                               withSetting:(TBPHSetting *) setting
                         operationCallback:(TBPHPhotoOperationCallback) callback ;

/**
 直接进入拍照页面.
 
 @param fromVC 来源VC.
 @param setting 配置对象.
 @param callback 回调 @see PhotoOperationCallback.
 */
+ (void) takeCameraFromViewController:(UIViewController *) fromVC
                          withSetting:(TBPHSetting *) setting
                    operationCallback:(TBPHPhotoOperationCallback) callback ;

/**
 直接进入全部照片页面.
 
 @param fromVC 来源VC.
 @param setting 配置对象.
 @param callback 回调 @see PhotoOperationCallback.
 */
+ (void) showPhotoListFromViewController:(UIViewController *) fromVC
                             withSetting:(TBPHSetting *) setting
                       operationCallback:(TBPHPhotoOperationCallback) callback ;



/**
 直接进入混合模式 视频+拍摄

 @param fromVC 来源VC.
 @param setting 配置对象.
 @param callback 回调 @see PhotoOperationCallback.
 */
+ (void) showMixedPhotoFromViewController:(UIViewController *) fromVC
                              withSetting:(TBPHSetting *) setting
                        operationCallback:(TBPHPhotoOperationCallback) callback ;


/**
 弹出编辑图片的页面.

 @param fromVC 来源VC
 @param setting 配置对象
 @param image 需要修改的图片.
 @param callback 回调 @see PhotoOperationCallback.
 */
+ (void) showEditViewFromViewController:(UIViewController *) fromVC
                            withSetting:(TBPHSetting *) setting
                                 aImage:(UIImage *) image
                      operationCallback:(TBPHPhotoOperationCallback) callback ;


///// 注册网络请求处理对象,手淘不需要注册.
//+ (void) registerRequestLoaderClass:(id<TBPHRequestLoaderProtocol>) loader ;
//
///// 注册图片加载处理对象,手淘不需要注册.
//+ (void) registerImageLoaderClass:(id<TBPHImageLoaderProtocol>) loader ;
//
///// 注册埋点处理对象，手淘不需要注册
//+ (void) registerTrackClass:(id<TBPHTrackProtocol>) track ;

@end

/// 配置文件.
@interface TBPHSetting : NSObject

/// 业务Code.
@property (nonatomic, copy) NSString *bizCode ;
/// 用户Id，埋点统计作用.
@property (nonatomic, copy) NSString *userId ;

/// 最多选择的图片数量.默认为9张图
@property (nonatomic, assign) NSInteger maxSelection ;

/// 是否允许多选, 默认多选. 如果multiSelection 为NO 的时候， 默认流程是 拍摄/选图 -> 裁剪 -> 滤镜 -> 贴纸，其他参数需要配置.
@property (nonatomic, assign) BOOL multiSelection ;

/// 滤镜选项.默认TBPHPhotoFilterDefault.
@property (nonatomic, assign) TBPHPhotoFilterOption filterOption ;

/// 帖纸选项.默认TBPHPhotoWaterMarkDefault.
@property (nonatomic, assign) TBPHPhotoWatermarkOption waterMarkOption ;

/// 最多贴纸数量.默认5张.
@property (nonatomic, assign) NSUInteger maxWatermark ;

/// 涂鸦选项是否开启.默认开启.
@property (nonatomic, assign) BOOL graffitiEnabled ;

/// 是否开启马赛克功能
@property (nonatomic, assign) BOOL mosaicEnabled ;

/// 是否允许裁剪.
@property (nonatomic, assign) BOOL cropEnabled ;

/// 裁剪比例,  默认是任意比例.，传入@"宽度:长度"，例如@"1:1", @"16:9", @"9:16".
@property (nonatomic, copy) NSString *cropRatio ;

/// 大图清晰度配置选项
@property (nonatomic, assign) TBPHLargeImageOption largeImageOption ;

/// 缩略图比例 默认比例80 * 80, 默认是当前系统的分辨率
@property (nonatomic, assign) CGSize thumSize ;

/// 设置裁剪之后，最终裁剪图片的大小.默认是当前分辨率.
@property (nonatomic, assign) CGSize imageMaxSize ;

/// 清晰度设置，默认值是0.9.
@property (nonatomic, assign) CGFloat compressQuality ;

/// 右下角确认的文案，默认是确定
@property (nonatomic, copy) NSString *sureTitle ;

/// 是否为前置摄像头
@property (nonatomic, assign) BOOL isFront ;

/// 是否配置pose机
@property (nonatomic, assign) BOOL poseEnabled ;

/// 贴纸Id数组
@property (nonatomic, strong) NSArray *pasterIds ;

@end


