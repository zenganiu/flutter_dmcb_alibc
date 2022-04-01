//
//  NXRProtocol.h
//  NebulaResource
//
//  Created by 扶瑶 on 16/3/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

typedef NS_ENUM (NSUInteger, NXRLogStep) {
    NXRLogStepBegin = 0,
    NXRLogStepFinished,
};

/**
 *  包管理原始埋点类型, 已通过NebulaSDK中NBMonitor输出, 业务方直接使用NBMonitor代理即可
 *
 *  埋点seedId:
 *
 *      NXRLogTypePrepareApp            H5_APP_PREPARE
 *      NXRLogTypeDownloadApp           H5_APP_DOWNLOAD
 *      NXRLogTypeUnzipApp              H5_APP_UNZIP
 *      NXRLogTypeVerifyApp             H5_APP_VERIFY
 *      NXRLogTypeRequestApps           H5_APP_REQUEST
 *      NXRLogTypeAppPool               H5_APP_POOL
 *      NXRLogTypeExceptionHandler      H5_APP_EXCEP
 *
 */
typedef NS_ENUM (NSUInteger, NXRLogType) {
    NXRLogTypeUnknown = 0,
    NXRLogTypePrepareApp,           // 准备应用
    NXRLogTypeDownloadApp,          // 下载应用
    NXRLogTypeUnzipApp,             // 解压应用 (增量更新)
    NXRLogTypeVerifyApp,            // 验签应用
    NXRLogTypeRequestApps,          // 请求应用
    NXRLogTypeAppPool,              // 包管理池变更,增、删、改
    NXRLogTypeExceptionHandler,     // 异常管理, 1. 强制请求列表增、删 2. 验证url
    
    // Webstat
    NXRLogTypeWebstatZhuangjiliang, // 装机量埋点
    
    // Netstat
    NXRLogTypeNetstatChannel        // 网络性能埋点
};

@interface RVRLogContext : NSObject;
@property (nonatomic, assign) NXRLogType type;
@property (nonatomic, assign) NXRLogStep step;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSDictionary *data;
@property (nonatomic, copy) NSString *customStep;
@property (nonatomic, copy) NSString *seedId;

+ (RVRLogContext *)type:(NXRLogType)type
                   step:(NXRLogStep)step;

+ (RVRLogContext *)type:(NXRLogType)type
                   step:(NXRLogStep)step
                  error:(NSError *)error
                   data:(NSDictionary *)data;

+ (RVRLogContext *)type:(NXRLogType)type
                cusStep:(NSString *)cusStep
                   data:(NSDictionary *)data;

+ (RVRLogContext *)type:(NXRLogType)type
                cusStep:(NSString *)cusStep
                  error:(NSError *)error
                   data:(NSDictionary *)data;

+ (RVRLogContext *)type:(NXRLogType)type
                   data:(NSDictionary *)data;

/**
 *  获取log唯一标识
 *
 *  @return string
 */
- (NSString *)seedId;

/**
 *  获取log参数
 *
 *  @return {key:value}
 */
- (NSDictionary *)params;
@end


