//
//  RVRDataSourceManagerLogProtocol.h
//  AriverResource
//
//  Created by nico on 2019/3/24.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef NXRDataSourceManagerLogProtocol_h
#define NXRDataSourceManagerLogProtocol_h
#import <AriverKernel/AriverKernel.h>

@protocol RVRDataSourceManagerLogProtocol <NSObject>

@optional
/*
 * H5_AL_SESSION_MAP_SUCCESS
 */
- (void)mainResourceDidMap:(RVKProxyEvent *)event;

/*
 * H5_AL_SESSION_HTTPPROXY
 * H5_AL_RESOURCE_FIRST_OFFLINE
 */
- (void)commonResouceDidMap:(NSURLRequest *)request dataSource:(RVRDataSource *)dataSource page:(RVKPage *)page;

/*
 * H5_AL_SESSION_FALLBACK
 */
- (void)mainResourceDidFallback:(RVKProxyEvent *)event redirectUrl:(NSURL *)redirectUrl;

/*
 * H5_APP_EXCEP
 */
- (void)mainUrlResourceDidDiscarded:(RVKProxyEvent *)event info:(NSString *)info;

/*
 * pkg of performance
 */
- (void)recordResourceStatus:(RVKProxyEvent *)event;

/*
 * local log info
 */
- (void)logInfo:(NSString *)desc;

@end

#endif /* NXRDataSourceManagerLogProtocol_h */
