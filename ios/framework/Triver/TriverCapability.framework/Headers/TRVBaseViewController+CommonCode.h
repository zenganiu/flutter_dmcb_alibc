//
//  WMLAppPageViewController+CommonCode.h
//  AliWindmill
//
//  Created by Jason Lee on 2018/11/14.
//

#import "WMLAppPageNavBarConsts.h"
//#import "TRVAppFollowGuideBar.h"
//#import "TRVRelationshipFollowManager.h"
#import <WindmillTRiverKit/TRVBaseViewController.h>

typedef NS_ENUM(NSUInteger, AliTRVAppPagePositionType) {
    AliTRVAppPagePositionTypeTabFirstPage,//无Tab时的第一个页面 或 有Tab时第一个Tab上的第一个页面
    AliTRVAppPagePositionTypeTabPage,//非第一个Tab上第一个页面
    AliTRVAppPagePositionTypeSecondPage,//次级页面
};


@interface TRVBaseViewController (CommonCode)

- (WMLAppPageNavBarColorStyle)trv_colorStyle;
- (CGFloat)trv_topMargin4LeftOrRightTopView;

- (NSDictionary *)trv_UTTrackArgs;
- (NSDictionary *)trv_UTTrackArgsWithType:(NSString *)tmpType;


#pragma mark - 设置Action

/**
 获取页面所在位置

 @return 返回页面所在位置
 */
- (AliTRVAppPagePositionType)trv_pagePosition;

/**
 触发默认设置Action
 */
- (void)trv_openDefaultSetting;

#pragma mark -


/**
 触发默认回流页面的返回首页Action
 */
- (void)trv_openAppIndexPage;


//#pragma mark - 关注相关API
//
//@property (nonatomic, strong) TRVAppFollowGuideBar *trv_followBar;
//@property (nonatomic, strong) TRVRelationshipFollowManager *relationFollowManager;
//
///**
// 获取小程序关注状态，如果用户未登陆，或请求失败，返回WMLAppInfoViewFollowStyleUndefined
// */
//- (void)trv_requestFavoriteStatusComplete:(void(^)(WMLAppInfoViewFollowStyle style, id result, NSError *error))complete;
//
///**
// 收藏小程序
//
// @param complete 收藏完成回调，success为YES表示收藏成功，NO表示收藏失败
// @param needTrack 是否需要内部埋点，除了导航栏上的关注外，其它都是NO
// */
//- (void)trv_addFavoriteMiniAppWithComplete:(void (^)(BOOL, NSDictionary *))complete needTrack:(BOOL)needTrack;
///**
// 取消收藏小程序
//
// @param complete 收藏完成回调，success为YES表示取消收藏成功，NO表示取消收藏失败
// */
//- (void)trv_removeFavoriteMiniAppWithComplete:(void(^)(BOOL success, NSDictionary *result))complete;


#pragma mark - 导航能力

/**
 小程序默认返回action
 */
- (void)trv_closeMiniAppPage;

/**
 轻店铺响应该action，轻应用不响应此action
 */
- (void)trv_closeMiniApp;

#pragma mark - ActionSheet

/**
 删除ActionSheet的某一项
 */
- (NSDictionary *)trv_removeMenuItemWithName:(NSString *)name fromMenuInfo:(NSDictionary *)menuInfo;

@end
