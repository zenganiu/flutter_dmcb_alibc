//
//  RVANebulaViewProtocol.h
//  AriverApp
//
//  Created by chenwenhong on 15/12/28.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/RVKWebView.h>

@class RVAContentViewPageProfile;

NS_ASSUME_NONNULL_BEGIN

@protocol RVAContentViewPageDelegate;

// 默认继承自WKWebView不需要实现，也不要实现
@protocol RVAContentViewProtocol <RVKContentViewProtocol>

@property(nonatomic) UIViewAutoresizing                     autoresizingMask;
@property(nonatomic, copy) NSString                         *channelId;
@property(nonatomic, copy) NSString                         *nbl_id;
@property(nonatomic, weak) id<RVAContentViewPageDelegate>    pageDelegate;

- (void)contentViewDidLoad;

- (void)contentViewDidPause;

- (void)contentViewDidResume;

- (void)contentViewDidClose;

@end

@protocol RVAWKLifeCycleDelegate <NSObject>
//frame
- (void)rva_setFrame:(CGRect)frame;
- (void)rva_willMoveToSuperview:(UIView *)view;

//scroll
- (void)rva_scrollViewDidScroll:(UIScrollView *)scrollView;


//NavigationDelegate
- (id<WKNavigationDelegate>)rvaAssginNavigationDelegate;
- (void)setRvaAssginNavigationDelegate:(id<WKNavigationDelegate>)delegate;
@optional

- (void)rva_webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler;

/*! @abstract Decides whether to allow or cancel a navigation after its
 response is known.
 @param webView The web view invoking the delegate method.
 @param navigationResponse Descriptive information about the navigation
 response.
 @param decisionHandler The decision handler to call to allow or cancel the
 navigation. The argument is one of the constants of the enumerated type WKNavigationResponsePolicy.
 @discussion If you do not implement this method, the web view will allow the response, if the web view can show it.
 */
- (void)rva_webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler;

/*! @abstract Invoked when a main frame navigation starts.
 @param webView The web view invoking the delegate method.
 @param navigation The navigation.
 */
- (void)rva_webView:(WKWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation;

/*! @abstract Invoked when a server redirect is received for the main
 frame.
 @param webView The web view invoking the delegate method.
 @param navigation The navigation.
 */
- (void)rva_webView:(WKWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(null_unspecified WKNavigation *)navigation;

/*! @abstract Invoked when an error occurs while starting to load data for
 the main frame.
 @param webView The web view invoking the delegate method.
 @param navigation The navigation.
 @param error The error that occurred.
 */
- (void)rva_webView:(WKWebView *)webView didFailProvisionalNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;

/*! @abstract Invoked when content starts arriving for the main frame.
 @param webView The web view invoking the delegate method.
 @param navigation The navigation.
 */
- (void)rva_webView:(WKWebView *)webView didCommitNavigation:(null_unspecified WKNavigation *)navigation;

/*! @abstract Invoked when a main frame navigation completes.
 @param webView The web view invoking the delegate method.
 @param navigation The navigation.
 */
- (void)rva_webView:(WKWebView *)webView didFinishNavigation:(null_unspecified WKNavigation *)navigation;

/*! @abstract Invoked when an error occurs during a committed main frame
 navigation.
 @param webView The web view invoking the delegate method.
 @param navigation The navigation.
 @param error The error that occurred.
 */
- (void)rva_webView:(WKWebView *)webView didFailNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;

/*! @abstract Invoked when the web view needs to respond to an authentication challenge.
 @param webView The web view that received the authentication challenge.
 @param challenge The authentication challenge.
 @param completionHandler The completion handler you must invoke to respond to the challenge. The
 disposition argument is one of the constants of the enumerated type
 NSURLSessionAuthChallengeDisposition. When disposition is NSURLSessionAuthChallengeUseCredential,
 the credential argument is the credential to use, or nil to indicate continuing without a
 credential.
 @discussion If you do not implement this method, the web view will respond to the authentication challenge with the NSURLSessionAuthChallengeRejectProtectionSpace disposition.
 */
- (void)rva_webView:(WKWebView *)webView didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;

/*! @abstract Invoked when the web view's web content process is terminated.
 @param webView The web view whose underlying web content process was terminated.
 */
- (void)rva_webViewWebContentProcessDidTerminate:(WKWebView *)webView API_AVAILABLE(macosx(10.11), ios(9.0));

@end


@protocol RVAWKNavigationDelegate <NSObject>


@end


@protocol RVAContentViewPageDelegate <NSObject>

- (void)contentViewPageStart:(RVAContentViewPageProfile *)page;

- (void)contentViewPageComplete:(RVAContentViewPageProfile *)page;

- (void)contentViewPagePaused:(RVAContentViewPageProfile *)page;

- (void)contentViewPageResume:(RVAContentViewPageProfile *)page;

- (void)contentViewPageEnd:(RVAContentViewPageProfile *)page;

@end

NS_ASSUME_NONNULL_END

