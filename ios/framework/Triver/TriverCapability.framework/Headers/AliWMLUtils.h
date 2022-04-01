//
//  AliWMLUtils.h
//  AliWindmill
//
//  Created by AllenHan on 2018/8/2.
//  Copyright © 2018年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindmillTRiverKit/TRVDefines.h>
#import <WindmillTRiverKit/TRVBaseViewController.h>

@interface AliWMLUtils : NSObject

// 首次关注前三次弹窗
#define kFirstCollectSuccessTimesKey        @"new_first_collect_success_times_key"
// 关注成功引导，是否需要再次显示强提示
#define kSecondCollectSuccessShowKey   @"new_second_collect_success_key"
// 关注成功常态提示显示次数
#define kCollectNormalSuccessShownTimesKey @"collect_normal_success_times_key"

#pragma mark - 大闭环新手引导弹层
+ (BOOL)isNeedShowGuideView4HugeClosedCycle:(NSString *)appId hasTask:(BOOL)hasTask;

#pragma mark - UT
+ (NSDictionary *)getCommonParams4Page:(TRVBaseViewController *)vc;
@end
