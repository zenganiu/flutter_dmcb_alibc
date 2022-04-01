//
//  TRVAppContainer+domainPermissionManager.h
//  AppContainer
//
//  Created by 岚遥 on 2020/2/17.
//  Copyright © 2020 Taobao. All rights reserved.
//


#import "TRVAppContainer.h"
#import "TRVCustomizeDomainPermissionManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TRVAppContainer (domainPermissionManager)

@property (nonatomic, strong) TRVCustomizeDomainPermissionManager *domainPermissionManager;

@end

NS_ASSUME_NONNULL_END
