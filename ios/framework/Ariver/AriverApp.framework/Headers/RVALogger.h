//
//  RVMonitor.h
//  AriverApp
//
//  Created by 章海滨 on 2019/4/15.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>

@protocol RVALoggerDelegate;

@interface RVALogger : NSObject

@property(nonatomic, weak) id<RVALoggerDelegate> delegate;

+ (instancetype)sharedInstance;

//TODO 缺少小程序框架版本号
+ (NSDictionary *)getCommonDatasFromPage:(RVKScene *)page;

+ (NSDictionary * _Nullable)formateDictionaryFromConcatedLoag:(NSString * _Nullable)log;

- (void)errorWithType:(NSString *)type code:(NSString *)code msg:(NSString *) msg commonDatas:(NSDictionary *)commonDatas extDatas:(NSDictionary *)extDatas;

- (void)performanceWithType:(NSString *)type commonDatas:(NSDictionary *)commonDatas properties:(NSDictionary *)properties stages:(NSDictionary *)stages events:(NSDictionary *)events;

- (void)behaviorWithType:(NSString *)type commonDatas:(NSDictionary *)commonDatas extDatas:(NSDictionary *)extDatas  currentVC:(id)currentVC;

- (void)behaviorWithData:(NSDictionary *)data contentView:(id)contentView callback:(RVKJsApiResponseCallbackBlock)callback;

@end




@protocol RVALoggerDelegate <NSObject>
@optional
/**
 * 异常类的数据通知
 * @param type 异常类型，如appx的异常、前端开发者代码异常、jsapi异常、容器异常
 * @param code 错误code
 * @param msg 错误概述
 * @param extDatas 扩展参数，根据不同类型进行扩展。比如url、jsapi的req请求、errorstack
 */
- (void)errorWithType:(NSString *)type code:(NSString *)code msg:(NSString *) msg commonDatas:(NSDictionary *)commonDatas extDatas:(NSDictionary *)extDatas;

/**
 * 性能模型的数据通知
 * @param type 性能类型，如启动、页面
 * @param commonDatas 通用的数据参数
 * @param properties 属性
 * @param stages 模型标准的时间点
 * @param events 额外的事件时间点
 */
- (void)performanceWithType:(NSString *)type commonDatas:(NSDictionary *)commonDatas properties:(NSDictionary *)properties stages:(NSDictionary *)stages events:(NSDictionary *)events;


/**
 * 行为类的数据通知
 * @param type 行为类型，如页面、点击、曝光、启动、前后台
 * @param commonDatas 通用的数据参数，由前端传入
 * @param extDatas 扩展的数据参数
 */
- (void)behaviorWithType:(NSString *)type commonDatas:(NSDictionary *)commonDatas extDatas:(NSDictionary *)extDatas  currentVC:(id)currentVC;

- (void)behaviorWithData:(NSDictionary *)data contentView:(id)contentView callback:(RVKJsApiResponseCallbackBlock)callback;

@end

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    RVALogger *RVALoggerGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus

