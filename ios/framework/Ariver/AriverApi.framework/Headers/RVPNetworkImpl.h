//
//  RVPNetworkImpl.h
//  AriverApi
//
//  Created by hua.lu on 2019/5/9.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum
{
    // Apple NetworkStatus Compatible Names.
    RVPNotReachable     = 0,
    RVPReachableViaWWAN = 1,
    RVPReachableViaWiFi = 2,
}RVPNetworkStatus;

@protocol RVPNetworkImplProtocol <NSObject>
-(RVPNetworkStatus )networkStatus;      //[DTReachability sharedDTReachability].networkStatus
-(BOOL)isReachableVia3G;                //[DTReachability sharedDTReachability].isReachableVia3G
-(BOOL)isReachableVia2G;                //[DTReachability sharedDTReachability].isReachableVia2G
@end

@interface RVPNetworkImpl : NSObject

+ (NSString *)H5RVPNetWorkName;

+ (NSString *)H5RVPNetWorkType;

+ (id<RVPNetworkImplProtocol>)rvpNetwork;

@end

NS_ASSUME_NONNULL_END
