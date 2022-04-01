//
//  AliWMLMtopManager.h
//  AliWindmillPermission
//
//  Created by AllenHan on 2018/12/4.
//  Copyright © 2018年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliWMLMtopRequest.h"
#import "NSError+WMLMtop.h"

typedef void(^AliWMLMtopRequestComplete)(BOOL success, NSDictionary *respJsons, NSError *error);

typedef NS_ENUM(NSUInteger, AliWMLMtopSource) {
    AliWMLMtopSourceFromMiniApp, //小程序请求
    AliWMLMtopSourceFromMiniAppSDK,//小程序框架请求
};

@interface AliWMLMtopManager : NSObject

///小程序请求
+ (void)request:(AliWMLMtopRequest *)request completion:(AliWMLMtopRequestComplete)completion;

+ (NSDate *)mtopServerDate;

@end
