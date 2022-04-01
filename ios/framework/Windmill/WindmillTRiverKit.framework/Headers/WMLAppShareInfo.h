////
////  WMLAppShareInfo.h
////  AliWindmill
////
////  Created by ali_liuhui on 2019/1/27.
////
//
//#import <Foundation/Foundation.h>
//
//typedef NS_ENUM(NSUInteger, WMLAppShareType) {
//    WMLAppShareTypeContainer,
//    WMLAppShareTypeAPI,
//};
//
//@class TRVBaseViewController;
//@interface WMLAppShareInfo : NSObject
//
///**
// 分享的类型
// type为WMLAppShareTypeContainer，为框架分享，小程序开发者可以通过前端API
// 'my.setShareAppMessage' 设置当前的框架分享参数；
//
// type为WMLAppShareTypeAPI时，为API分享，系小程序开发者通过前端API 'my.shareTinyAppMsg'
// 主动呼起的分享。
//
// */
//@property (nonatomic, assign) WMLAppShareType type;
//
///**
// 分享标题
// */
//@property (nonatomic, readonly) NSString *title;
//
///**
// 分享内容
// */
//@property (nonatomic, readonly) NSString *desc;
//
///**
// 分享的图片URL，前端透入，默认取appLogo
// */
//@property (nonatomic, readonly) NSString *imageUrl;
//
///**
// 分享的url，该参数由前端传入，如果没有传入则使用默认值（默认值是根据小程序当前页面生成）
// */
//@property (nonatomic, readonly) NSString *url;
//
///**
// 由小程序开发者通过my.setShareAppMessage，type为0时传入，可能为nil
// */
//@property (nonatomic, copy) NSDictionary *pageShareInfo;
//
///**
// 由小程序开发者通过my.setShareAppMessage，type为1时传入，可能为nil
// */
//@property (nonatomic, copy) NSDictionary *appPageShareInfo;
//
///**
//  小程序开发者通过my.shareTinyAppMsg主动呼起分享时传入的参数，可能为nil
// */
//@property (nonatomic, copy) NSDictionary *customShareInfo;
//
///**
// 分享事件发生所在的页面
// */
//@property (nonatomic, weak) TRVBaseViewController *pageVC;
//
//
//@end
//
