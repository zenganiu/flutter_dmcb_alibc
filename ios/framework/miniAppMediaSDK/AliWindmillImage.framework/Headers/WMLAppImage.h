//
//  WMLAppImage.h
//  Windmill API
//
//  Created by Cai Xiaomin on 2018/8/16.
//

#import <Foundation/Foundation.h>
//#import <WindmillBridge/WindmillBridge.h>

@interface WMLAppImage : NSObject 

@end

/**
 小程序图片对象，包含（本地路径，缩略图路径，和是否原图）这些信息
 */
@interface WMLAppImageObject : NSObject

/// 图片本地地址.
@property (nonatomic, copy) NSString *localPath ;
/// 缩略图路径.
@property (nonatomic, copy) NSString *thumPath ;
/// 是否为原图
@property (nonatomic, assign) BOOL isOrign ;

@end

/**
 小程序图片预览对象
 */
@interface WMLAppPreviewImageObject : NSObject
//图片网络url
@property (nonatomic, copy) NSString *originalURL;
//图片上方显示的文字
@property (nonatomic, copy) NSString *title;
@end
