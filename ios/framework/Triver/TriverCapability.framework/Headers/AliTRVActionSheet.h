//
//  AliTRVActionSheet.h
//  AliTRVActionSheet
//  Created by 连墨 on 2018/4/11.
//  Copyright © 2018年 连墨. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "AliTRVActionSheetCommon.h"
#import <UIKit/UIKit.h>

@class AliTRVActionSheet;
@protocol AliTRVActionSheetDelegate <NSObject>

@optional
- (void)trv_willPresentActionSheet:(AliTRVActionSheet *_Nonnull)actionSheet;
- (void)trv_didPresentActionSheet:(AliTRVActionSheet *_Nonnull)actionSheet;
- (void)trv_actionSheet:(AliTRVActionSheet *_Nonnull)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)trv_actionSheet:(AliTRVActionSheet *_Nonnull)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex;
- (BOOL)trv_shouldAutoCloseInActionSheet:(AliTRVActionSheet *_Nonnull)actionSheet;
- (void)trv_actionSheet:(AliTRVActionSheet *_Nonnull)actionSheet clickedButtonAtIndexPath:(NSIndexPath *_Nonnull)indexPath;
- (void)trv_actionSheet:(AliTRVActionSheet *_Nonnull)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
@end

@interface AliTRVActionSheet : UIView
//这个参数决定表单是否有位置改变动画(默认appearDirectly=NO，从底部滑出来），当appearDirectly=YES，省去位置改变动画
@property(nonatomic, assign) BOOL appearDirectly;

@property (nonatomic, strong, readonly) NSArray * _Nullable sections;

+ (int)suggestedContentViewWidth:(UIView* _Nonnull)targetView withEdgeInset:(UIEdgeInsets)insets;

- (instancetype _Nonnull )initWithTitle:(nullable NSString *)title delegate:(nullable id<AliTRVActionSheetDelegate>)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle otherButtonTitles:(nullable NSString *)otherButtonTitles, ...;

- (instancetype _Nonnull )initWithTitle:(nullable NSString *)title delegate:(nullable id<AliTRVActionSheetDelegate>)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle otherButtonTitleList:(nullable NSArray *)buttonTitlesArray;

- (nullable NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;


//以delegate的方式获知 button被点击的事件，以及表单生命周期的事件
@property (nonatomic, weak) id  <AliTRVActionSheetDelegate> _Nullable delegate;

//以block回调的方式获知 按键 被点击的事件
@property (nonatomic, copy) void (^ _Nullable buttonPressedBlock)(AliTRVActionSheet * _Nonnull actionSheet, NSIndexPath * _Nonnull indexPath);

//用户点击在表单外时的回调，可以用来让表单消失
@property (nonatomic, copy) void (^ _Nullable outsidePressBlock)(AliTRVActionSheet * _Nullable sheet);


//当前表单是否在屏幕上可见
@property (nonatomic, assign, readonly, getter=isVisible) BOOL visible;


// 用来调整表单边距
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 @param sections 包含了所有要显示在表单上的sections，至少包含一个对象
 */
+ (instancetype _Nonnull )actionSheetWithSections:(NSArray *_Nonnull)sections;

/**
 @param sections 包含了所有要显示在表单上的sections，至少包含一个对象
 */
- (instancetype _Nonnull )initWithSections:(NSArray *_Nonnull)sections;

- (void)showInView:(UIView *_Nonnull)view;
- (void)showInView:(UIView *_Nonnull)view animated:(BOOL)animated;


// 让表单消失
- (void)dismissAnimated:(BOOL)animated withButtonIndex:(NSInteger)buttonIndex;
- (void)dismissAnimated:(BOOL)animated withButtonIndexPath:(NSIndexPath *_Nullable)indexPath;

//和UIActionSheet保持一致
// hides alert sheet or popup. use this method when you need to explicitly dismiss the alert.
// it does not need to be called if the user presses on a button
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

//浮层附加在contentView上的高度
+(CGFloat)extraHeightPlus2ContentView;

- (instancetype _Nonnull)initWithTitle:(nullable NSString *)title contentView:(UIView * _Nonnull)contentView delegate:(nullable id<AliTRVActionSheetDelegate>)delegate;
@end
