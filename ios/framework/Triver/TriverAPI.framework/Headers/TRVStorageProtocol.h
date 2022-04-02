//
//  TRVStorageProtocol.h
//  API
//
//  Created by xuyouyang on 2019/5/28.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 统一存储协议，提供 存、读、删 的能力
 */

NS_ASSUME_NONNULL_BEGIN

@protocol TRVStorageProtocol <NSObject>

@required
- (void)saveObject:(NSString *)object forKey:(NSString *)key;

- (NSString *)objectForKey:(NSString *)key;

- (void)removeObjectForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
