//
//  RVTExtensionProtocol4PluginContext.h
//  AriverRuntime
//
//  Created by xuyouyang on 2019/7/14.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVTJSCExecutor;

NS_ASSUME_NONNULL_BEGIN

@protocol RVTExtensionProtocol4PluginContext <NSObject>

@optional
/**
 插件JSContext创建后，完成 biz context 属性复制，插件代码执行前的扩展点。
 */
- (void)beforPluginExecute:(RVTJSCExecutor *)jscExecutor pluginId:(NSString *)pluginId;

/**
 插件代码执行后的扩展点。
 */
- (void)afterPluginExecute:(RVTJSCExecutor *)jscExecutor pluginId:(NSString *)pluginId;

@end

NS_ASSUME_NONNULL_END
