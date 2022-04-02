//
//  TRVOptionPickerFactoryProtocol.h
//  API
//
//  Created by 岚遥 on 2020/4/7.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVOptionPickerProtocol.h"
#import <AriverResource/RVRApp.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVOptionPickerFactoryProtocol <NSObject>

- (BOOL)enableExtensionOptionPickerWithApp:(RVRApp *)currentApp;

- (id<TRVOptionPickerProtocol>)createExtensionOptionPickerView;

@end

NS_ASSUME_NONNULL_END
