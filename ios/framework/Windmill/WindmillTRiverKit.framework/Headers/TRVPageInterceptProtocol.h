//
//  TRVPageInterceptProtocol.h
//  Triver
//
//  Created by zhongweitao on 2019/7/23.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol TRVPageInterceptProtocol <NSObject>

/// @brief 切换tab拦截
- (BOOL)forbidChangeToTabForUrl:(NSString *)url sourceVC:(UIViewController *)sourceVC;

/// @brief pushWindow拦截
- (BOOL)forbidPushWindowForUrl:(NSString *)url sourceVC:(UIViewController *)sourceVC;

/// @brief 直投二级页返回首页拦截
- (BOOL)forbidBackToHomeForUrl:(NSString *)url sourceVC:(UIViewController *)sourceVC;

/// @brief 小程序启动失败
- (BOOL)downgradeForAppId:(NSString *)appId appUrl:(NSString *)appUrl sourceVC:(UIViewController *)sourceVC;

@end
