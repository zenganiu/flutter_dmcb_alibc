//
//  TRVScanProtocol.h
//  API
//
//  Created by xuyouyang on 2019/5/30.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TriverAppContainer/TRVAppPageViewController.h>
#import <AriverApp/RVKSession+RVA.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TRVScanProtocolScanType) {
	TRVScanProtocolScanTypeQR,
	TRVScanProtocolScanTypeBAR
};

typedef NS_ENUM(NSInteger, TRVScanProtocolErrorCode) {
	TRVScanProtocolErrorCodeCancel = 10,
	TRVScanProtocolErrorCodeFail = 11,
	TRVScanProtocolErrorCodeNone = 0
};

typedef void(^TRVScanViewControllerResultBlock)(NSString * _Nullable data, TRVScanProtocolErrorCode errorCode);

@protocol TRVScanViewControllerProtocol <NSObject>

@required
// 扫码返回结果回调
@property (nonatomic, copy) TRVScanViewControllerResultBlock resultBlock;

@end

@protocol TRVScanProtocol <NSObject>

@required
/**
 获取一个扫码视图
 
 @param type           扫码类型
 @param appId          当前小程序Id
 @param currentSession 当前小程序容器
 @return 继承于 TRVAppPageViewController 且实现了 TRVScanViewControllerProtocol 协议的 VC
 */
- (TRVAppPageViewController<TRVScanViewControllerProtocol> *)createScanVCWithType:(TRVScanProtocolScanType)type appId:(NSString *)appId session:(RVKSession *)currentSession;

@end

NS_ASSUME_NONNULL_END
