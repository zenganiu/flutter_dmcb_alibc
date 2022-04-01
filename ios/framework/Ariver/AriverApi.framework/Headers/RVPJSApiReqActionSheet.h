//
//  RVPJSApiReqActionSheet.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqActionSheet : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *title; // 标题
@property (nonatomic, strong, nonnull) NSArray *btns; // 一组按钮，item类型是string
@property (nonatomic, strong) NSString *cancelBtn; // 设置取消按钮及文字
@property (nonatomic, strong) NSNumber *destructiveBtnIndex; // 指定按钮的索引号，从0开始，使用场景：需要删除或清除数据等类似场景，默认红色

/**
 index: NSNumber : 需要飘红的选项的索引，从0开始
 type:  NSString : 飘红类型，支持 none（无红点）/ point（纯红点） / num（数字红点）/ text（文案红点）/ more（...）
 text:  NSString : 自定义飘红文案：1、type为none/point/more时本文案可不填  2、type为num时本文案为小数或<=0均不显示, >100 显示"..."
 */
@property (nonatomic, strong) NSArray *badges; // 需飘红选项的数组


@end

NS_ASSUME_NONNULL_END
