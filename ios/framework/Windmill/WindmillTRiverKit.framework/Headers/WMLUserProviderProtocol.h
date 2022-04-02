//
//  WMLUserProviderProtocol.h
//  Windmill
//
//  Created by Jason Lee on 2018/5/10.
//

#import <WindmillWeaver/WMLBaseProtocol.h>

@protocol WMLUserProtocol <WMLBaseProtocol>

@optional

- (BOOL)logined;

- (NSString *)userId;

@end

@protocol WMLUserProviderProtocol <WMLBaseProtocol>

- (id<WMLUserProtocol>)currentUser;

@end
