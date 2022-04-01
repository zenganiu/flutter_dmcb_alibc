//
//  RVKJsApi.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKContext;
@class RVKJsApiHandler;

typedef void (^RVKJsApiResponseCallbackBlock)(id responseData);
typedef void (^RVKJsApiHandlerBlock)(NSDictionary *data, RVKContext *context, RVKJsApiResponseCallbackBlock responseCallbackBlock);

//JsApi类，注：优先使用RVKJsApiHandlerBlock，若不存在，才使用handlerClass进行处理
@interface RVKJsApi : NSObject 

@property(nonatomic, readonly, copy) NSString               *name; // JsApi名称
@property(nonatomic, copy) NSString *alias;
@property(nonatomic, readonly, strong) RVKJsApiHandlerBlock handler; // JsApi处理函数，优先使用
@property(nonatomic, readonly, strong) Class                handlerClass; // JsApi处理类
@property(nonatomic, readonly, assign) BOOL                 checkParams; // 是否检查参数（检查是否NSDictionary类型）
@property(nonatomic, readonly, assign) BOOL                 isPrivate; // 是否私有（决定是否能被反注册、覆盖）
@property(nonatomic, readonly, copy) NSString               *scope; // 作用域

@property(nonatomic, strong) RVKJsApiHandler                *jsApiHandler;
/**
 *  @brief 创建一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param name    JsApi名称
 *  @param handler JsApi处理函数
 *
 *  @return 返回一个JsApi对象
 */
+ (instancetype)jsApi:(NSString *)name
              handler:(RVKJsApiHandlerBlock)handler;

/**
 *  @brief 创建一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param name         JsApi名称
 *  @param handlerClass JsApi处理类
 *
 *  @return 返回一个JsApi对象
 */
+ (instancetype)jsApi:(NSString *)name
         handlerClass:(Class)handlerClass;

/**
 *  @brief 创建一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param name    JsApi名称
 *  @param handler JsApi处理函数
 *  @param checkParams 是否检查参数
 *  @param isPrivate 是否私有api
 *  @param scope 作用域
 *
 *  @return 返回一个JsApi对象
 */
+ (instancetype)jsApi:(NSString *)name
              handler:(RVKJsApiHandlerBlock)handler
          checkParams:(BOOL)checkParams
            isPrivate:(BOOL)isPrivate
                scope:(NSString *)scope;

/**
 *  @brief 创建一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param name    JsApi名称
 *  @param alias   JsApi别名
 *  @param handler JsApi处理函数
 *  @param checkParams 是否检查参数
 *  @param isPrivate 是否私有api
 *  @param scope 作用域
 *
 *  @return 返回一个JsApi对象
 */
+ (instancetype)jsApi:(NSString *)name
                alias:(NSString *)alias
              handler:(RVKJsApiHandlerBlock)handler
          checkParams:(BOOL)checkParams
            isPrivate:(BOOL)isPrivate
                scope:(NSString *)scope;

/**
 *  @brief 创建一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param name         JsApi名称
 *  @param handlerClass JsApi处理类
 *  @param checkParams 是否检查参数
 *  @param isPrivate 是否私有api
 *  @param scope 作用域
 *
 *  @return 返回一个JsApi对象
 */
+ (instancetype)jsApi:(NSString *)name
         handlerClass:(Class )handlerClass
          checkParams:(BOOL)checkParams
            isPrivate:(BOOL)isPrivate
                scope:(NSString *)scope;

/**
 *  @brief 创建一个JsApi对象
 *
 *  @date 2014-08-20
 *
 *  @param name         JsApi名称
 *  @param alias        JsApi别名
 *  @param handlerClass JsApi处理类
 *  @param checkParams 是否检查参数
 *  @param isPrivate 是否私有api
 *  @param scope 作用域
 *
 *  @return 返回一个JsApi对象
 */
+ (instancetype)jsApi:(NSString *)name
                alias:(NSString *)alias
         handlerClass:(Class )handlerClass
          checkParams:(BOOL)checkParams
            isPrivate:(BOOL)isPrivate
                scope:(NSString *)scope;

/**
 *  @brief 处理JsApi函数
 *
 *  @date 2014-08-20
 *
 *  @param data     处理的消息参数
 *  @param context  当前上下文信息
 *  @param callback 回调
 *
 *  @return 无
 */
- (void)handler:(NSDictionary *)data context:(RVKContext *)context callback:(RVKJsApiResponseCallbackBlock)callback;

@end
