//
//  RVPJSApiReq4Modal.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqAlert : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *title; // alert框标题
@property (nonatomic, strong) NSString *message; // alert框文本
@property (nonatomic, strong) NSString *button; // 按钮文字

@end

@interface RVPJSApiReqConfirm : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *title; // confirm 框的标题
@property (nonatomic, strong) NSString *message; // confirm 框的内容
@property (nonatomic, strong) NSString *okButton; // 确定按钮文字，默认’确定’
@property (nonatomic, strong) NSString *cancelButton; // 取消按钮文字，默认’取消’

@end

@interface RVPJSApiReqPrompt : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *title; // prompt框标题
@property (nonatomic, strong) NSString *message; // prompt框文本
@property (nonatomic, strong) NSString *okButton; // 确定按钮文字，默认’确定’
@property (nonatomic, strong) NSString *cancelButton; // 取消按钮文字，默认’取消’
@property (nonatomic, strong) NSString *placeholder; // 输入框内的提示文案
@property (nonatomic, strong) NSString *align; // message对齐方式，可用枚举left/center/right

@end

NS_ASSUME_NONNULL_END
