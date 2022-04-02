//
//  RVKSession+JSEvent.h
//  AriverApp
//
//  Created by runfeng.crf on 2020/2/7.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <AriverKernel/AriverKernel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVKSession (JSEvent)

/**
*  从Native调用当前栈顶的h5页面的JS函数，避免使用vc的callhandler发生前一个vc被销毁而发送失败的场景
*
*  @param handlerName 函数名
*  @param data        函数参数
*  @param callback    JS端执行完后回调处理block
*/
- (void)callHandler:(NSString *)handlerName data:(id)data responseCallback:(void(^)(id responseData))callback;

@end

NS_ASSUME_NONNULL_END
