//
//  SPDYNetworkStatusManager.h
//  SPDY
//
//  Created by 亿刀 on 14-1-9.
//  Copyright (c) 2014年 Twitter. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 通过[NSNotificationCenter defaultCenter]监听网络状态变化通知。
 * 收到通知后，可以通过 NWReachabilityManager.currentNetworkStatus 获取当前网络状态。
 *
 * 注意：该通知在非主线程通知。
 */
#define NW_NETWOEK_STATUS_NOTIFY @"TBNetworkStatusChangeNotify"

extern NSString*  const  NETWOEK_STATUS_NOTIFY; // same as NW_NETWOEK_STATUS_NOTIFY, for swift


/**
 * 网络状态
 */
typedef NS_ENUM(NSUInteger, NetworkStatus) {
    NotReachable = 0,
    ReachableViaWiFi,
    ReachableVia2G,
    ReachableVia3G,
    ReachableVia4G
};


/**
 * Reachability 接口
 */
@interface NWReachabilityManager : NSObject

+ (NWReachabilityManager *)shareInstance;

- (NSString *)currentIMSI;

- (NSString *)currentCarrierName;

- (NetworkStatus)currentNetworkStatus;

- (NetworkStatus)preNetworkStatus;

- (NSString *)currentNetworkStatusString:(NetworkStatus)status;

- (NSString *)currentNetworkStatusString;

- (NSString *)currentAPN;

- (NSString *)getWifiSSID;

- (NSString *)getWifiBSSID;

- (NSString *)uniqueSSID;

- (NSString *)getWiFiSSIDMD5;

- (void)updateWifiSSID;

+ (BOOL)configureProxies;

@end
