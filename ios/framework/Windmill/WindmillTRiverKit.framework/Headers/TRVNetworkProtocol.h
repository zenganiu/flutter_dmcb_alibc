//
//  TRVNetworkProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/2.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TRVNetworkProtocol <NSObject>

@optional
// 获取服务端时间
- (NSTimeInterval)getServerTimeStamp;

// 本地时间与服务器的时间差
- (NSTimeInterval)timestampOffset;

@required
- (void)call:(NSString *)api withParam:(NSDictionary *)param completion:(void (^)(BOOL success, id result, NSError *error))completion;

@end
