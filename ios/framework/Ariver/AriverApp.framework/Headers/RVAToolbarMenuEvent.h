//
//  RVAToolbarMenuEvent.h
//  AriverApp
//
//  Created by chenwenhong on 15/9/9.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import "RVAToolbarMenuProtocol.h"

@interface RVAToolbarMenuEvent : RVKEvent

@property(nonatomic, strong) id<RVAToolbarMenuProtocol> toolbarMenu;
@property(nonatomic, readonly, copy) NSString *selectedRowTag;
@property(nonatomic, readonly, copy) NSString *selectedTag;

+ (instancetype)allEvent:(id<RVAToolbarMenuProtocol>)toolbarMenu;

+ (instancetype)createBeforeEvent:(id<RVAToolbarMenuProtocol>)toolbarMenu;

+ (instancetype)createAfterEvent:(id<RVAToolbarMenuProtocol>)toolbarMenu;

+ (instancetype)selectEvent:(id<RVAToolbarMenuProtocol>)toolbarMenu selectedTag:(NSString *)selectedTag selectedRowTag:(NSString *)selectedRowTag;

+ (instancetype)selectCancelEvent:(id<RVAToolbarMenuProtocol>)toolbarMenu selectedTag:(NSString *)selectedTag selectedRowTag:(NSString *)selectedRowTag;

@end
