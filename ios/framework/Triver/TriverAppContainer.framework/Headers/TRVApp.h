//
//  TRVApp.h
//  Triver
//
//  Created by zhongweitao on 2019/4/1.
//

#import <Foundation/Foundation.h>
#import <AriverResource/RVRApp.h>

@interface TRVApp : NSObject

@property (nonatomic, strong) NSString *appId;

@property (nonatomic, strong) NSString *version; // 

@property (nonatomic, assign) double lastUseTime;

@property (nonatomic, assign) double lastRefreshTime;

@property (nonatomic, strong) RVRApp *arvApp;

- (instancetype)initWithRVRApp:(RVRApp *)arvApp;

@end


@interface TRVPlugin : NSObject

@property (nonatomic, strong) NSString *appId;
@property (nonatomic, strong) NSString *deployVersion; //
@property (nonatomic, strong) NSString *developVersion; //
@property (nonatomic, assign) double lastUseTime;
@property (nonatomic, assign) double lastRefreshTime;

@property (nonatomic, strong) RVRApp *arvApp;

- (instancetype)initWithRVRApp:(RVRApp *)arvApp;

@end
