//
//  DWPlayerImageLoaderProtocol.h
//  DWPlayerSDK
//
//  Created by zzqiltw on 16/6/2.
//  Copyright © 2016年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DWPlayerImageLoaderProtocol <NSObject>

@required
- (UIImageView *)generateImageViewForGIFNamed:(NSString *)name frame:(CGRect)frame;

@end
