//
//  WMLShareProtocol.h
//  Windmill
//
//  Created by Jason Lee on 2018/5/10.
//

#import <WindmillWeaver/WMLBaseProtocol.h>

#import "WMLAppCustomPageShareInfoModel.h"
#import "WMLAppShareInfo.h"

@protocol WMLShareProtocol <WMLBaseProtocol>

@optional
/**
 触发分享，相关分享的信息通过shareInfo透出
 
 shareInfo 字段：
 * @"url"             分享的URL
 * @"title"           分享的标题
 * @"description"     分享的描述
 * @"imageUrl"        分享的图片URL
 * @"targets"         分享的渠道，值为字符串数组 @[@"name2", @"name2", @"name3"]
 * @"viewController"  当前页面ViewController
 * @"templateId"      模板ID（手淘分享模板）
 *
 * 另外，构造的WMLAppCustomPageShareInfoModel对象中的自定义参数customParams，会在shareInfo中透传
 */
- (void)share:(NSDictionary *)shareInfo completed:(void (^)(BOOL success, NSDictionary *resultInfo))completed;

//
///**
// 新的分享接口
//
// @param shareModel 分享model
// @param completed 分享完成回调
// */
//- (void)shareWithInfo:(WMLAppShareInfo *)shareModel complete:(void (^)(BOOL success, NSDictionary *resultInfo))completed;


#pragma mark - 业务分享
/**
 店铺二楼特殊分享逻辑
 */
- (void)share4BrandZoneWithUrl:(NSString *)shareUrl title:(NSString *)shareTitle image:(NSString *)shareImage desc:(NSString *)shareDesc viewController:(UIViewController *)viewController;


@end
