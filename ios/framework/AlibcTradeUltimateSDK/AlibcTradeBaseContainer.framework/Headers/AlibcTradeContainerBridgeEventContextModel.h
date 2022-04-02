/*
 * AlibcTradeContainerBridgeEventContextModel.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeBaseContainer 
 * 版本号：5.0.0.0
 * 发布时间：2020-01-03
 * 开发团队：阿里巴巴百川
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2020 阿里巴巴-淘宝-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "AlibcTradeContainerContextModel.h"

NS_ASSUME_NONNULL_BEGIN
@interface AlibcTradeContainerBridgeEventHandleResult : NSObject

@property (nonatomic,strong)NSError *error;
@property (nonatomic,copy)NSDictionary *resultDataDic;

@end


@interface AlibcTradeContainerBridgeEventContextModel : NSObject

@property (nonatomic,copy)NSString *eventName;
@property (nonatomic,copy)NSDictionary *paramDic;
@property (nonatomic,copy)NSString *sourceType;// h5、miniapp

@property (nonatomic,strong,nullable) AlibcTradeContainerContextModel * containerContext;

@end

NS_ASSUME_NONNULL_END
