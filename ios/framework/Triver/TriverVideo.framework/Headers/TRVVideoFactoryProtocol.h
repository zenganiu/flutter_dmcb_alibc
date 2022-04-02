//
//  TRVVideoFactoryProtocol.h
//  Triver
//
//  Created by 岚遥 on 2019/11/1.
//

#import <Foundation/Foundation.h>
#import "TRVVideoPlayerViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TRVVideoFactoryProtocol <NSObject>

- (id<TRVVideoPlayerViewProtocol>)createTBVideoPlayerView;

@end

NS_ASSUME_NONNULL_END
