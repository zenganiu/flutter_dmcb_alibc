//
//  RVTJSCManager.h
//  AriverRuntime
//
//  Created by theone on 2017/12/18.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>

@class RVTJSCBridge;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, RVTJSCWORKERSTATE) {
	RVTJSCWORKERSTATEUNINSTAL = 1 << 0,
	RVTJSCWORKERSTATEINSTALLING = 1 << 1,
	RVTJSCWORKERSTATEINSTALED = 1 << 2,
};

@interface RVTJSCWorkerInfo : NSObject
@property(nonatomic, assign, readonly)  RVTJSCWORKERSTATE state;
@property(nonatomic, copy, readonly)    NSString         *workerUrl;
@end

@interface RVTJSCManager : NSObject

@property(nonatomic, readonly, assign)      BOOL  hasStartDebuger;
@property(nonatomic, weak)                  RVTJSCBridge *bridge;
@property(nonatomic, strong)                NSMutableDictionary<NSString *,RVTJSCWorkerInfo *> *workers;
- (instancetype)initWithSession:(RVKSession *)session;
- (void)addWorker:(NSString *)url;
- (BOOL)isWorkerExist:(NSString *)url;
- (BOOL)isWorkerInstalled:(NSString *)url;
- (BOOL)isWorkerInstalling:(NSString *)url;
- (void)setWorkderState:(NSString *)url state:(RVTJSCWORKERSTATE)state;
- (void)loadBaseJS;

@end

NS_ASSUME_NONNULL_END
