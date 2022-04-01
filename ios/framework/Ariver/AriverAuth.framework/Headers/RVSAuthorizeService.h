//
//  RVSAuthorizeService.h
//  AriverDemo
//
//  Created by theone on 2019/4/12.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>

@class openauthWalletAuthSkipResultPB;

NS_ASSUME_NONNULL_BEGIN
@protocol RVSAuthorizeDialog <NSObject>
@required
- (void)addButton:(NSString *)buttonTitle actionBlock:(void(^)())actionBlock;
- (void)show;
@end

@protocol RVSDialogDelegate <NSObject>
@required
- (void)dialogView:(UIView *)dialogView clickedButtonAtIndex:(NSInteger)buttonIndex;
@end

@protocol RVSAuthView <NSObject>
@property(nonatomic, assign) BOOL isShowing;
- (void)dismiss;
- (void)setActionButtonDidClickBlock:(void (^)(void))block;
- (void)setCloseButtonDidDissmissBlock:(void (^)(void))block;
@end

@protocol RVSAuthorizeService <RVAServiceProtocol>

@required
/**
 带按钮标题的初始化方法。
 注意 弹框视觉要求，当title和message中一个不存在时，必须设置为title，但不推荐只传title或message的情况，建议所有弹窗都带title和message
 
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象
 @param buttonTitle 按钮标题列表
 @return AUNoticeDialog 实例
 */
- (id<RVSAuthorizeDialog>)getDialogWithTitle:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<RVSDialogDelegate>)delegate
                 cancelTitle:(NSString *)cancelTitle
                 confimTitle:(NSString *)confimTitle;

- (id<RVSAuthorizeDialog>)getDialogWithTitle:(NSString *)title
                 message:(NSString *)message
                 appName:(NSString *)app
                    logo:(NSString *)logo
                delegate:(id<RVSDialogDelegate>)delegate
             cancelTitle:(NSString *)cancelTitle
             confimTitle:(NSString *)confimTitle;

//必须实现需要用来显示界面
- (id<RVSAuthView>)showInSuperview:(UIView *)superview
                             title:(NSString *)title
                              data:(NSDictionary *)data;

@optional
- (BOOL)ta_use_native_share_config;
- (NSArray *)authorizationWhiteList;
//曝光埋点
- (void)exposureLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view;
- (void)clickedLogWithSpmId:(NSString *)spmId bizCode:(NSString *)bizCode extParams4:(nullable NSDictionary *)param4 view:(NSObject *)view ;

- (UIViewController *)currentVisibleViewController;

- (NSArray *)ta_appx_rpc_white_cfg;
- (NSDictionary *)rpcAppKeyConfig;
- (void)dispatchRpcEventWithSession:(RVKSession *)session responseHeader:(NSDictionary *)responseHeader;

//支付宝必须实现
- (BOOL)isMiniServer;
- (NSString *)parentIdWithMiniServer;
- (BOOL)shouldUseNewGetAuthCode;

// 当前VC是否可见，退出保活状态会出现不可见情况
- (BOOL)isCurrentVCVisible:(UIViewController *)vc;

- (void)authWithH5ModeParams:(openauthWalletAuthSkipResultPB *)params
                 extraParams:(NSDictionary *)extra // 需要透传更多的参数多业务实现方，两端对齐
                     session:(RVKSession *)session
              viewController:(UIViewController *)viewController
                    callback:(void(^)(id data))callback;

- (id)currentApplication;
- (UINavigationController *)currentNavigationController;
- (BOOL)didSupportNewGetAuthCode;
- (void)prepareForNewAuthCode:(RVKContext *)context
                      session:(RVKSession *)session
                     callback:(void (^)(id responseData))callback;
- (void)showErrorViewWithParams:(NSDictionary *)params;
- (NSDictionary *)getTracerInfoFromScene:(RVKScene *)scene;
//当前地域标识，作为多语言判断标记
- (NSString *)currentRegion;
- (NSString *)regionTypeMO;//澳门版静态地域标识

@end

NS_ASSUME_NONNULL_END
