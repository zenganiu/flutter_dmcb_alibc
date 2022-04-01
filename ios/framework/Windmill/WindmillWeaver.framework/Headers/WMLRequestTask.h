//
//  WMLRequestTask.h
//  Weaver
//
//  Created by lianyu on 2018/7/17.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol WMLRequestTask <NSObject>

@required

/**
 要发送的请求。
 */
@property (nonatomic, copy, readonly, nonnull) NSURLRequest * request;

/**
 请求已结束。
 */
- (void)didFinish;

/**
 请求失败。
 */
- (void)didFailWithError:(NSError * _Nullable)error;

@optional

/**
 已发送指定的数据。
 */
- (void)didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;

/**
 接收到响应。
 */
- (void)didReceiveResponse:(NSURLResponse * _Nonnull)response;

/**
 已经执行重定向。
 */
- (void)didPerformRedirection:(NSURLResponse * _Nonnull)response newRequest:(NSURLRequest * _Nonnull)request;

/**
 接收到响应数据。
 */
- (void)didReceiveData:(NSData * _Nonnull)data;

@end
