//
//  RVPAccountInfoProtocol.h
//  AriverApi
//
//  Created by hua.lu on 2019/6/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVPAccountInfoProtocol_h
#define RVPAccountInfoProtocol_h

@protocol RVPAccountInfoProtocol <NSObject>
- (NSString *)loginUserToken;
@end

@protocol RVPAppInfoProtocol <NSObject>
- (NSArray *)AppSchemes;
- (NSString *)AppName;
- (NSString *)AppVer;
@end

#endif /* RVPAccountInfoProtocol_h */
