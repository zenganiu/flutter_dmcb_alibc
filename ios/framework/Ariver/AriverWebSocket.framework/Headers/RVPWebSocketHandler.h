//
//  RVPWebSocketHandler.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVPWebSocketConfig.h"
#import "RVPWebSocketDefines.h"
#import "SRWebSocket.h"

@class RVPWebSocketHandler;

@protocol RVPWebSocketHandlerDelegate <NSObject>

-(void)webSocketDidClose:(RVPWebSocketHandler*)handler;

@end

@interface RVPWebSocketHandler : NSObject<SRWebSocketDelegate>

@property (nonatomic) NSString*             appID;              //小程序的唯一标识
@property (nonatomic) NSString*             socketTaskID;       //同一小程序下socketTask唯一标识

@property (nonatomic) UInt64                appVersion;         //小程序版本

@property (nonatomic) RVPWebSocketConfig*    webSocketConfig;    //当前handler的配置

@property (nonatomic) BOOL                  isOpen;

@property (nonatomic) SRWebSocket*          webSocket;          //socket结构

@property (nonatomic) dispatch_queue_t      workerQueue;        

@property (nonatomic,weak) id<RVPWebSocketHandlerDelegate> delegate;

@property (nonatomic) RVPCallBackOnWebSocketOpen  openCallBack;
@property (nonatomic) RVPCallBackOnWebSocketRecieveMessage messageCallBack;
@property (nonatomic) RVPCallBackOnWebSocketError errorCallBack;
@property (nonatomic) RVPCallBackOnWebSocketClose closeCallBack;

-(void)callbackWithError:(NSError*)err;

-(void)close;
-(void)closeWithCode:(NSInteger)code reason:(NSString*)reason;

-(instancetype)initWithAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID appVersion:(UInt64)version workerQueue:(dispatch_queue_t)queue;

-(void)openWithRequest:(NSMutableURLRequest*)request isIgnoreCheckDomain:(BOOL)ignDomain completionHandler:(RVPOpenWebSocketCompetionHandler)handler;

-(void)sendMessage:(id)msg completionHandler:(RVPSendWebSocketMessageCompletionHandler)handler;

-(void)webSocketAppid:(NSString*)appid version:(UInt64)version upFlow:(NSInteger)up downFlow:(NSInteger)down;

@end

































