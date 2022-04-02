//
//  RVKView.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKKernel.h"
#import <UIKit/UIKit.h>

@class RVKViewParam;
@class RVKPage;
@class RVKScene;
@class RVKContentView;

//View类：见名知意，代表一个可视view的抽象类，通常这个类，拥有一个RVKWebView。
@interface RVKView : RVKKernel

@property(nonatomic, readonly, strong) RVKPage *page;

- (RVKViewParam *)createParam;

/**
 *  @brief 返回view对象
 *
 *  @date 2014-08-08
 *
 *  @return 返回view
 */
- (RVKContentView *)contentView;

/**
 *  @brief 给定一个viewParam参数，创建一个View对象，该View对象包含一个Page对象
 *
 *  @date 2014-08-08
 *
 *  @param viewParam 要创建所需要的参数，不能为nil
 *
 *  @return 返回View对象
 */
+ (instancetype)viewWithViewParam:(RVKViewParam *)viewParam parentObject:(RVKKernel *)parentObject;


/**
 移除WK通信brige
 */
- (void)removeMessageHandler:(NSArray<NSString *> *)messageNames;

//调用私有方法同步cookie
+ (void)saveCookieForStorage:(NSHTTPCookieStorage *)storage;

// 获取 processPool
+ (WKProcessPool *)defaultProcessPool;

@end


@interface RVKViewParam : NSObject

@property(nonatomic, strong) Class          contentViewCls;
@property(nonatomic, assign) CGRect         frame;
@property(nonatomic, copy) NSString         *url;
@property(nonatomic, strong) NSDictionary   *expandParams;

@end

