//
// UIViewController+UTTrack.h
// 
// UserTrack 
// 开发团队：数据通道团队 
// UT答疑群：11791581(钉钉) 
// UT埋点平台答疑群：11779226(钉钉) 
// 
// Copyright (c) 2014-2017 Taobao. All rights reserved. 
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** 是否为VC或者View */
#define UT_IS_VC_OR_VIEW(object) ([object isKindOfClass:[UIViewController class]] || [object isKindOfClass:[UIView class]])
/** 是否为VC */
#define UT_IS_VC(object) ([object isKindOfClass:[UIViewController class]])
/** 是否为VIew */
#define UT_IS_VIEW(object) ([object isKindOfClass:[UIView class]])

@interface UIViewController(UTTrackHook)

@property(nonatomic, retain) NSString *utActionName;
@property(nonatomic, retain) NSDictionary *utArgs;
@property(nonatomic, retain) NSURL *utNavUrl;
@property(nonatomic, retain) NSDictionary *utProperties;
@property(nonatomic, retain) NSString * utPageNameAlias;// 页面别名
@property(nonatomic,retain) NSString * utH5HasCalled;
@property(nonatomic,retain) NSString * utHasAppeared;

#pragma mark - spm-pre专用
/** 新增spm-pre属性 */
@property (nonatomic, copy)   NSString *utSpmPre;
@property (nonatomic, copy)   NSString *utSpmUrl;
@property (nonatomic, copy)   NSString *utSpmCnt;
/** 默认进入的spm-pre-next值，用于privateNextPageProperties中的数据被销毁之后 用于复原 */
@property (nonatomic, copy)   NSString *utSpmPreNext;

#pragma mark - utParam带两步专用
/** 新增utParam属性 */
@property (nonatomic, copy)   NSString *utParamPre;
@property (nonatomic, copy)   NSString *utParamUrl;
@property (nonatomic, copy)   NSString *utParamCnt;
/** 默认进入的utparam-pre-next值，用于privateNextPageProperties中的数据被销毁之后 用于复原 */
@property (nonatomic, copy)   NSString *utParamPreNext;

#pragma mark - scm专用
@property (nonatomic, copy)   NSString *utScmPre;
@property (nonatomic, copy)   NSString *utScmUrl;
@property (nonatomic, copy)   NSString *utScmPreNext;

/** 是否为返回 */
@property (nonatomic, assign) BOOL utIsbk;
/** 是否设置返回，如果设置为返回，不执行返回判断逻辑，直接执行返回计算逻辑 */
@property (nonatomic, assign) BOOL utIsbkManually;
/** 是否present了一个新VC */
@property (nonatomic, assign) BOOL utPresentNew;

/** 仅限于H5调用 */
- (void)ut_h5UpdateSpmInfo:(NSDictionary *)spmInfo;
- (void)ut_h5UpdateScmInfo:(NSDictionary *)scmInfo;

/** 当前VC的navi */
- (UINavigationController *)ut_correctNavigationController;
- (UIViewController *)ut_correctPresentedViewController;

/** 是否为子VC */
- (BOOL)ut_isChildViewController;

/** 是否为返回状态 */
- (BOOL)ut_isBackWithStackLength:(NSInteger)stackLength;
- (BOOL)ut_isBackWithStackLength:(NSInteger)stackLength navi:(UINavigationController *)navi;
/** 判断是否手淘导航 */
- (BOOL)isUseTBNav;
@end
