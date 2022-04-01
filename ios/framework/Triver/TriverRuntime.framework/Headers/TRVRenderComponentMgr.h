//
//  TRVRenderComponentMgr.h
//  Runtime
//
//  Created by xuyouyang on 2019/8/26.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TRVRenderComponentMgr : NSObject

+ (instancetype)sharedInstance;

- (void)readAppxRenderAppendJS;

// 同步请求数据
- (NSData *)fetchComponentJSDataSync;

@end

NS_ASSUME_NONNULL_END

