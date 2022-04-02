//
//  RVTData.h
//  AriverRuntime
//
//  Created by runfeng.crf on 2019/9/2.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//用于包装NSData避免jsapi调用路径上性能问题
@interface RVTData : NSObject

@property (nonatomic, strong, readonly) NSData *data;

- (instancetype)initWithBytes:(void *)bytes length:(NSUInteger)length;
- (instancetype)initWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
