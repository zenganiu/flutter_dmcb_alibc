//
//  RVKDefines.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#ifndef RVKDefines_h
#define RVKDefines_h


#define NKXBridgeExtensionSubFixSel  @" originParam:(NSDictionary *)originParam page:(RVKScene *)page callback:(RVKJsApiResponseCallbackBlock)callback"



//********************** NKXRegisterMod ***********************//
#define kRVKConfigKey_PluginRuntime             @"PluginRuntime"
#define kRVKConfigKey_Plugins                   @"Plugins"
#define kRVKConfigKey_PluginName                @"name"
#define kRVKConfigKey_PluginEvents              @"events"
#define kRVKConfigKey_PluginEvent               @"name"
#define kRVKConfigKey_PluginUseCapture          @"useCapture"

#define kRVKConfigKey_JsApiRuntime              @"JsApiRuntime"
#define kRVKConfigKey_JsApis                    @"JsApis"
#define kRVKConfigKey_JsApiName                 @"name"
#define kRVKConfigKey_JsApi                     @"jsApi"
#define kRVKConfigKey_JsApiAlias                @"alias"
#define kRVKConfigKey_CheckParams               @"checkParams"
#define kRVKConfigKey_IsPrivate                 @"isPrivate"
#define kRVKConfigKey_Scope                     @"scope"
#define kRVKConfigKey_Level                     @"level"

#define kRVKConfigKey_ComponentRuntime          @"ComponentRuntime"
#define kRVKConfigKey_Components                @"Components"
#define kRVKConfigKey_ComponentName             @"component"

#define kRVKConfigKey_ExtensionRuntimeKey       @"ExtensionRuntime"
#define kRVKConfigKey_Extensions                @"Extensions"


#define NKXConfigurationMod()\
+ (void)load{\
[[RVKConfigManager sharedInstance]  registerConfigMod:NSStringFromClass(self)];\
}\


/**
 注册一个JSAPI,可配置如：
 
 RVK_Register_JSAPI(toast, JSApi4Toast, mytoast, Y, scene, high)
 
 @param name plain jsapi名称
 @param cls  plain  jsapi对应的实现类
 @param alias plain jsapi别名(可选，不需要就写-)
 @param isPrivate plain 这个jsapi是否支持重写(可选(Y/N)，不需要就写-)
 @param scope plain jsapi作用域(可选(service,session,scene,page)，不需要就写-)
 @param level plain jsapi权限等级(可选(high,abovemedium,medium,low,none)，不需要就写-，默认权限放开)
 @return void
 */
#define RVK_Register_JSAPI(name, cls , alias , isPrivate, scope, level)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kRVKConfigKey_JsApi];\
[name##dic setValue:@#cls forKey:kRVKConfigKey_JsApiName];\
if(![@#alias isEqualToString:@"-"]){\
[name##dic setValue:@#alias forKey:kRVKConfigKey_JsApiAlias];\
}\
if([@#isPrivate isEqualToString:@"Y"]||[@#isPrivate isEqualToString:@"N"]){\
[name##dic setValue:@#isPrivate forKey:kRVKConfigKey_IsPrivate];\
}else{\
[name##dic setValue:@"Y" forKey:kRVKConfigKey_IsPrivate];\
}\
if([@#scope isEqualToString:@"service"]||[@#scope isEqualToString:@"session"] || [@#scope isEqualToString:@"scene"] || [@#scope isEqualToString:@"page"]){\
[name##dic setValue:@#scope forKey:kRVKConfigKey_Scope];\
}\
if(![@#level isEqualToString:@"-"]){\
[name##dic setValue:@#level forKey:kRVKConfigKey_Level];\
}\
[self registerJsapiWithConfig:name##dic];\


/**
 注册一个插件,可配置如：
 
 RVK_Register_Plugin(Plugin4TabBar,scene)
 
 @param name plain 插件的实现类名称
 @param scope plain 插件的作用域(可选(service,session,scene,page)，不需要就写-)
 */
#define RVK_Register_Plugin(name, scope)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kRVKConfigKey_PluginName];\
if([@#scope isEqualToString:@"service"]||[@#scope isEqualToString:@"session"] || [@#scope isEqualToString:@"scene"] || [@#scope isEqualToString:@"page"] || [@#scope isEqualToString:@"proxy"]){\
[name##dic setValue:@#scope forKey:kRVKConfigKey_Scope];\
}\
[self registerPluginWithConfig:name##dic];\


/**
 注册一个Component,可配置如：
 
 RVK_Register_Component(NBComponent4Canvas,canvas)
 
 @param name plain Component的实现类名称
 @param component plain 前端使用的组件名称
 */
#define RVK_Register_Component(name, component)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kRVKConfigKey_PluginName];\
[name##dic setValue:@#component forKey:kRVKConfigKey_ComponentName];\
[self registerComponentWithConfig:name##dic];\

/**
 注册一个扩展,可配置如：
 
 RVK_Register_Extension(NXExtension4Tab)
 
 @param name plain Extension的实现类名称
 */
#define RVK_Register_Extension(name)\
NSMutableDictionary *name##dic = [NSMutableDictionary dictionary];\
[name##dic setValue:@#name forKey:kRVKConfigKey_PluginName];\
[self registerExtensionWithConfig:name##dic];\



////**********************Message Handler***********************//
//
//#define KRVKBRIDGEMESSAGEHANDLER        @"PSDBRIDGEMESSAGEHANDLER"
//#define KRVKBRIDGEDOMREADY              @"PSDBRIDGEDOMREADY"
//#define KRVKXMLHTTPREQUESTMESSAGE       @"PSDXMLHTTPREQUESTMESSAGE"
//#define KRVKXNEBULAXMLHTTPREQUEST       @"X-NEBULAXMLHTTPREQUEST"
//#define KRVKXMSGID                      @"msgId"
//#define KRVKXMSGCOOKIE                  @"msgCookie"
//#define KRVKXMSGMAINURL                 @"msgMainUrl"
//#define KRVKXMSGVAL                     @"val"
//#define KRVKXMSGTYPE                    @"type"
//#define KRVKXMSGENCTYPE                 @"FormEnctype"
//#define KRVKXMSGACCEPTCHARSET           @"AcceptCharset"
//#define KRVKXMSGDOCUMENTCHARSET         @"DocumentCharset"
//#define KRVKXMSGISSTREAM                @"IsStream"
//#define KRVKXMSGNAME                    @"name"
//#define KRVKXMSGVALUE                   @"value"
//#define KRVKFORMENCTYPEOFURLENCODE      @"application/x-www-form-urlencoded"
//#define KRVKFORMENCTYPEOFPLAIN          @"text/plain"
//#define kRVKSceneInjectRequest          @"kPSDSceneInjectRequest"
//#define KRVKXMSGTK                      @"msgKt"
//#define KRVKXMSGREQUESTURL              @"msgRequestUrl"
//
////********************** other ***********************//
////可以通过runtime的方式获得当前request是否是主文档的请求
//#define kRVKWEBVIEWISMAINFRAMEREQUEST   @"kPSDWEBVIEWISMAINFRAMEREQUEST"
//
//
//#define KRVKWKFakePersistentCookie              @"KPSDWKFAKEPERSISTENTCOOKIE"
//#define KRVKWKSharedCookies                     @"KPSDWKSharedCookies"
//#define KRVKDocumentHref                        @"document.location.href"
//#define KRVKMainUrlFallback                     @"KPSDMainUrlFallback"
//#define KRVKUrlFromHttpRequest                  @"KPSDUrlFromHttpRequest"

#endif /* RVKDefines_h */
