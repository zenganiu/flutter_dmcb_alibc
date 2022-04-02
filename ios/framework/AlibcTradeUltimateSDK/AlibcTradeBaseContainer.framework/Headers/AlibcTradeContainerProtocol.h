/*
 * AlibcTradeContainerProtocol.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeBaseContainer 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AlibcTradeContainerAppInfoModel.h"
#import "AlibcTradeContainerContextModel.h"
#import "AlibcTradeContainerEventListenerBaseProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/** 容器当前状态 */
typedef NS_ENUM (NSUInteger, AlibcContainerState) {
    /** 容器未进行初始化 */
    AlibcContainerUnInit = 0,
    /** 容器初始化当中 */
    AlibcContainerIniting = 1,
    /** 容器初始化完成 */
    AlibcContainerInitSucc = 2,
    /** 容器初始化失败 */
    AlibcContainerInitFailed = 3
};

@protocol AlibcTradeContainerProtocol <NSObject>

/**
 初始化容器
 */
@required
- (void)initConatinerWithData:(NSDictionary *)data;

/**
 容器唯一标识
 */
@required
- (NSString *)conatinerTag;

/**
 设置容器环境参数
 */
@required
- (void)setContainerEnv:(NSString *)env;

/**
 返回容器状态
 */
@required
- (AlibcContainerState)containerState;

/**
 加载内容
 */
@required
- (BOOL)loadUrlWithContext:(AlibcTradeContainerContextModel *)context;

/**
 刷新容器
 */
@required
- (void)reload;

/**
 关闭容器
 */
@required
- (void)closeContainer;

/**
 创建容器组件并返回
*/
@optional
- (void)loadComponent4Context:(AlibcTradeContainerContextModel *)context
                     callBack:(void (^)(NSError *error,UIViewController *componentVC))callBack;

/**
 创建容器组件并返回
*/
@optional
- (void)loadNativeComponent4Context:(AlibcTradeContainerContextModel *)context
                           callBack:(void (^)(NSError *error,UIViewController *componentVC))callBack;

/**
 设置AppInfo
 */
@optional
- (void)setAppInfo4Container:(AlibcTradeContainerAppInfoModel *)appInfoModel;


/**
 SDK Setting
 */
@optional
- (void)setSDKSetting:(NSDictionary *)sdkSetting WithGroupName:(NSString *)groupName;

/**
 在原容器中加载新URL
 */
@optional
- (void)loadNewUrlInBeforeContainerWithContext:(AlibcTradeContainerContextModel *)context;

/**
 容器页面回退
 */
@optional
- (void)goback;
@end

NS_ASSUME_NONNULL_END
