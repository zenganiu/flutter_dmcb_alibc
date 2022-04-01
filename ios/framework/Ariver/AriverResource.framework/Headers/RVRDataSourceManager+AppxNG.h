//
//  RVRDataSourceManager+AppxNG.h
//  AriverResource
//
//  Created by lyusheng on 2020/2/4.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import "RVRDataSourceManager.h"
#import "RVRDataSourceManager+Load.h"

NS_ASSUME_NONNULL_BEGIN

/// \discussion AppxNG支持的实现
@interface RVRDataSourceManager (AppxNG)

@property (nonatomic, readonly) BOOL enableAppxNG;
@property (nonatomic) NSDictionary *mergedLaunchParams;
- (NSString *)appxngAppId;

/// 主包、资源包、分包都要经过
/// @param url 离线资源的虚拟路径
- (NSString *)urlRouted2Appxng:(NSString *)url;

/// 仅主包资源的fallback
/// @param url 离线资源的虚拟路径
- (NSString *)mainAppFallbackUrlRouted2Appxng:(NSString *)url;
@end

NS_ASSUME_NONNULL_END
