//
// UTTPKItem.h
// 
// UserTrack 
// 开发团队：数据通道团队 
// UT答疑群：11791581(钉钉) 
// UT埋点平台答疑群：11779226(钉钉) 
// 
// Copyright (c) 2014-2017 Taobao. All rights reserved. 
//

#import <Foundation/Foundation.h>

@interface UTTPKItem : NSObject

/*透传key
 */
@property NSString * key;
/*透传方式,有两种:
 *就近:@"nearby"
 *就远:@"far"
 */
@property NSString * type;
/*获取透传key对应的value，有四种来源方式：
 *从url获取:${url|keyx}
 *从updatePageProperties获取:${ut|keyx}
 *先从updatePageProperties获取,然后从url获取:${keyx}
 *静态值:valuex
 */
@property NSString * fetchRule;

@end
