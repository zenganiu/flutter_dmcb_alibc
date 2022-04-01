//
//  RVPWebSocketMgr.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVPWebSocketDefines.h"
#import "RVPWebSocketHandler.h"

@interface RVPWebSocketMgr : NSObject<RVPWebSocketHandlerDelegate>

@property (nonatomic) NSMutableDictionary<NSString*,RVPWebSocketHandler*>* dicAppID2WebSocketHandler;

+(instancetype)shareInstance;

-(NSInteger)connectionsCountForAppID:(NSString *)appid;
-(BOOL)hasConnectionForAppID:(NSString *)appid socketTaskId:(NSString *)socketTaskId;

-(void)closeAndDeleteAllWebSocketHandler;

-(void)closeAndDeleteHandlerWithAppID:(NSString*)appid;

-(void)closeAndDeleteHandlerWithAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID;

-(void)closeSocketWithAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID;

-(void)closeSocketWithAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID code:(NSInteger)code reason:(NSString*)reason;

-(void)connectSocketWithAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID multiple:(BOOL)multiple appVersion:(UInt64)version isIgnoreCheckDomain:(BOOL)ignDomain url:(NSURL*)url httpHeader:(NSDictionary*)headers method:(NSString*)method params:(NSString*)data completionHandler:(RVPConnectWebSocketCompletionHandler)completionHandler openHandler:(RVPCallBackOnWebSocketOpen)openHandler messageHandler:(RVPCallBackOnWebSocketRecieveMessage)messageHandler errorHandler:(RVPCallBackOnWebSocketError)errorHandler closeHandler:(RVPCallBackOnWebSocketClose)closeHandler;

-(void)sendMessage:(id)msg withAppID:(NSString*)appid socketTaskID:(NSString *)socketTaskID completionHandler:(RVPSendWebSocketMessageCompletionHandler)handler;



@end
