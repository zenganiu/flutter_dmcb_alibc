//
//  RVPWebSocketDefines.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef RVPWebSocketDefines_h
#define RVPWebSocketDefines_h

#define DEFAULT_TIMEOUT_MILLSECOND 30000

#define DISPATCH_QUEUE_NAME "com.portal.websocket"

@class RVPWebSocketHandler;
@protocol RVPWebSocketLogDelegate,RVPWebSocketStorageDelegate;

extern id<RVPWebSocketStorageDelegate> RVPWebSocketStorage;

typedef void (^RVPOpenWebSocketCompetionHandler)(NSString* appid, NSString *socketTaskID, NSError* error);
typedef void (^RVPSendWebSocketMessageCompletionHandler)(NSString* appid, NSString *socketTaskID, NSError* error);

typedef void (^RVPConnectWebSocketCompletionHandler)(NSString* appid, NSString *socketTaskID,NSError* error);
typedef void (^RVPSendWebSocketMessageCompletionHandler)(NSString* appid, NSString *socketTaskID,NSError* error);
typedef void (^RVPCallBackOnWebSocketOpen)(NSString* appid, NSString *socketTaskID);
typedef void (^RVPCallBackOnWebSocketRecieveMessage)(NSString* appid, NSString *socketTaskID,id data);
typedef void (^RVPCallBackOnWebSocketError)(NSString* appid, NSString *socketTaskID,NSError* error);
typedef void (^RVPCallBackOnWebSocketClose)(NSString* appid, NSString *socketTaskID,NSString* reason);

typedef NS_ENUM(NSInteger,RVPWebSocketErrorCode) {
    RVPErrorCodeSendUnopen = -10001,
    RVPErrorCodeMsgNotStringOrData = -10002,
    RVPErrorCodeMsgSendToNoSocket = -10003,
};

#define RVP_WEBSOCKET_DOMAIN @"RVPWebSocket"
#define RVP_WEBSOCKET_ERROR(errorcode) [[NSError alloc] initWithDomain:RVP_WEBSOCKET_DOMAIN code:errorcode userInfo:nil]

#endif /* RVPWebSocketDefines_h */
