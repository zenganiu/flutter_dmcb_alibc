//
//  munion.h
//  MunionBcAdSDK
//
//  Created by 江滔 on 2019/11/27.
//  Copyright © 2019 江滔. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface munion : NSObject

+(instancetype)sharedInstance;

/**
 * @ 传入现有的跳转URL 返回拼接ClickID参数后的新URL
 * @ param currentUrl 当前URL
 *
 */
-(NSString *) handleADUrl:(NSString *) currentURL;

/**
 * @ 传入现有的跳转URL 返回Clickid
 * @ param currentUrl 当前URL
 *
 */
-(NSString *) handleADUrlForClickid:(NSString *) currentURL;

@end

NS_ASSUME_NONNULL_END
