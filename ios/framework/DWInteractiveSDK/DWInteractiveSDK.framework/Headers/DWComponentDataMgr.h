//
//  DWComponentDataMgr.h
//  DWInteractiveSDK
//
//  Created by zzqiltw on 16/5/4.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DWInteractiveSDK/DWComponent.h>
@interface DWComponentDataInstancePair : NSObject

@property (nonatomic, strong) DWComponent *landscapeInstance;
@property (nonatomic, strong) DWComponent *portraitInstance;

- (instancetype)initWithLandscapeInstance:(DWComponent *)landscapeInstance portraitInstance:(DWComponent *)protraitInstance;

@end

@interface DWComponentDataMgr : NSObject

+ (DWComponentDataMgr *)shareInstance;

- (void)clearAllData;
- (void)addInstancePairToListLandScape:(DWComponent *)landscape andPortrait:(DWComponent *)portrait;
- (DWComponent *)getAnotherInstanceWith:(DWComponent *)instance;

@end
