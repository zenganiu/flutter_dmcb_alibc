//
//  RVKExtensionPoint.h
//  NebulaKernel
//
//  Created by theone on 2018/8/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKExtension;

typedef void(^RVKStopPropagationCallback)(RVKExtension *extension);
typedef void(^RVKPreventDefaultCallback)(RVKExtension *extension);
typedef void(^RVKProgressCallback)(RVKExtension *extension, id result);
typedef void(^RVKCompleteCallback)(id result);


@protocol RVKExtensionPointLifeCycleProtocol <NSObject>

@required
@property(nonatomic) BOOL isPreventDefault;                       // 扩展点是否阻止默认行为
@property(nonatomic) BOOL isStopPropagation;                      // 扩展点是否停止传播
@property(nonatomic) RVKStopPropagationCallback  stopPropagationCallback;    // 阻止传播回调
@property(nonatomic) RVKPreventDefaultCallback  preventDefaultCallback;     // 阻止默认处理回调
@property(nonatomic) RVKProgressCallback  processCallback;              // 处理过程中回调
@property(nonatomic) RVKCompleteCallback  completeCallback;             // 完成调用回调
@end


@interface RVKExtensionPointLifeCycle : NSObject <RVKExtensionPointLifeCycleProtocol>
@property(nonatomic) BOOL isPreventDefault;                       // 扩展点是否阻止默认行为
@property(nonatomic) BOOL isStopPropagation;                      // 扩展点是否停止传播
@property(nonatomic) RVKStopPropagationCallback  stopPropagationCallback;    // 阻止传播回调
@property(nonatomic) RVKPreventDefaultCallback  preventDefaultCallback;     // 阻止默认处理回调
@property(nonatomic) RVKProgressCallback        processCallback;              // 处理过程中回调
@property(nonatomic) RVKCompleteCallback  completeCallback;             // 完成调用回调

- (instancetype)initWithStopPropagationCallback:(RVKStopPropagationCallback)stopPropagationCallback
                         preventDefaultCallback:(RVKPreventDefaultCallback)preventDefaultCallback
                                processCallback:(RVKProgressCallback)processCallback
                               completeCallback:(RVKCompleteCallback)completeCallback;
@property(nonatomic) Protocol *ponit;

// convenient for setting by chain
- (instancetype)onStopPropagation:(RVKStopPropagationCallback)callback;
- (instancetype)onPreventDefault:(RVKPreventDefaultCallback)callback;
- (instancetype)onProcess:(RVKProgressCallback)callback;
- (instancetype)onComplete:(RVKCompleteCallback)callback;

@end
