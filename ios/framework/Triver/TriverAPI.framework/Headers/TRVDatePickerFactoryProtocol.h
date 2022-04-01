//
//  TRVDatePickerFactoryProtocol.h
//  API
//
//  Created by 岚遥 on 2020/4/7.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVDatePickerProtocol.h"
#import <AriverResource/RVRApp.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVDatePickerFactoryProtocol <NSObject>

- (BOOL)enableExtentionDatePickerWithApp:(RVRApp *)currentApp;

- (id<TRVDatePickerProtocol>)createExtensionDatePickerView;

@end

NS_ASSUME_NONNULL_END
