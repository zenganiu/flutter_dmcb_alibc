//
//  MediaDeviceInfo.h
//  Image
//
//  Created by 岚遥 on 2020/2/10.
//  Copyright © 2020 alibaba.inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 判断当前设备是否是 iPad。
 */
NS_INLINE BOOL miniAppMediaDeviceModelIsIPad() {
    return [[[UIDevice currentDevice] model] isEqualToString:@"iPad"];
}

NS_ASSUME_NONNULL_END
