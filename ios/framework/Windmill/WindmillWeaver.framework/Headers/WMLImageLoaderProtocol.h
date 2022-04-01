//
//  WMLImageLoaderProtocol.h
//  Windmill
//
//  Created by Jason Lee on 2018/5/7.
//

#import "WMLBaseProtocol.h"
#import <UIKit/UIKit.h>

@protocol WMLImageOperationProtocol <WMLBaseProtocol>

- (void)cancel;

@end

typedef NS_ENUM(NSInteger, WMLImageLoaderCacheType) {
    WMLImageLoaderCacheTypeNone,
    WMLImageLoaderCacheTypeDisk,
    WMLImageLoaderCacheTypeMemory
};

@protocol WMLImageLoaderProtocol <WMLBaseProtocol>

- (id<WMLImageOperationProtocol>)downloadImageWithURL:(NSURL *)imageUrl
                                                frame:(CGRect)imageFrame
                                              options:(NSDictionary *)options
                                             progress:(void(^)(NSInteger receivedSize, NSInteger expectedSize))progressBlock
                                            completed:(void(^)(UIImage *image, NSError *error, BOOL finished))completedBlock;

@optional

- (void)setImageView:(UIImageView *)imageView
             withURL:(NSURL *)imageUrl
         placeholder:(UIImage *)placeholder
             options:(NSDictionary *)options
            progress:(void(^)(NSInteger receivedSize, NSInteger expectedSize))progressBlock
           completed:(void(^)(UIImage *image, NSError *error, WMLImageLoaderCacheType cacheType, NSURL *imageURL))completedBlock;

@end
