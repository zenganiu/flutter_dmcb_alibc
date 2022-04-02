//
//  DWLonginStatusProtocol.h
//  DWInteractiveSDK
//
//  Created by wentao.wwt on 2017/3/7.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DWLonginStatusProtocol<NSObject>

- (BOOL)isValidLogin;

- (NSString*)currentUserName;

- (void)loginWitCompletion:(void(^)(BOOL))compltete;
@end
