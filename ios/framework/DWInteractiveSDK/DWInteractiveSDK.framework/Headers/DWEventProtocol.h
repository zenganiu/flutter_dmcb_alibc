//
//  DWEventProtocol.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/5/12.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#ifndef DWEventProtocol_h
#define DWEventProtocol_h

#import <DWInteractiveSDK/DWComponent.h>
@protocol DWEventProtocol <NSObject>

- (void)openUrl:(NSString*)url;



//addCart 接口使用
- (void)pullLoginWithCompletionHandler:(void(^)())completion cancelHandler:(void(^)())cancel;
- (void)addCart:(UIView*)SKUInView goodsID:(NSString*)goodsID SKUCancleBlock:(void(^)())SKUCancleBlock;
- (void)closeAddCartView;

//DWInstanceModule openWebViewLayer时使用
- (UIViewController*)getCurrentSelectedViewController;
- (void)openWebView:(NSDictionary*)data VC:(UIViewController*)VC component:(DWComponent*)component;
- (void)closeWebView:(UIView *)webView;

@end

#endif /* DWEventProtocol_h */
