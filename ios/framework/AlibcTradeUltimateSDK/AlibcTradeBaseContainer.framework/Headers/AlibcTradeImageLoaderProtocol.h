//
//  AlibcTradeImageLoaderProtocol.h
//  AlibcTradeBaseContainer
//
//  Created by zhongweitao on 2020/3/10.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol AlibcTradeImageOperationProtocol <NSObject>

- (void)cancel;

@end

typedef NS_ENUM(NSInteger, AlibcTradeImageLoaderCacheType) {
    AlibcTradeImageLoaderCacheTypeNone,
    AlibcTradeImageLoaderCacheTypeDisk,
    AlibcTradeImageLoaderCacheTypeMemory
};

@protocol AlibcTradeImageLoaderProtocol <NSObject>

- (id<AlibcTradeImageOperationProtocol>)downloadImageWithURL:(NSURL *)imageUrl
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
           completed:(void(^)(UIImage *image, NSError *error, AlibcTradeImageLoaderCacheType cacheType, NSURL *imageURL))completedBlock;

@end
