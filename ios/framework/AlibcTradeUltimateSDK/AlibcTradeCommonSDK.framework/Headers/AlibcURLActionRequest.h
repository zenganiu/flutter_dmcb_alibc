//
//  AlibcURLActionRequest.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/11/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlibcURLActionRequest : NSObject

@property (nullable, nonatomic, strong, readonly) NSURL *url;

/**
 *    使用者所在源controller
 */
@property (nullable, nonatomic, strong) UIViewController *sourceController;

/**
 *    不适合放在url里的本地参数
 */
@property (nullable, nonatomic, strong) NSDictionary *params;


- (instancetype)initWithURL:(NSURL *)url params:(nullable id)params NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
