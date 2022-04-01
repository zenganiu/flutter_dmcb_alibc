//
//  TRVAppManager.h
//  Triver
//
//  Created by zhongweitao on 2019/4/2.
//

#import <Foundation/Foundation.h>
#import "TRVAppContainer.h"

@interface TRVAppManager : NSObject

+ (TRVAppManager *)sharedInstance;

/**
 小程序SDK初始化
 */
- (void)setup;

/// @brief 所有能力注册后的初始化，eg:Orange配置
- (void)setupAfterRegisterHandler;

/// @brief 清理小程序缓存（客户端清理缓存调用）
- (void)clearMiniAppCache;

/**
 打开小程序
 
 @param urlStr 小程序URL
 @return 小程序根ViewController
 */
- (UIViewController *)openAppWithUrl:(NSString *)urlStr;


/**
 打开小程序
 
 @param urlStr  小程序URL
 @param error   创建根ViewController发生的Error，Code码参考 “打开小程序ErrorCode”
 @return        小程序根ViewController
 */
- (UIViewController *)openAppWithUrl:(NSString *)urlStr error:(NSError **)error;
- (UIViewController *)openAppWithUrl:(NSString *)urlStr extraParams:(NSDictionary *)extraParams error:(NSError **)error;

#pragma mark - embed
/**
 通过直接获取小程序页面的方式打开小程序
 
 @param urlStr  小程序URL
 @param completion   返回小程序页面ViewController
 */
- (void)openEmbedAppWithUrl:(NSString *)urlStr completion:(TRVOpenEmbedAppCompletion)completion;

/// @brief app 不在最前
- (void)appPauseForPage:(TRVAppPageViewController *)appPage;

/// @brief app 恢复到最前
- (void)appResumeForPage:(TRVAppPageViewController *)appPage;

#pragma mark - HideLoading
- (TRVAppContainer *)appContainerForHideLoading:(NSString *)url error:(NSError **)error;

#pragma mark - app container

/// @brief 小程序实例是否被打开
- (BOOL)openedForAppContainer:(TRVAppContainer *)appContainer;

/// @brief 关闭小程序
- (void)closeAppContainer:(TRVAppContainer *)appContainer;
- (void)closeAppContainer:(TRVAppContainer *)appContainer completion:(void (^)(void))completion;

@end
