//
//  WMDefine.h
//  Weaver
//
//  Created by Cai Xiaomin on 2018/11/15.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#ifndef WMDefine_h
#define WMDefine_h

/**
 *  @abstract Compared with system version of current device
 *
 *  @return YES if greater than or equal to the system verison, otherwise, NO.
 *
 */
#define WM_SYS_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

/**
 *  @abstract Compared with system version of current device
 *
 *  @return YES if greater than the system verison, otherwise, NO.
 *
 */
#define WM_SYS_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)

/**
 *  @abstract Compared with system version of current device
 *
 *  @return YES if equal to the system verison, otherwise, NO.
 *
 */
#define WM_SYS_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)

/**
 *  @abstract Compared with system version of current device
 *
 *  @return YES if less than the system verison, otherwise, NO.
 *
 */
#define WM_SYS_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

/**
 *  @abstract Compared with system version of current device
 *
 *  @return YES if less than or equal to the system verison, otherwise, NO.
 *
 */
#define WM_SYS_LESS_THAN_OR_EQUAL_TO(v)             ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


#endif /* WMDefine_h */
