//
//  RVRRequestManager.h
//  NebulaResource
//
//  Created by 扶瑶 on 16/4/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RVRRequsetManagerProtocol <NSObject>

@optional
- (void)processData:(NSDictionary *)data
            reqlist:(NSDictionary *)reqlist
             params:(NSDictionary *)params;

@end

@interface RVRRequestManager : NSObject <RVRRequsetManagerProtocol>
-(id)initWithKey:(NSString *)requestKey;
/**
 *  全量请求
 *
 *  @param param        参数, 暂时无用可传nil
 *  @param autoDownload 是否自动下载
 *  @param finish       完成回调
 */
- (void)requestAllApps:(NSDictionary *)params
          autoDownload:(BOOL)autoDownload
                finish:(NXRRequestFinish)finish;


/**
 *  单个请求
 *
 *  @param param        参数, 暂时无用可传nil
 *  @param autoDownload 是否自动下载
 *  @param finish       完成回调
 */
- (void)requestApps:(NSDictionary *)dicApps
       autoDownload:(BOOL)autoDownload
             params:(NSDictionary *)params
             finish:(NXRRequestFinish)finish;

/**
 * 其他渠道数据更新处理
 * 注: 仅在合并rpc应用中心触发兜底逻辑时调用, 不支持强大rpc, params默认为nil
 */
- (void)processData:(NSDictionary *)data
            reqlist:(NSDictionary *)reqlist
       autoDownload:(BOOL)autoDownload;



/**
 *  请求插件信息
 *  plugin {appId:version}
 *  @param param        参数, 暂时无用可传nil
 *  @param autoDownload 是否自动下载
 *  @param finish       完成回调
 */
- (void)requestPlugin:(NSDictionary *)plugin
               params:(NSDictionary *)params
               finish:(NXRRequestFinish)finish;
@end
