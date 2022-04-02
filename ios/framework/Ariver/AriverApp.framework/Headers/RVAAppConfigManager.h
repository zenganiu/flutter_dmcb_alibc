//
//  RVAAppConfigManager.h
//  AriverApp
//
//  Created by theone on 17/3/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RVAAppConfigManager : NSObject
@property(nonatomic, strong, readonly) NSDictionary *config;

- (instancetype)initWithConfig:(NSDictionary *)config;

/**
 *  合并配置文件中的参数到context中
 *
 *  @date 2017-03-07
 *
 */
- (void)mergeAppConfigParamsToContextParams:(RVASessionContext *)context;


/**
 *  依据Tag来合并的为最终参数
 *
 *  @date 2017-03-07
 *
 */
- (NSDictionary *)mergeParams:(NSDictionary *)params withTag:(NSString*)tag;


/**
 *  依据page来合并参数
 *
 *  @date 2017-03-07
 *
 */
- (void)addPluginPageParams:(NSDictionary *)params page:(NSString *)page;

@end
