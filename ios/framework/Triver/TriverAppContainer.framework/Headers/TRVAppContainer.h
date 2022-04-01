//
//  TRVAppContainer.h
//  Triver
//
//  Created by zhongweitao on 2019/4/8.
//

#import <Foundation/Foundation.h>
#import "TRVAppRootViewController.h"
#import "RVRAppEnterInfo+TRVExtension.h"
#import <AriverResource/RVRApp.h>
#import <WindmillTRiverKit/TRVAppContainerProtocol.h>
#import "TRVAppPageViewController.h"

#define kAppContainerExpandoKey @"kAppContainerExpandoKey"
#define TRVAppLoadingTypeKey @"trvLoadingType"

typedef void(^TRVTargetAppComplete)(NSString *status);

typedef void(^TRVOpenEmbedAppCompletion)(TRVAppPageViewController *appPageViewController, NSError *error);

@interface TRVAppContainer : NSObject <TRVAppContainerProtocol>

/// @brief 小程序ID
@property (nonatomic, strong, readonly) NSString *appId;

/// @brief 小程序程序码信息
@property (nonatomic, strong) RVRAppEnterInfo *appEnterInfo;

/// @brief app
@property (nonatomic, strong, readonly) RVRApp *arvApp;

/// @brief 第一个页面VC
@property (nonatomic, strong, readwrite) TRVAppPageViewController *firstPageVC;

/// @brief 是否打开直投的二级页
@property (nonatomic, assign) BOOL showIndexPage;

@property (nonatomic, strong, readwrite) NSDictionary *extraParams;

@property (nonatomic, strong) NSDictionary *appResumeData;

@property (nonatomic, assign) TRVAppOpenType appOpenType;
@property (nonatomic, assign) BOOL embedAppPaused;

/// @brief 小程序最近一次访问时间
@property (nonatomic, assign) NSTimeInterval lastVisitTime;
@property (nonatomic, assign) BOOL isOpenByAlive;

/// @brief 容器启动时间戳, ms
@property (nonatomic, assign) NSTimeInterval containerStartTimestamp;

#pragma mark - navigateToMiniProgram
@property (nonatomic, weak) TRVAppContainer *navigateTargetContainer;
@property (nonatomic, copy) TRVTargetAppComplete targetAppComplete;


/// @brief 用TRVAppEnterInfo初始化
- (instancetype)initWithAppEnterInfo:(RVRAppEnterInfo *)appEnterInfo extraParams:(NSDictionary *)extraParams;
- (instancetype)initWithEmbedAppEnterInfo:(RVRAppEnterInfo *)appEnterInfo;

/// @brief 获取小程序根ViewController
- (TRVAppRootViewController *)getAppRootViewController;

- (void)startApp;

- (void)closeApp;
- (void)closeApp:(void (^)(void))completion;

- (void)backToAppFirstPage:(BOOL)reLaunch;

- (void)updateAppExtraData:(NSDictionary *)params;

/// @brief 清理小程序内存
- (void)cleanUpForMemory;

/// @brief 打开小程序首页
- (void)loadAppFirstPage;

/// @brief 加载完成后隐藏Loading
- (void)hideAppLoading;

#pragma mark - embed app

- (void)startEmbedApp:(TRVOpenEmbedAppCompletion)completion;

@end
