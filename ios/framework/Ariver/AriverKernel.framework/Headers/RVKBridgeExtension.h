//
//  RVKBridgeExtension.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "RVKBridgeMethodInfo.h"
#import "RVKDefines.h"
#import "RVKBridgeMethodInfoManager.h"
#import "RVKExtension.h"
#import "RVKJsApi.h"
#import "RVKPage.h"
#import "RVKScene.h"

/*!
 使用RVKBridgeExtension来注册Jsapi，新增Extension继承自RVKBridgeExtension，一个Extension可以实现多个jsapi
 * jsapi实现方法：
    * 通过RVK_DEFINE_JSAPI宏在Extension中定义jsapi
 * 参数说明
   * 第一个参数是jsapi的名称
   * 第二个jsapi实现对应的方法，需要指定每一个需要的参数名称以及类型，会按照参数名称和类型
      从前端传入的字典中自动映射到对应的参数中，映射规则是按照参数名称从字典中取到对应的值
      并且会做参数类型判断，如果类型不符合预期会直接回调前端参数错误
      对于必填参数可以通过方法参数中指定nonnull nullable等来表示
      该参数是否必填，如果必填项前端没有传入会直接提示入参错误
      目前参数可以指定以下类型:@[@"NSString",@"NSNumber",@"NSDictionary",@"NSArray",@"NSDate",@"BOOL"]
   *  第三个参数是是否支持重写，支持就是Y,不支持就是N
 * 其他
   * 实现方可以直接拿到当前的Page对象和callback函数，无需自己在方法中添加
 * 示范
 ```
 //注册setTitle这个jsapi，不可复写，没有别名
 RVK_DEFINE_JSAPI(setTitle, setTitle:(NSString *)title bb:(NSString *)cc)
 {
 RVKScene *currentPage = page;
 NSLog(@"====>%@",page);
 callback(@{});
 }
 
 //注册setTitle这个jsapi，可复写，没有别名
 RVK_DEFINE_JSAPI(setTitle, setTitle:(NSString *)title bb:(NSString *)cc,Y)
 {
 RVKScene *currentPage = page;
 NSLog(@"====>%@",page);
 callback(@{});
 }
 
 //注册setTitle这个jsapi，可复写，别名setBizTitle
 RVK_DEFINE_JSAPI(setTitle, setTitle:(NSString *)title bb:(NSString *)cc,Y,setBizTitle)
 {
 RVKScene *currentPage = page;
 NSLog(@"====>%@",page);
 callback(@{});
 }
 ```
 */

@class RVKBridgeMethodInfo;

NS_ASSUME_NONNULL_BEGIN

/************************************** bridge **************************************/
#define RVK_CONCAT2(A, B) A ## B
#define RVK_CONCAT(A, B) RVK_CONCAT2(A, B)

#if !defined RVK_DYNAMIC
#if __has_attribute(objc_dynamic)
#define RVK_DYNAMIC __attribute__((objc_dynamic))
#else
#define RVK_DYNAMIC
#endif
#endif

#define _RVK_MAP_JSAPI(js_name, method,...) \
+ (void)RVK_CONCAT(__RVK_export__, RVK_CONCAT(js_name, RVK_CONCAT(__LINE__, __COUNTER__))){ \
RVKBridgeMethodInfoManager *manager =  [RVKBridgeMethodInfoManager defaultMethodInfoManager];\
RVKBridgeMethodInfo *info = [[RVKBridgeMethodInfo alloc] init];\
info.jsName = @#js_name;\
info.objectMethodName = @#method;\
info.objectClsName = NSStringFromClass([self class]);\
info.originOverrideAndAlias =@#__VA_ARGS__;\
[manager addMethodInfo:info];\
}

#define RVK_MAP_JSAPI_INFO(js_name, method, args...) \
_RVK_MAP_JSAPI(js_name,method,args) \
- (void)method originParam:(NSDictionary *)originParam page:(RVKScene *)page callback:(RVKJsApiResponseCallbackBlock)callback RVK_DYNAMIC

#define RVK_DEFINE_JSAPI(js_name, method, args...) \
RVK_MAP_JSAPI_INFO(js_name, method,args)

#define RVK_DEFINE_RVKBRIDGEEXTENSION(name) \
@protocol NXEvent4##name <NSObject>\
@end\
@interface name : RVKExtension <RVKBridgeExtensionProtocol,NXEvent4##name>\
@end\


#define RVK_DEFINE_BRIDGEEXTENSION(name) \
@protocol NXEvent4##name <NSObject>\
@end\
@interface name : RVKBridgeExtension <NXEvent4##name>\
@end\

@protocol RVKBridgeExtensionProtocol <NSObject>
@end

RVK_DEFINE_RVKBRIDGEEXTENSION(RVKBridgeExtension)

NS_ASSUME_NONNULL_END
