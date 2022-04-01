//
//  TRVAppContainerDowngradeProtocol.h
//  AppContainer
//
//  Created by xuyouyang on 2020/2/17.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverResource/RVRApp.h>
#import <TriverAppContainer/TRVAppContainer.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVAppContainerDowngradeProtocol <NSObject>

/**
 小程序降级 URL 配置
 */
- (NSString *)downgradeURLWithAppContainer:(TRVAppContainer *)appContainer;

@end

NS_ASSUME_NONNULL_END
