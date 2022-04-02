//
//  RVRApp+Plugin.h
//  AriverResource
//
//  Created by nico on 2019/7/2.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "RVRApp.h"
NS_ASSUME_NONNULL_BEGIN

@interface RVRApp (Plugin)
@property (nonatomic, readonly, copy) NSString * requireVersion;
- (BOOL)isPluginExpired;
@end

NS_ASSUME_NONNULL_END
