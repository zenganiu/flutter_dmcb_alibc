//
//  DWPlayerConfigProtocol.h
//  Pods
//
//  Created by zzqiltw on 16/4/18.
//
//

#import <Foundation/Foundation.h>

@protocol DWPlayerConfigProtocol <NSObject>

@optional
- (BOOL)getConfigForAllowWiFiAutoPlay DEPRECATED_MSG_ATTRIBUTE("实现逻辑改了，不需要这个接口了");
- (NSDictionary *)getDWInteractiveSDKOrangeConfig;
- (NSDictionary *)getTBMediaPlayerBundleOrangeConfig;
- (BOOL)getConfigForVideoCacheEnable;
- (NSArray*) bizcodeForDisableCache;
- (NSString *) bizcodeForEnableMediaCache;
- (NSString*) bizcodeForEnabledPlayControl;
- (NSString *) machineForEnableH265;
- (NSString *) bizcodeForPlayControlServiceBackupLogic;
- (NSString *) bizcodeForDeferPlayControlRequst;

- (NSString *)interactiveVideoPlayerCoreMode;
- (NSArray *)bizcodesForPlayerCoreABTest;
- (NSString *)playerCoreABTestBucket;
- (BOOL)getConfigForInteractiveButton:(NSString *)buttonName;

- (NSString *)bizcodeStringForDisableFreeFlowGuide;

- (void)getConfigOfAllowWiFiAutoPlayFromMyTaoBao:(void(^)(BOOL))callback;
@end
