//
//  NWIPv6Helper.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 5/15/16.
//  Copyright © 2016 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NWIPv6Helper : NSObject
@property (atomic, strong) NSString *ipv4onlyArpa;

+ (instancetype)sharedInstance;

+ (BOOL)isIPv4address:(NSString *)ip;

- (BOOL)isIPv6only;

- (NSString *)convertIPv4toIPv6:(NSString *)ipv4;

- (void)reset;

@end
