//
//  需要子类重载的方法
//  RVBaseShareDataManager+SubClass.h
//  AriverApi
//
//  Created by 张光宇 on 2019/5/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "RVPBaseShareDataManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface RVPBaseShareDataManager(SubClass)

//! 字符串加密，默认返回原始String
- (NSString *)stringWithAESEncrypt:(NSString *)string;

//! 字符串解密，默认返回原始String
- (NSString *)stringWithAESDecrypt:(NSString *)string;

//! 写数据
//    [APCommonPreferences setObject:sharedDataDic forKey:SHARED_DATA_KEY business:SHARED_DATA_BIZ];
- (void)doWriteSharedData:(NSDictionary *)sharedDataDic;

//! 读数据
//    [APCommonPreferences objectForKey:SHARED_DATA_KEY business:SHARED_DATA_BIZ];
- (NSDictionary *)doReadSharedData;

@end

NS_ASSUME_NONNULL_END
