//
//  WMLAppCustomPageShareInfoModel.h
//  AppContainer
//
//  Created by AllenHan on 2018/4/10.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface WMLAppCustomPageShareInfoModel : NSObject

@property (nonatomic, copy) NSString *imageUrl; // 分享的图片URL
@property (nonatomic, copy) NSString *desc; // 分享通用描述文案
@property (nonatomic, copy) NSString *appDesc; // 小程序描述
@property (nonatomic, copy) NSString *title; //分享的标题
@property (nonatomic, copy) NSString *url; //分享的地址
@property (nonatomic, strong) NSArray *targets; //分享的目标地址
@property (nonatomic, copy) NSString *templateId; //分享使用的模板ID（目前手淘有多套模板，非手淘可不填）
@property (nonatomic, copy) NSString *path; //前端透传的path参数，用来传入URL或者页面的相对路径
@property (nonatomic, strong) NSDictionary *customParams; //自定义参数，用于存放mini app信息
@property (nonatomic, strong) NSDictionary *extraParams;  //自定义参数，用于存放前端分享透传的自定义参数。可以通过"setAppShareInfo"传入，也可以通过"doShare"传入
@property (nonatomic, strong) UIViewController *parent;

@end
