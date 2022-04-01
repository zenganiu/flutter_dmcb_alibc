//
//  RVKWebViewURLProtocol.h
//  Poseidon
//
//  Created by chenwenhong on 14-10-15.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FakeNSURLProtocol : NSObject

@property(readonly, copy) NSCachedURLResponse *cachedResponse;
@property(readonly, retain) id<NSURLProtocolClient> client;
@property(readonly, copy) NSURLRequest *request;

- (instancetype)initWithRequest:(NSURLRequest *)request cachedResponse:(NSCachedURLResponse *)cachedResponse client:(id<NSURLProtocolClient>)client;
- (void)startLoading;
- (void)stopLoading;
+ (id)propertyForKey:(NSString *)key inRequest:(NSURLRequest *)request;
+ (void)setProperty:(id)value forKey:(NSString *)key inRequest:(NSMutableURLRequest *)request;
+ (void)removePropertyForKey:(NSString *)key inRequest:(NSMutableURLRequest *)request;
+ (BOOL)requestIsCacheEquivalent:(NSURLRequest *)a toRequest:(NSURLRequest *)b;
+ (BOOL)canInitWithRequest:(NSURLRequest *)request;

@end

@class RVKResponse;

@protocol RVKWebViewURLProtocolDelegate <NSObject>

- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol willStartLoading:(NSURLRequest *)request channelId:(NSString *)channelId; // 最原始的request
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol startLoading:(NSURLRequest *)request; // request可以被修改
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol wasRedirectedToRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirectResponse;
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol didReceiveResponse:(NSURLResponse *)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy;
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol didLoadData:(NSData *)data;
- (void)RVKWebViewURLProtocolDidFinishLoading:(NSURLProtocol *)protocol;
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol didFailWithError:(NSError *)error;
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol didCancel:(NSError *)error;

@optional
- (void)RVKWebViewURLProtocol:(NSURLProtocol *)protocol
                         task:(NSURLSessionTask *)task
   didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics;

@end

// intercept requests
#if PRODUCT_WALLET
@interface RVKWebViewURLProtocol : NSURLProtocol<NSURLConnectionDataDelegate, RVKWebViewURLProtocolDelegate>
#else
@interface RVKWebViewURLProtocol : FakeNSURLProtocol<NSURLConnectionDataDelegate, RVKWebViewURLProtocolDelegate>
#endif

@property(nonatomic, strong) NSMutableURLRequest *proxyRequest;
@property(nonatomic, strong) RVKResponse *proxyResponse;
@property(nonatomic, strong) NSURLConnection *connection;
@property(nonatomic, strong) NSURLResponse *response;
@property(nonatomic, strong) id<RVKWebViewURLProtocolDelegate> urlProtocolProcessor;
@property(nonatomic, strong) NSURLSessionDataTask *sessionTask;

@end
