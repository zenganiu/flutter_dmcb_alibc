//
//  WMLAppShareManager.h
//  AppContainer
//
//  Created by AllenHan on 2018/4/18.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TRVBaseViewController.h"

#define TRVShareSourceMenu @"menu"
#define TRVShareSourceKey  @"from"

// 手淘分享组件文档参考：https://lark.alipay.com/zxf94492/ucip5m/welcome-to-lark
#define kShareTemplate4Detail  @"detail" // 分享组件提供的 详情 类型的分享模板
#define kShareTemplate4Group   @"group" // 分享组件提供的 小分队 类型的分享模板
#define kShareTemplate4Weex    @"weex" // 分享组件提供的 weex 类型分享模板
#define kShareTemplateFromNet  @"net"   //需要从网络上获取模板
#define kShareTemplate4Shop     @"shop"   //分享组件提供的 店铺 类型分享模板

//轻店铺首页分享默认底图
#define kTinyShopShareIndexBgImage @"https://gw.alicdn.com/tfs/TB1AuhZLH2pK1RjSZFsXXaNlXXa-1160-648.png"
//轻店铺次级页分享默认底图
#define kTinyShopShareOtherBgImage @"https://gw.alicdn.com/tfs/TB14xcVeTZmx1VjSZFGXXax2XXa-1160-648.png"

// 分享API入参Key定义
#define TRVAPIShareTitleKey     @"title"
#define TRVAPIShareImageUrlKey  @"imageUrl"
#define TRVAPIShareDescKey      @"desc"

// 分享透传MapKey定义
#define TRVShareViewControllerKey @"viewController"

@interface TRVAppShareManager : NSObject

+ (instancetype)sharedInstance;



/**
 分享小程序的单页

 @param pageVC 单页的PageViewController
 */
- (void)sharePage:(TRVBaseViewController *)pageVC;


/**
  框架分享，分享小程序的单页

 @param pageVC 单页的PageViewController
 @param completed 完成回调
 */
- (void)sharePage:(TRVBaseViewController *)pageVC completed:(void (^)(BOOL success, NSDictionary *resultInfo))completed;

    
/**
 API分享，自定义分享内容

 @param customInfo 自定义分享内容，相应的Key如下
 * @"title":    分享的标题
 * @"desc":     描述
 * @"imageUrl": 分享的图片
 * @"url":      分享的URL
 * @"parent":   分享时所在的VC
 * @"targets":  分享的渠道
 */
- (void)shareCustomInfo:(NSDictionary *)customInfo pageVC:(TRVBaseViewController *)pageVC  completed:(void (^)(BOOL success, NSDictionary *resultInfo))completed;

#pragma mark - Share Url

/**
 生成页面的分享URL

 @param pageVC 当前页面
 @param customPath 自定义Path
 */
- (NSString *)generalShareUrlForPageVC:(TRVBaseViewController *)pageVC customPath:(NSString *)customPath;

@end
