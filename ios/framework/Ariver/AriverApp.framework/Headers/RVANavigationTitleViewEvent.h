//
//  RVATitleViewEvent.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import "RVANavigationTitleViewProtocol.h"

@interface RVANavigationTitleViewEvent : RVKEvent

@property(nonatomic, strong) id<RVANavigationTitleViewProtocol>  titleView;
@property(nonatomic, copy) NSString                             *mainTitle;
@property(nonatomic, copy) NSString                             *subtitle;

+ (instancetype)allEvent:(id<RVANavigationTitleViewProtocol>)titleView;

+ (instancetype)createBeforeEvent;

+ (instancetype)createAfterEvent:(id<RVANavigationTitleViewProtocol>)titleView;

+ (instancetype)setTitleEvent:(NSString *)mainTitle subtitle:(NSString *)subtitle;

+ (instancetype)titleClickEvent:(id<RVANavigationTitleViewProtocol>)titleView;

+ (instancetype)subtitleClickEvent:(id<RVANavigationTitleViewProtocol>)titleView;

+ (instancetype)rightIconClickEvent:(id<RVANavigationTitleViewProtocol>)titleView;


@end
