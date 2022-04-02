//
//  RVKPage.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKKernel.h"
#import <UIKit/UIKit.h>

@class RVKPageParam;
@class RVKView;
@class RVKJsBridge;
@class RVKContentView;
@protocol WKNavigationDelegate;
@protocol WKUIDelegate;

//Page类：代指浏览器打开一个页面，所产生的对象，通常一个一次跳转或者刷新产生一个Page。
@interface RVKPage : RVKKernel

@property(nonatomic, readonly, strong) RVKJsBridge *bridge;
@property(nonatomic, strong) NSString *pageUUID;


- (RVKPageParam *)createParam;

/**
 *  @brief 给定一个pageParam参数，创建一个Page对象
 *
 *  @date 2014-08-08
 *
 *  @param pageParam 要创建所需要的参数，不能为nil
 *
 *  @return 返回Page对象
 */
+ (instancetype)pageWithPageParam:(RVKPageParam *)pageParam parentObject:(RVKKernel *)parentObject;

@end

//创建Page所需的参数类
@interface RVKPageParam : NSObject

@property(nonatomic, weak) RVKContentView           *contentView;
@property(nonatomic, weak) id<WKNavigationDelegate> webViewNavigationDelegate4RVKView;
@property(nonatomic, weak) id<WKUIDelegate>         webViewUIDelegate4RVKView;
@property(nonatomic, strong) NSDictionary           *expandParams;

@end

