//
//  RVLEnv.h
//  RiverLogger
//
//  Created by lianyu on 2020/5/19.
//  Copyright © 2020 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RVL_MACRO_CONCAT_(A, B) A##B
#define RVL_MACRO_CONCAT(A, B) RVL_MACRO_CONCAT_(A, B)

/**
 设置指定的环境变量，该环境变量仅在当前线程的本次同步执行中可用。
 */
#define RVLSetEnv(ENV, VALUE) __strong NSString * RVL_MACRO_CONCAT(__RVL_SET_ENV__, __LINE__) __attribute__((cleanup(RVL_EXECUTE_CLEANUP_ENV), unused)) = RVL_SET_ENV((ENV), (VALUE))

#ifdef __cplusplus
extern "C" {
#endif

/**
 获取指定的环境变量。
 */
id _Nullable RVLGetEnv(NSString * _Nonnull envName);
	
NSString * _Nullable RVL_SET_ENV(NSString * _Nonnull envName, id _Nullable value);
void RVL_EXECUTE_CLEANUP_ENV(__strong NSString * _Nullable * _Nonnull envName);

#ifdef __cplusplus
}
#endif

