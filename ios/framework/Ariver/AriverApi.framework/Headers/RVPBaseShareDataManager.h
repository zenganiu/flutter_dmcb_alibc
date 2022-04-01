//
//  RVPBaseShareDataManager.h
//  AriverApi
//
//  Created by 张光宇 on 2019/5/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPBaseShareDataManager : NSObject

- (void)setSharedData:(NSDictionary *)sharedData;

- (NSString *)sharedDataForKey:(NSString *)key readFromFile:(BOOL)readFromFile;

- (void)removeSharedDataForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
