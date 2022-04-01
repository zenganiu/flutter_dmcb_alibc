/*
 * AlibcTradeContainerManager.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeContainer 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <AlibcTradeBaseContainer/AlibcTradeContainerProtocol.h>
#import <AlibcTradeBaseContainer/AlibcTradeContainerContextModel.h>

NS_ASSUME_NONNULL_BEGIN
@interface AlibcTradeContainerManager : NSObject

+ (instancetype)sharedInstance;

/**
 初始化容器
 */
- (void)initConatinerWithData:(NSDictionary *)data;

/**
 设置容器环境参数
 */
- (void)setContainerEnv:(NSString *)env WithContainerTag:(NSString *)containerTag;

/**
 设置SDK配置信息
 */
- (void)setSDKSetting:(NSDictionary *)sdkSetting WithGroupName:(nonnull NSString *)groupName WithContainerTag:(NSString *)containerTag;

/**
 加载内容
 */
- (NSError *)loadUrlWithContext:(AlibcTradeContainerContextModel *)context;

/*
 加载组件
 */
- (NSError *)loadComponentWithContext:(AlibcTradeContainerContextModel *)context
                             callBack:(void (^)(NSError *error,UIViewController *componentVC))callBack;

/**
 继续加载
 */
- (NSError *)loadNewUrlInBeforeContainerWithContext:(AlibcTradeContainerContextModel *)context;

/**
 刷新容器
 */
- (void)reloadWithContainerTag:(NSString *)containerTag;


/**
 goback
 */
- (void)goBackWithContainerTag:(NSString *)containerTag;

/**
 关闭容器
 */
- (void)closeContainerWithContainerTag:(NSString *)containerTag;

/**
 设置AppInfo
 */
- (void)setAppInfo4Container:(AlibcTradeContainerAppInfoModel *)appInfoModel WithContainerTag:(NSString *)containerTag;


@end

NS_ASSUME_NONNULL_END
