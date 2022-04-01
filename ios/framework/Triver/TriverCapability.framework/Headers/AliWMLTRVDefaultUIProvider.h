//
//  AliWMLTRVDefaultUIProvider.h
//  AliWindmill
//
//  Created by AllenHan on 2019/4/4.
//  Copyright © 2019年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>


@interface AliWMLTRVDefaultUIProvider : NSObject<TRVUIProviderProtocol, TRVPullRefreshProtocol>

/**
 获取具体的Header 工厂
 */
- (id<TRVUIProviderProtocol>)uiProviderInstanceForPage:(TRVBaseViewController*)page;

@end

