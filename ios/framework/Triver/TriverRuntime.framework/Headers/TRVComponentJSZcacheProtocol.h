//
//  TRVComponentJSZcacheProtocol.h
//  Runtime
//
//  Created by 岚遥 on 2019/11/4.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVComponentJSZcacheProtocol <NSObject>

- (NSData *)readAppendComponentJSFromZcacheWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
