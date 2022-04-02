//
//  DWImgLoaderProtocol.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/5.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#ifndef DWImgLoaderProtocol_h
#define DWImgLoaderProtocol_h

#import <UIKit/UIKit.h>


@protocol DWImgLoaderProtocol <NSObject>

/**
 * 下载图片
 * @param url             :   图片URL
 * @param userInfo        :   用户信息
 *        imageQuality    :   图片质量
 *        imageSharp      :   图片策略
 * @param completedBlock  :   下载结束回调
 *
 **/
- (void)setImageByURL:(NSString *)url imageView:(UIImageView *)imageView userInfo:(NSDictionary *)userInfo completed:(void(^)(UIImage *image,  NSError *error, BOOL finished))completedBlock;

- (UIImageView *)generateImageViewForGIFNamed:(NSString *)name frame:(CGRect)frame;

@end
#endif /* DWImgLoaderProtocol_h */
