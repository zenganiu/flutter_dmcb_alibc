//
//  DWInteractiveProtocol.h
//  Pods
//
//  Created by yingfang on 2017/7/15.
//
//

#import <Foundation/Foundation.h>

@protocol DWInteractiveProtocol <NSObject>

- (void)handleLikeStatusChange:(NSNumber*)bLike;


- (void)handleAttentionStatusChange:(NSNumber*)bAttention;

@end
