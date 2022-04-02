//
//  DWInstanceModule.h
//  DWInteractiveSDK
//
//  Created by jyi on 16/4/15.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <DWInteractiveSDK/Config.h>
#import <Foundation/Foundation.h>
#if !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
#import <WeexSDK/WXModuleProtocol.h>
#endif // !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
#import <DWInteractiveSDK/DWComponent.h>
extern NSString * const kDWInstanceModuleShowToastNotification;
extern NSString * const kDWInstanceModuleShowToastUserInfoKeyName;
extern NSString * const kDWInstanceModuleShowToastDuring;

extern NSString * const kDWInstanceModuleSyncDataNotification;
extern NSString * const kDWInstanceModuleOpenUrlActionNotification;
extern NSString * const kDWInstanceModuleQuitFullScreenNotification;

@interface DWWeakObject : NSObject

@property (nonatomic, weak) id weakObject;

@end

@interface DWInstanceModule : NSObject
#if !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
<WXModuleProtocol>
// 暂时放在这里，抽工具类
+ (UILabel *)toast:(NSString *)hint inView:(UIView *)view dismissAfterSeconds:(NSTimeInterval)seconds delayTime:(NSTimeInterval)delayTime isFullScreen:(BOOL)isFullScreen;
#endif // !defined(BUILD_FOR_BAICHUAN) || !(BUILD_FOR_BAICHUAN)
@end

