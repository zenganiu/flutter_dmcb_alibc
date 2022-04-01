//
//  RVRAppUtils.h
//  Ariver
//
//  Created by zhongweitao on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "RVRAppEnterInfo.h"

@interface RVRAppUtils : NSObject

/// @brief 小程序URL解析
+ (RVRAppEnterInfo *)extractEnterInfoWithAppUrl:(NSString *)appUrl error:(NSError *__autoreleasing *)error;

/// @brief 判断是否是小程序URL
+ (BOOL)isAppUrl:(NSString *)url;

@end
