//
//  RVKService+Private.h
//  Poseidon
//
//  Created by chenwenhong on 15-1-28.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//


@interface RVKService (Private)

/**
 *  @brief 在默认分组下，反注册一个插件
 *
 *  @date 2014-09-03
 *
 *  @param pluginCfg 插件配置对象
 *
 *  @return 无
 */
- (void)unRegisterPlugin:(RVKPluginConfig *)pluginCfg;

/**
 *  @brief 反注册一个JsApi，在默认分组下
 *
 *  @date 2014-09-03
 *
 *  @param jsApi   jsApi对象
 *
 *  @return 无
 */
- (void)unRegisterJsApi:(RVKJsApi *)jsApi; // 默认分组


/**
 恢复WK同步过的CooKie
 */
- (void)recoveryCookies;

@end
