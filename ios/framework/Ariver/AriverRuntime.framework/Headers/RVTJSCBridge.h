//
//  RVTJSCBridge.h
//  AriverRuntime
//
//  Created by theone on 2017/12/18.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVTDefine.h"
#import <AriverKernel/AriverKernel.h>

@class RVTJSCExecutor;
@class RVTJSCTiming;

NS_ASSUME_NONNULL_BEGIN

@interface RVTJSCBridge : RVKJsBridge

@property(nonatomic, copy, nullable)   NSString       *jsc_workerId;
@property(nonatomic, weak, nullable)   RVTJSCExecutor  *javaScriptExecutor;
@property(nonatomic, weak, readonly)   RVKSession      *rvksession;

- (instancetype _Nonnull)initWithSession:(nonnull RVKSession *)session
							 isDebugMode:(BOOL)isDebugMode;

- (void)executeAsyncJavaScript:(nonnull NSString *)javaScript
					 sourceURL:(nullable NSURL *)sourceURL
					onComplete:(nullable RVTJavaScriptCallback)onComplete;

- (void)executeAsyncJavaScript:(nonnull NSString *)javaScript
                     sourceURL:(nullable NSURL *)sourceURL
                    onComplete:(nullable RVTJavaScriptCallback)onComplete
                     contextId:(NSString *)contextId;

- (void)executeJavaScript:(nonnull NSString *)javaScript
				sourceURL:(nullable NSURL *)sourceURL
			   onComplete:(nullable RVTJavaScriptCallback)onComplete;

- (void)doFlushMessageQueue:(nullable id)buffer;

- (void)doFlushMessageQueue:(nullable NSDictionary *)message
				   callBack:(nullable RVKJsApiResponseCallbackBlock)callback;

- (nullable id)doSyncFlushMessageQueue:(nullable NSDictionary *)message;

- (void)sendMessage:(nonnull NSString *)messageName
			   data:(nullable id)data
   responseCallback:(nullable RVKJsApiResponseCallbackBlock)responseCallback;

//只向worker发送js事件的方法，调用入参和callhandler方法保持一致。支持nsdata->arraybuffer
- (void)sendJSEvent:(nonnull NSString *)eventName
               data:(nullable NSDictionary *)data
           callback:(nullable RVKJsApiResponseCallbackBlock)callback;

//timer
- (void)addUpdateObserver:(nonnull RVTJSCTiming *)timer;
- (void)createTimer:(nonnull NSNumber *)callbackID
		   duration:(NSTimeInterval)jsDuration
   jsSchedulingTime:(nonnull NSDate *)jsSchedulingTime
            repeats:(BOOL)repeats
          contextId:(NSString *)contextId;

- (void)deleteTimer:(nonnull NSNumber *)timerID
          contextId:(NSString *)contextId;

- (void)invalidate;
- (void)setUp;

//importjs
- (void)importJSWithUrl:(nullable NSString *)url callback:(nullable RVTImportJsCallback)callback;

@end

NS_ASSUME_NONNULL_END
