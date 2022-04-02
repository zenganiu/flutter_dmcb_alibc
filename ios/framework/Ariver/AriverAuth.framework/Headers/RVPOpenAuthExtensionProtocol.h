//
//  RVPOpenAuthExtensionProtocol.h
//  AriverAuth
//
//  Created by Klueze on 2020/2/18.
//  Copyright © 2020 Alipay. All rights reserved.
//

#ifndef RVPAuthProtocol_h
#define RVPAuthProtocol_h

@class RVKContext;

typedef void(^RVPAuthCompleteBlock)(BOOL authProcessed, id responseData);

// Auth相关API的协议
// 国际化小程序引入
@protocol RVPOpenAuthExtensionProtocol <NSObject>

/**
Auth方法统一入口
所有授权 JSAPI 都会进入改方法调用，用于各接入方注入实现Auth流程的自定义
 
@param data JSAPI 调用传入的参数
@param context JSAPI 调用的上下文
@param completion 外部处理的回调，请务必将 authProcessed 设为 YES，并返回有效的 responseData，否则将进入默认授权流程
*/
- (void)authorizeWithData:(NSDictionary *)data context:(RVKContext *)context completion:(RVPAuthCompleteBlock)completion;

@end

#endif
