//
//  NAMApp.h
//  AriverResource
//
//  Created by nico on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVAppProtocol.h"

NS_ASSUME_NONNULL_BEGIN



@interface RVRApp : NSObject<RVAppProtocol>
@property (nonatomic, readonly, copy) NSString * appId;
@property (nonatomic, readonly, copy) NSString * name;
@property (nonatomic, readonly, copy) NSString * alias; //简称
@property (nonatomic, readonly, copy) NSString * logo;
@property (nonatomic, readonly, copy) NSString * desc;
@property (nonatomic, readonly, copy) NSString * developVersion;
@property (nonatomic, readonly, copy) NSString * deployVersion;
@property (nonatomic, readonly, copy) NSString * fallbackBaseUrl;
@property (nonatomic, readonly, copy) NSString * packageUrl;
@property (nonatomic, readonly, copy) NSDictionary * subPackages;
@property (nonatomic, readonly, copy) NSString * appKey;
@property (nonatomic, readonly, copy) NSString * mainUrl;
@property (nonatomic, readonly, copy) NSString * vhost;
@property (nonatomic, readonly, copy) NSString * packageSize;
@property (nonatomic, readonly, copy) NSString * status; //应用发布状态（之前叫releaseType）
@property (nonatomic, readonly, assign) NSInteger origin; //小程序原始平台（1：支付宝；2：淘宝； 3：蚂蚁国际）
@property (nonatomic, readonly, assign) NSInteger subType; //小程序子类型 (8: 小游戏)

@property (nonatomic, readonly, copy) NSArray * plugins;
@property (nonatomic, readonly, copy) NSDictionary * templateConfig;
@property (nonatomic, readonly, copy) NSDictionary * container;
@property (nonatomic, readonly, copy) NSDictionary * extendInfo;
@property (nonatomic, readonly, copy) NSDictionary * permission;

//只有是插件才带有mainAppId，是插件包时为主关联appId。不是插件为nil
@property (nonatomic, readonly, copy) NSString * mainAppId;

//(当前对象是插件时调用　)把插件和主应用ap相关联，建立引用关系
-(void)associateWithMainAppId:(RVRApp *)mainApp;
@end

NS_ASSUME_NONNULL_END
