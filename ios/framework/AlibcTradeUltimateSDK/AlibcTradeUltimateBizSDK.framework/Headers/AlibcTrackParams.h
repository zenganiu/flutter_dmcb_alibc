/*
 * AlibcTrackParams.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeUltimateBizSDK 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcTrackParams : NSObject
/**必填: 供计算效果用，由推荐模块输出内容后，曝光埋点使用 */
@property(nonatomic, strong) NSString *scm;
/**必填: 供计算效果用，由推荐模块输出内容后，曝光埋点使用 */
@property(nonatomic, strong) NSString *pvid;
/**必填: 三方app的用户识别id，用于百川识别该用户行为并对推荐效果进行优化 */
@property(nonatomic, strong) NSString *puid;
/** 三方app页面名称*/
@property(nonatomic, strong) NSString *page;
/** 三方app控件名称 */
@property(nonatomic, strong) NSString *label;


/*
 * trackParam 参数key说明
 */
#define track_scm @"scm"
#define track_pvid @"pvid"
#define track_isv_code @"isv_code"

/**
 *  生成Dictionary
 */
- (NSDictionary *)toDictionary;

+ (NSString *)ybhpssStringForDictionary:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
