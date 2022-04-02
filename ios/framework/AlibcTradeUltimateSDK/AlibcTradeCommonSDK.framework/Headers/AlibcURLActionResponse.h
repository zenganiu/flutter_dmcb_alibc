//
//  AlibcURLActionResponse.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/11/30.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AlibcURLActionResponseType) {
    AlibcURLActionResponseTypeNone = 1, /**< 告诉容器不用做处理。（如触发了某个事件，但不需页面跳转） */
    AlibcURLActionResponseTypeViewController, /**< 返回ViewController */
    AlibcURLActionResponseTypeObject, /**< 返回一个用户自定义的对象 */
//    AlibcURLActionResponseTypeAsync, /**< 异步response */
};

NS_ASSUME_NONNULL_BEGIN

@interface AlibcURLActionResponse : NSObject

/**
 *    若responseType=TBURLActionResponseTypeViewController，那么需返回viewController
 */
@property (nullable, nonatomic, strong) __kindof UIViewController *viewController;

/**
 *    若responseType=TBURLActionResponseTypeObject，那么需返回object
 */
@property (nullable, nonatomic, strong) id result;

/**
 *    响应类型
 */
@property (nonatomic, assign) AlibcURLActionResponseType responseType;


- (instancetype)initAsNone;
- (instancetype)initWithViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
