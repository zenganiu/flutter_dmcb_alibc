//
//  RVKWebView.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@protocol RVKContentViewDelegate;
@protocol RVKExternalWebViewDelegate;
@class RVKContentViewConfig;
@protocol RVKViewControllerProtocol;
@protocol RVKContentViewNavigationDelegate;
@protocol RVKContentViewUIDelegate;

//webView代理接口
@protocol RVKExternalWebViewDelegate <NSObject>

@end

@protocol RVKContentViewProtocol <NSObject>
NS_ASSUME_NONNULL_BEGIN
@optional
@property(nonatomic, weak) id<RVKExternalWebViewDelegate>           rvkExternalWebViewDelegate;
@property(nonatomic, weak) id<RVKViewControllerProtocol>            rvkViewController;
@property(nonatomic, weak) id<RVKContentViewDelegate>               rvkContentViewDelegate;
@property(nonatomic, weak) id<RVKContentViewNavigationDelegate>     rvkContentViewNavigationDelegate;
@property(nonatomic, weak) id<RVKContentViewUIDelegate>             rvkContentViewUIDelegate;

@property (nonatomic, readonly, copy) WKWebViewConfiguration *configuration;

- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType textEncodingName:(NSString *)textEncodingName baseURL:(NSURL *)baseURL;

//@required
@property(nonatomic, readonly, weak) UIView                         *view; // 获取UIView对象
@property(nullable, nonatomic, readonly) UIWindow                   *window;
@property(nonatomic, readonly, nullable, strong) UIScrollView       *scrollView; // only h5
@property(nonatomic, readonly, nullable, strong) NSURLRequest       *request;
@property(nonatomic, readonly) BOOL                                 isLoading;
@property(nonatomic, readonly) BOOL                                 canGoBack;
@property(nonatomic, weak) id                                       delegate;
@property(nonatomic, nullable, copy) NSString                       *channelId;
@property(nonatomic) BOOL                                           scalesPageToFit;
@property(nonatomic) BOOL                                           detectsPhoneNumbers;
@property(nonatomic) UIDataDetectorTypes                            dataDetectorTypes;
@property(nonatomic) BOOL                                           allowsInlineMediaPlayback; // iPhone Safari defaults to NO. iPad Safari defaults to YES
@property (nullable, nonatomic, readonly, copy) NSURL               *URL;//for same with wkwebview
- (void)evaluateJavaScript:(nullable NSString *)js completionHandler:(nullable void (^)(id result, NSError *error))completionHandler;

- (void)loadRequest:(nullable NSURLRequest *)request;
- (void)loadHTMLString:(nullable NSString *)string baseURL:(nullable NSURL *)baseURL;
- (void)reload;
- (void)stopLoading;

- (void)goBack;
- (void)goForward;
NS_ASSUME_NONNULL_END
@end

// 对外接口参数，为了方便调用
@interface RVKContentView : UIView <RVKContentViewProtocol>

@end

//webView基类
@interface RVKWebView : WKWebView <RVKContentViewProtocol>

@end

// 配置
@interface RVKContentViewConfig : WKWebViewConfiguration

@end


//webView代理接口
@protocol RVKContentViewDelegate <NSObject>
@optional
- (BOOL)contentView:(nullable RVKContentView *)contentView resizeFrame:(CGRect)frame;

@end

@protocol RVKContentViewPrepareProtocol <NSObject>

@optional
+ (RVKContentView *_Nullable)fetchPrepareContentViewWithFrame:(CGRect)frame configuration:(NSDictionary *_Nonnull)configuration;
+ (void)prepareContentView;

@end


