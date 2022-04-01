//
//  TRVSendMtopPrefetchProtocol.h
//  Embed
//
//  Created by 岚遥 on 2019/10/29.
//  Copyright © 2019 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVSendMtopPrefetchProtocol <NSObject>

/**
 判断是否可以预取数据
 */
- (BOOL)enableSendPrefetchMtopWithMtopName:(NSString *)mtopName
                                     params:(NSDictionary *)params
                              appContainer:(id)appContainer;

/**
 前端数据预取接口
 */
- (NSDictionary *)sendMtopPrefetchWithMtopName:(NSString *)mtopName
                                        params:(NSDictionary *)params
                                  appContainer:(id)appContainer;

@end

NS_ASSUME_NONNULL_END
