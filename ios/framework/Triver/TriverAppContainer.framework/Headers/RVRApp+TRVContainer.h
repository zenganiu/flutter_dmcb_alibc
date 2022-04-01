//
//  RVRApp+TRVContainer.h
//  Triver
//
//  Created by zhongweitao on 2019/7/17.
//

#import <AriverResource/RVRApp.h>

@interface RVRApp (TRVContainer)

/// 是否是网络错误从缓存中读取的
@property (nonatomic, assign) BOOL isFromCacheWhenError;

- (BOOL)enableKeepAlive;

- (NSString *)subBizType;

- (NSString *)bizType;

- (BOOL)isShopMiniApp;

@end
