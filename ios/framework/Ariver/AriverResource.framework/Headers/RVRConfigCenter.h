//
//  RVRConfigCenter.h
//  AriverResource
//
//  Created by nico on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVRProtocol.h"
#import "RVRDataSource.h"
#define kARVAppxAppId    @"66666692"

//和预置包相关逻辑的delegate
@protocol RVRPresetConfigDelegate <NSObject>
@optional
//当前应用下多投配置的信息
-(NSString * _Nullable)includeConfig:(RVRDataSource *_Nullable)appDataSource;
- (BOOL)enableFixHexValue;
//预置包plist文件名
-(NSString *_Nullable)presetPlistName;
//预置包bundle名
-(NSString *_Nullable)presetBundleName;
//是否是覆盖更新
-(BOOL )isCoverInstall;
/**
 * 查看预置离线包信息
 *  @{@"66666692":@""};
 */
-(NSDictionary *_Nullable)presetAmrApps;
/**
 *公共资源包AppId列表;
 *@[@"66666692"];
 */
-(NSArray *_Nullable)commonAppList;

/**
 * 小程序appx依赖的appx appId
 */
-(NSString *_Nullable)appxId;

/**
 *
 */
-(NSString *_Nullable)commonMinAppxVersion;

/**
 * 是否开启appx minAppxVersion判断
 */
- (BOOL)enableMinAppxVersionCompare;

/**
 预加载Tar包
 
 @param appId tar包对应的AppId
 @return 预加载内容
 */
- (id _Nullable )preloadTarDataForApp:(NSString *_Nonnull)appId;

/**
获取自定义vhost

@param app appInfo
@return 预加载内容
*/
- (NSString *_Nullable)customVhostForApp:(RVRApp *_Nonnull)app;
@end

#ifdef __cplusplus
extern "C" {
#endif
    id<RVRLogManagerDelegate> _Nonnull  RVRLogMgr(void);
    id<RVRAppInterfaceDelegate> _Nonnull  RVRAppInterfaceGet(void);
    id<RVRConfigManagerDelegate> _Nonnull RVRConfigManagerGet(void);
    id<RVRMonitorDelegate> _Nonnull RVRMonitorManagerGet(void);
    id<RVRAppPoolProtocol> _Nonnull RVRAppPoolGet(NSString * _Nullable scene);
    id<RVRAppPoolProtocol> _Nonnull RVRAppPoolDefaultGet(void);
    id<RVRRequestCenterDelegate> _Nonnull RVRRequestCenterGet(void);
    id<RVRDownloadManagerDelegate> _Nonnull RVRDownloadManagerGet(void);
    id<RVRZipArchiveManagerDelegate> _Nonnull RVRZipManagerGet(void);
    id<RVRPresetConfigDelegate> _Nonnull RVRPresetConfigGet(void);
#ifdef __cplusplus
}
#endif

@interface RVRConfigCenter : NSObject
+(_Nonnull instancetype)shared;

//核心功能相关，必须设置
@property(nonatomic, weak)__nullable id<RVRRequestManagerDelegate> requestManagerDelegate;
@property(nonatomic, weak)__nullable id<RVRDownloadManagerDelegate> downloadManagerDelegate;
@property(nonatomic, weak)__nullable id<RVRZipArchiveManagerDelegate> zipArchiveDelegate;
@property(nonatomic, weak)__nullable id<RVRAppPoolManagerProtocol> appPoolManagerDelegate;
@property(nonatomic, weak)__nullable id<RVRPresetConfigDelegate> presetConfigDelegate;

//支付宝侧使用老验签模块进行代理
@property (nonatomic, weak) __nullable id <RVRSignVerifyDelegate> signVerifyDelegate;
#if PRODUCT_WALLET
//动态配置功能开关
//使用Cache-Control"设置离线包内子资源缓存，优化二次进入页面的渲染速度
@property (nonatomic, strong) NSDictionary *_Nullable useBrowserCacheConfig;
#endif
//小程序多语言支持(当前语言环境)
@property (nonatomic, strong) NSString *_Nullable currentLanguage;
@end

