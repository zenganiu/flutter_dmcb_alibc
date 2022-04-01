//
//  RVKJsFileManager.h
//  Poseidon
//
//  Created by chenwenhong on 14-10-24.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RVKFilePreloadManager : NSObject

+ (NSString *)jsBridgeFileContentString;

+ (NSDictionary *)kernelConfigDict;

+ (NSDictionary *)kernelExtraConfigDict;

+ (NSDictionary *)ariverConfigDict;

@end
