//
//  TRVAppEnvConfig.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/18.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TRVAppEnvConfig : NSObject

+ (instancetype)sharedInstance;

/**
 * 客户端名称，例如 "TB"
 */
@property (nonatomic, strong) NSString *appName;

/**
 * 客户端版本，例如 "7.11.0"
 */
@property (nonatomic, copy) NSString *appVersion;

/**
 * 是否为阿里集团app，会影响 UA，默认值为：YES
 */
@property (nonatomic, assign) BOOL isAliApp;

/**
 * 是否 APP 为调试模式，非 Release 模式
 */
@property (nonatomic, assign) BOOL isAppDebugMode;

/**
 * SDK 框架的版本
 */
@property (nonatomic, strong, readonly) NSString *sdkVersion;
/**
 * 客户端网络环境，值为 "online" | "pre" | "test"
 */
@property (nonatomic, strong) NSString *hostEnv;
/**
 *  inside 应用唤起支付宝 app 操作之后，返回回去的 app scheme，具体场景比如收银台唤起支付宝支付，支付成功后返回。
 *  ！！注意：1.集成了标准版 AlipaySDK 一定要传
 *          2.集成了专业版 AlipaySDK 如果有针对scheme做业务分流也要传
 */
@property (nonatomic, assign) NSString *appScheme;


/**
 * 是否 开启三方MTOP，默认不开启，三方主动主动设置开启
 */
@property (nonatomic, assign) BOOL openMtopEnable;

/**
 * 自定义小程序MTOP请求和页面UA
 */
@property (nonatomic, copy) NSString *customUA;

/**
 * 小程序 RPC 调用deviceId, 可以为nil, 需要传递的端可以从 UTDID.framework [UTDevice utdid] 获取
 */
@property (nonatomic, copy) NSString *rpcDeviceId;

/**
* 自定义小程序UT默认参数
*/
@property (nonatomic, strong) NSDictionary *customUTParams;

/**
 * 自定义小程序AppMonitor埋点page
*/
@property (nonatomic, copy) NSString *customMonitorPage;

@end

