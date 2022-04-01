//
//  AlibcSimpleWebViewController.h
//  AlibcTradeContainer
//
//  Created by zhongweitao on 2020/4/11.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcSimpleWebViewController : UIViewController<WKNavigationDelegate>

@property (strong, nonatomic)WKWebView *webView;

@property (nonatomic, copy) NSString *customTitle;

@end

NS_ASSUME_NONNULL_END
