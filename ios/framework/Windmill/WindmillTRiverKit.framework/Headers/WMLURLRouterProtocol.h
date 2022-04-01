//
//  WMLURLRouterProtocol.h
//  Windmill
//
//  Created by Jason Lee on 2018/5/13.
//

#import <WindmillWeaver/WMLBaseProtocol.h>
#import "TRVBaseViewController.h"
#import <UIKit/UIKit.h>

#define TRVRouterBizTypeKey @"TRVRouterBizTypeKey"
#define TRVLoadingParamsKey @"TRVLoadingParamsKey"

@protocol WMLURLRouterProtocol <WMLBaseProtocol>

- (void)openURL:(NSString *)urlStr onViewController:(UIViewController *)vc withParam:(NSDictionary *)param animated:(BOOL)animated;

@optional


/**
 * 跳转目标小程序

 @param params 参数，字段定义如下：
 * @"appId" : 跳转到的小程序appId
 * @"path" : 打开的页面路径，如果为空则打开首页
 * @"extraData" : 需要传递给目标小程序的数据
 * @"frameType" : 目标小程序的类型 @"pubArea":轻应用 ；@"priArea":轻店铺
 @param vc 当前小程序显示的ViewController
 */
- (void)navigateToMiniProgramWithParams:(NSDictionary *)params onViewController:(TRVBaseViewController *)vc;


/**
 * 跳转回上一个小程序

 @param params 参数，字段定义如下：
 * @"extraData" : 需要传递给目标小程序的数据
 @param vc 当前小程序显示的ViewController
 */
- (void)navigateBackMiniProgramWithParams:(NSDictionary *)params onViewController:(TRVBaseViewController *)vc;

/**
 * 返回到App首页

 @param params 参数，字段定义如下：
 * @"extraData" : 需要传递给目标小程序的数据
 @param vc 当前小程序显示的ViewController
 */
- (void)popToAppHomeWithParams:(NSDictionary *)params onViewController:(TRVBaseViewController *)vc;


@end



#define TRVTidaExt_SceneKey @"Ext_SceneKey"
#define TRVTidaExt_WindowKey @"Ext_Window"
#define TRVTidaExt_TTCInfoKey @"Ext_TTCInfo"
@protocol TRVTidaContainerRouterProtocol <NSObject>

/**
 在容器内部打开一个线上的H5页面
 
 @param url 页面地址
 @param vc 当前跳转的VC
 @param extInfo 拓展信息
 */
- (void)navigateToTidaUrl:(NSString *)url onViewController:(TRVBaseViewController *)vc  extInfo:(NSDictionary *)extInfo;

@end
