//
//  RVPUtils.h
//  AriverApi
//
//  Created by nico on 2019/4/24.
//  Copyright © 2019 Alipay. All rights reserved.
//


#import <AriverKernel/AriverKernel.h>
#import "RVPViewControllerProtocol.h"

#define kRVP_Error                      @"error"
#define kRVP_Error_Msg                  @"errorMessage"

@class RVPPushWindowAdvisor;
@protocol RVPVCTabBarProtocol;

@interface RVPUtils: NSObject

+ (NSString *)convertAlipayRunSceneToAppX:(NSString *)sourceScene;

+ (NSString *)getAlipayRunSceneWithAppId:(NSString *)appId;

+ (RVPPushWindowAdvisor *)pushWindowAdvisor;

+ (id<RVPViewControllerProtocol>)rvpViewControllerProtocolImp;

+ (id<RVPVCTabBarProtocol>)vcTabbarProtocolImp;

@end

