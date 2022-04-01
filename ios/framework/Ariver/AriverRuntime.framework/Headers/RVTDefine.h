//
//  RVTDefine.h
//  AriverRuntime
//
//  Created by theone on 2017/12/18.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVTDefine_h
#define RVTDefine_h

typedef void (^RVTJavaScriptCompleteBlock)(NSError *_Nullable error);
typedef void (^RVTJavaScriptCallback)(id _Nullable json, NSError *_Nullable error);
typedef void (^RVTDownloadCallback)(NSDictionary *_Nullable result);
typedef void (^RVTImportJsCallback)(NSDictionary *_Nullable dic, NSError *_Nullable error);

#define kRVTFROMH5JSC @"FROMH5JSC"
#define kRVTEnableDSL @"enableDSL"

//*******************************ExpandPropertyKeys***************************//
#define kExpandPropertyKey_PrefetchViewId       @"kExpandPropertyKey_PrefetchViewId"
#define kExpandPropertyKey_ComponentManager     @"kExpandPropertyKey_ComponentManager"
#define kExpandPropertyKey_JSC                  @"kExpandPropertyKey_JSC"
#define kExpandPropertyKey_MultiJSC             @"kExpandPropertyKey_MultiJSC"
#define kExpandPropertyKey_ComponentManager     @"kExpandPropertyKey_ComponentManager"
#define kExpandPropertyKey_JSCViewId            @"kExpandPropertyKey_JSCViewId"
#define kExpandPropertyKey_JSCPageId            @"kExpandPropertyKey_JSCPageId"
#define kExpandPropertyKey_JSCDebugger          @"kExpandPropertyKey_JSCDebugger"

//*******************************Event***************************//
#define kRVTEvent_Seesion_Worker_Load_JS         @"session.worker.load.js" //woker启动过程中加载其他js的扩展点
#define kRVTEvent_Session_Worker_Before_Load      @"session.worker.before.load" //加载worker之前对worker进行修改的时机，用于小程序调试
#define kRVTEvent_Session_Isolate_Context_Load   @"session.worker.isolate.context.load" //isolateContext加载前的注入时机
#define kRVTEvent_Session_Worker_Jsapi_Callasync @"session.worker.jsapi.callasync" //调试模式下jsapi调用事件
#define kRVTEvent_Seesion_Worker_Create_After    @"session.worker.create.after" //woker启动过程中加载其他js的扩展点
#define kRVTEvent_Scene_WK_LayerTreeComplete     @"scene.wk.ingore" //WKWebViewLayout布局完成 layertreecommitcomplete


#endif /* RVTDefine_h */
