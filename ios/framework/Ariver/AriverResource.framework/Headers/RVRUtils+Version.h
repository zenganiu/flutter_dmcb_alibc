//
//  NXRUtils+Version.h
//  NebulaResource
//
//  Created by 扶瑶 on 16/3/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "RVRUtils.h"

/**
 按版本排序
 
 @param version1
 @param version2
 @return
 (versionName1格式正确 && versionName2格式错误) 	||	versionName1 > versionName2 : return 1;
 ((versionName1 && versionName2)格式错误) 		||	versionName1 = versionName2 : return 0;
 (versionName1格式错误 && versionName2格式正确) 	||	versionName1 < versionName2 : return -1;
 
 如：
 version1[null], 		version2[null], 		result["0"].
 version1[null], 		version2[""], 			result["0"].
 version1[null], 		version2[""], 			result["0"].
 version1[""], 			version2[""], 			result["0"].
 version1[""], 			version2["1.0.0.0"], 	result["-1"].
 version1[""], 			version2["1.0"], 		result["-1"].
 version1["a.b.c"], 		version2["1.0.1.1"], 	result["-1"].
 version1["a.b.c"], 		version2["a.b.c"], 		result["0"].
 version1["1"], 			version2["1"], 			result["0"].
 version1["1"], 			version2["1.0"], 		result["0"].
 version1["1"], 			version2["1.0.0.0"], 	result["0"].
 version1["1"], 			version2["2"], 			result["-1"].
 version1["1"], 			version2["1.1"], 		result["-1"].
 version1["1"], 			version2["1.0.0.1"], 	result["-1"].
 version1["1"], 			version2["0.9.9.9"], 	result["1"].
 version1["1"], 			version2["0."], 		result["1"].
 version1["1.1"], 		version2["1"], 			result["1"].
 version1["1.1"], 		version2["1.1"], 		result["0"].
 version1["1.1"], 		version2["1.2"], 		result["-1"].
 version1["1.1"], 		version2["1.2.3.4"], 	result["-1"].
 version1["1.2.3.4"], 	version2["1"], 			result["1"].
 version1["1.2.3.4"], 	version2["1.2"], 		result["1"].
 version1["1.2.3.4"], 	version2["1.2.3.3"], 	result["1"].
 version1["1.2.3.4"], 	version2["1.2.3.4"], 	result["0"].
 version1["1.2.3.4"], 	version2["1.3"], 		result["-1"].
 version1["1.2.3.4"], 	version2["1.2.3.5"], 	result["-1"].
 version1["1.2.3.4"], 	version2["2.2.3.4"], 	result["-1"].
 version1[".2.3.4"], 	version2["1.2.3.4"], 	result["-1"].
 version1[".x"], 		version2["1"], 			result["-1"].
 version1[".x"], 		version2[".x"], 		result["0"].
 version1["-1.2.3.4"], 	version2["1.2.3.4"], 	result["-1"].
 version1["-1.2.3.4"], 	version2["-1.2.3.4"], 	result["0"].
 version1["-1.2.3.4"], 	version2["a.b.c.d"], 	result["0"].
 
 解释：
 格式错误：   null, "", "a.b.c", "-1.2.3.4" 1.2. .2.3 .2.3..4.5.6
 格式化规则：	1			->	1.0.0.0
 1.2			->	1.2.0.0
 1.2.3.4		->	1.2.3.4
 1.2.3.4.5	->	1.2.3.4
 */
NSInteger NXRCompareVersions(NSString *version1, NSString *version2, void *context);

/**
 *  模糊匹配,找出数据源中模糊匹配的最大的版本号
 *
 *  version: 支持4位模糊查询  *  N.*  N.*.*  N.*.*.*
 *
 *  @param versin 待模糊匹配的版本号
 *  @param source 数据源
 *
 *  @return 模糊匹配的最大版本号
 */
NSString *NXRFuzzyMatchMaxVersion(NSString *version, NSArray *source);

/**
 *  获取最大/最小版本号
 *
 *  @param source 待筛选数据源
 *
 *  @return 返回最大/最小版本号
 */
NSString *NXRMaxVersion(NSArray *source);
NSString *NXRMinVersion(NSArray *source);

/**
 *  判断是否为支持的模糊查找版本号格式
 */
BOOL NXRIsFuzzyMatchFormat(NSString *version);

/**
 *  版本号由高到低排序
 */
NSArray *NXRSoredVersions(NSArray *arrVersions);
