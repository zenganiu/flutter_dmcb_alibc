//
//  TRVExtensionManager.h
//  Runtime
//
//  Created by xuyouyang on 2019/4/18.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKExtension;

NS_ASSUME_NONNULL_BEGIN

@interface TRVExtensionManager : NSObject

+ (void)startApiDetect;

+ (void)registerExtensionArray:(NSArray<NSString *> *)extensionArray;

+ (RVKExtension *)findJSAPIExtensionWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
