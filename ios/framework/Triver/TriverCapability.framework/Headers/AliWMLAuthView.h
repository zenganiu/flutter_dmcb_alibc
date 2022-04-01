//
//  AliWMLAuthView.h
//  AliWindmill
//
//  Created by AllenHan on 2018/2/2.
//

#import <UIKit/UIKit.h>

typedef void(^TBWopcAuthActionBlock)(void);

@protocol AliTRVAuthViewProtocol <NSObject>
@optional

/**
 定制授权按钮背景颜色

 @return 描述颜色(CGColor)的数组，支持渐变
 */
- (NSArray<id>*)confirmButtonBackgroundColors;

/**
 定制授权弹窗的父View，不实现该方法时，授权弹窗将在[UIApplication sharedApplication].keyWindow 上展示

 @param vc 当前授权发生所在的ViewController
 @return 授权弹窗的父View
 */
- (UIView *)authViewSuperViewInViewController:(UIViewController *)vc;

@end

@interface AliWMLAuthView : UIView

@property (nonatomic, strong, readonly) UIButton *confirmBtn;

@property (nonatomic, strong) TBWopcAuthActionBlock onAuth;

@property (nonatomic, strong) TBWopcAuthActionBlock onCancel;

@property (nonatomic, strong) NSDictionary *authInfo;

- (instancetype)initWithReferenceView:(UIView *)view;

- (void)setupView:(NSDictionary *)authInfo;

- (void)show;

- (void)dismiss;

@end
