//
//  TRVApiDynamicDispatchHandler.h
//  Runtime
//
//  Created by xuyouyang on 2019/8/25.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TRVApiCustomDispatchCallback)(id responseData);

@interface TRVApiCustomDispatchContext : NSObject

/**
 API 名称
 */
@property (nonatomic, strong) NSString *apiName;
/**
 参数
 */
@property (nonatomic, strong) NSDictionary *params;
/**
 返回值
 */
@property (nonatomic, strong) TRVApiCustomDispatchCallback callback;
/**
 当前容器
 */
@property (nonatomic, strong) UIViewController *currentVC;

@end


@interface TRVApiCustomDispatchHandler : NSObject

/**
 根据上下文创建一个处理 api 的 handler
 */
- (instancetype)initWithContext:(TRVApiCustomDispatchContext *)context;

/**
 触发 API 调用
 */
- (void)invoke;

@end

NS_ASSUME_NONNULL_END

