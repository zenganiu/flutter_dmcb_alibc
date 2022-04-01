//
//  TRVNetworkStatusProtocol.h
//  Triver
//
//  Created by zhongweitao on 2019/11/19.
//

#import <Foundation/Foundation.h>
#import <AriverApi/RVPNetworkImpl.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVNetworkStatusProtocol <NSObject>

@required
- (RVPNetworkStatus )networkStatus;

- (BOOL)isReachableVia3G;

- (BOOL)isReachableVia2G;

@end

NS_ASSUME_NONNULL_END
