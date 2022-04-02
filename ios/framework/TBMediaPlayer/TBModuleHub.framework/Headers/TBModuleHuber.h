//
//  TBModuleHuber.h
//  TBModuleHub
//
//  Created by qiufu on 7/19/16.
//  Copyright © 2016 CX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBModuleHuber : NSObject

/*!
 * @abstract 创建 TBModuleHuber 单例。
 * @return 返回 TBModuleHuber 单例。
 */
+ (instancetype)sharedInstance;

/*!
 * @abstract 根据给定的 url 解析出对应的 selectorName/className，调用对应的实例方法。
 * @param url 模式为：scheme://[class]/[selector]?[params]，比如：tb://TBXXXClass/xxxmethod?param1=1&param2=2
 * @return 返回调用结果。
 */
- (id)callInstanceMethodWithURL:(NSURL *)url completion:(void(^)(NSDictionary *info))completion;

/*!
 * @abstract 根据给定的 url 解析出对应的 selectorName/className，调用对应的类方法。
 * @param url 模式为：scheme://[class]/[selector]?[params]，比如：tb://TBXXXClass/xxxmethod?param1=1&param2=2
 * @return 返回调用结果。
 */
- (id)callClassMethodWithURL:(NSURL *)url completion:(void(^)(NSDictionary *info))completion;

/*!
 * @abstract 根据给定的 selectorName/className，调用对应的实例方法。
 * @return 返回调用结果。
 */
- (id)callInstanceMethodWithSelectorName:(NSString *)selectorName className:(NSString *)className parameters:(NSDictionary *)parameters;

/*!
 * @abstract 根据给定的 selectorName/className，调用对应的类方法。
 * @return 返回调用结果。
 */
- (id)callClassMethodWithSelectorName:(NSString *)selectorName className:(NSString *)className parameters:(NSDictionary *)parameters;

@end
