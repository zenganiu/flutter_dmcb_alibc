//
//  RVKURLProtocolProcessor.h
//  Poseidon
//
//  Created by chenwenhong on 14-10-15.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVKWebViewURLProtocol.h"

//URLProtocol处理，以便插入监控等
@interface RVKURLProtocolProcessor : NSObject<RVKWebViewURLProtocolDelegate>

// for diagnose purpose
@property(nonatomic, copy) NSString                *parentTraceId;
@property(nonatomic, copy) NSString                *traceId;

@end

@protocol RVKURLProtocolProcessorDelegate <NSObject>

@optional
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor willStartLoading:(NSURLRequest *)request channelId:(NSString *)channelId;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor startLoading:(NSURLRequest *)request;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor wasRedirectedToRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirectResponse receiveData:(NSData *)receiveData;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor didReceiveResponse:(NSURLResponse *)response;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor didLoadData:(NSData *)data;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor didFinishLoading:(NSData *)receiveData receiveDataLength:(NSUInteger)receiveDataLength protocol:(NSURLProtocol *)protocol;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor didFailWithError:(NSError *)error protocol:(NSURLProtocol *)protocol;
- (void)RVKURLProtocolProcessor:(RVKURLProtocolProcessor *)processor didCancel:(NSError *)error protocol:(NSURLProtocol *)protocol;

@end
