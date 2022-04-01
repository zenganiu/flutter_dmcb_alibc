//
//  TRVDebugConfigCenter.h
//  Runtime
//
//  Created by xuyouyang on 2019/7/16.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TRVDebugConfigCenter : NSObject

/**
 调试模式下，appx 的 cdn 地址
 */
@property (nonatomic, strong) NSString *appxHotUrl;

/**
 调试模式下，根据URL判断是否为店铺
 */
@property (nonatomic, assign) BOOL isShopDebug;

+ (instancetype)sharedInstance;

- (void)configAppxHotURLWithOrignalAppUrl:(NSString *)AppUrl;

@end

NS_ASSUME_NONNULL_END
