//
//  TRViPadUtils.h
//  API
//
//  Created by 岚遥 on 2020/2/7.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TRViPadUtils : NSObject

/**
 寻找与指定 ViewController 相关的顶层 ViewController。

 @return 顶层 ViewController。
 */
+ (UIViewController *)iPadTopViewController:(UIViewController *)viewController;

/**
 判断当前设备是否为 iPad
 */
BOOL TRVDeviceModelIsIPad(void);

/**
 判断当前设备是否可以使用iPad 自适应layout
 */
BOOL TRVEnableIPadAdaptivelayout(void);

@end

NS_ASSUME_NONNULL_END
