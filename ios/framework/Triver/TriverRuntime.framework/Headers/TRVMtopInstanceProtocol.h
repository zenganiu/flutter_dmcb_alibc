//
//  TRVMtopInstanceProtocol.h
//  Triver
//
//  Created by zhongweitao on 2019/8/26.
//

#import <Foundation/Foundation.h>

#if __has_include(<mtopext/MtopExtRequest.h>)
    #import <mtopext/MtopExtRequest.h>
    #import <mtopext/MtopExtResponse.h>
    #import <mtopext/MtopService.h>
#else
    #import <MtopCore/MtopExtRequest.h>
    #import <MtopCore/MtopExtResponse.h>
    #import <MtopCore/MtopService.h>
#endif

/// @brief Inside客户端存在多实例mtop的情况需要适配该协议
@protocol TRVMtopInstanceProtocol <NSObject>

@optional
/// @brief MTOP多实例场景下，小程序框架发起MTOP请求或者sendMtop未指定instance的情况下使用的淘宝MTOP实例
- (MtopService *)trv_taobaoMtopService;

/// @brief MTOP多实例场景下，根据sendMtop指定instance参数获取mtop实例
/// @param instanceId mtop实例ID
- (MtopService *)trv_mtopServiceForInstanceId:(NSString *)instanceId;

@end
