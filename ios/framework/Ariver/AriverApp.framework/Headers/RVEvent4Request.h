//
//  RVEvent4Request.h
//  NebulaApp
//
//  Created by lyusheng on 2018/9/29.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#ifndef RVEvent4Request_h
#define RVEvent4Request_h

@class RVKScene;
@class RVKResponse;

@protocol RVEvent4Request <NSObject>

@optional

// kEvent_Proxy_Request_Start_Handler
// scene:requestHandler:requestDate:customResponse:channelId:
- (void)scene:(RVKScene *)scene
requestHandler:(NSURLRequest *)request
  requestDate:(NSDate *)requestDate
customResponse:(RVKResponse *)customResponse
    channelId:(NSString *)channelId;

// kEvent_Proxy_Request_Response_Handler
// scene:responseHandler:response:requestDate:responseDate:channelId:
- (void)scene:(RVKScene *)scene
responseHandler:(NSURLRequest *)request
     response:(NSURLResponse *)response
  requestDate:(NSDate *)requestDate
 responseDate:(NSDate *)responseDate
    channelId:(NSString *)channelId;


// kEvent_Proxy_Request_Cancel
// scene:requestCancel:error:requestDate:uniqueId:channelId:
- (void)scene:(RVKScene *)scene
requestCancel:(NSURLRequest *)request
        error:(NSError *)error
  requestDate:(NSDate *)requestDate
     uniqueId:(NSString *)uniqueId
    channelId:(NSString *)channelId;


// kEvent_Proxy_Request_ReceiveResponse
// scene:receiveResponse:request:requestDate:responseDate:uniqueId:channelId:
- (void)scene:(RVKScene *)scene
receiveResponse:(NSURLResponse *)response
      request:(NSURLRequest *)request
  requestDate:(NSDate *)requestDate
 responseDate:(NSDate *)responseDate
     uniqueId:(NSString *)uniqueId
    channelId:(NSString *)channelId;


// kEvent_Proxy_Request_Finish
// scene:finishLoad:response:requestDate:responseDate:receiveData:receiveDataLength:error:uniqueId:channelId:
- (void)scene:(RVKScene *)scene
   finishLoad:(NSURLRequest *)request
     response:(NSURLResponse *)response
  requestDate:(NSDate *)requestDate
 responseDate:(NSDate *)responseDate
  receiveData:(NSData *)receiveData
receiveDataLength:(NSUInteger)receiveDataLength
        error:(NSError *)error
     uniqueId:(NSString *)uniqueId
    channelId:(NSString *)channelId;




@end

#endif /* RVEvent4Request_h */
