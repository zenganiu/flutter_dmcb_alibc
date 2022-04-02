//
//  RVKUtils.h
//  NebulaPoseidon
//
//  Created by theone on 2017/9/11.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVKWebView.h"

//********************** Encode ***********************//
NSStringEncoding RVKEncodingFromAcceptCharset(NSString *acceptCharset, NSString *documentCharset);
BOOL RVKIsNonByteBasedEncoding(NSStringEncoding currentEncodeing);
BOOL RVKIsUTF7Encoding(NSStringEncoding currentEncodeing);
NSStringEncoding RVKEncodingForFormSubmission(NSStringEncoding currentEncodeing);
NSString* RVKURLEncodeString(NSString *string);
NSDictionary *RVKURLGetQuery(NSString *queryString);
NSString *RVKURLEncodeData(NSData *data);
NSURL *RVKURLWithFixedString(NSString *URLString);
NSString *RVKGetCookiesStrWithUrlAndCookies(NSURL *url, NSArray *cookies);
NSArray *RVKGetFilterCookies(NSArray *cookies);
BOOL RVKShouldUseNewMethodSyncWKCookies();
NSString *RVKMD5(NSString *string);
NSString *RVKGetTokenWithContentView(RVKContentView *view);
NSString *RVKReplaceString(NSString *jsStr,NSString *targetStr, NSString *replaceStr);
NSString *RVKReplaceBridgeWithContentView(RVKContentView *view,NSString *js);
NSString *RVKString(id obj);
void RVKSetWKWebViewNavDelegate(WKWebView *webview, id<WKNavigationDelegate> delegate);
NSString *RVKGetPluginIdWithParams(NSDictionary *);
unsigned long long RVKColorNumberWithHexString(NSString *hexStr);
