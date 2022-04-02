//
//  WMLActionSheetSection.h
//  JDYUIControls
//
//  Created by 连墨 on 2018/4/11.
//  Copyright © 2018年 连墨. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AliTRVActionSheetCommon.h"
#import "AliTRVActionSheet.h"

typedef NS_ENUM(NSUInteger, AliTRVActionSheetButtonStyle) {
    AliTRVActionSheetButtonStyleDefault,
    AliTRVActionSheetButtonStyleCancel,
    AliTRVActionSheetButtonStyleDestructive,
    AliTRVActionSheetButtonStyleIconText
};

typedef NS_ENUM(NSUInteger, AliTRVActionSheetType) {
    AliTRVActionSheetTypeButtons = 0,
    AliTRVActionSheetTypeContentView = 1
};

@interface AliTRVActionSheetSection : UIView
@property (nonatomic, strong) NSNumber *tbDarkMode_needAutoColorInvert;
@property(nonatomic, assign) int secionHeightLimit;
@property(nonatomic, weak) AliTRVActionSheet * _Nullable hostingSheet;
@property(nonatomic, assign) AliTRVActionSheetType acType;
@property (nonatomic, assign) NSUInteger index;
@property (nonatomic, copy) void (^ _Nullable buttonPressedBlock)(NSIndexPath *_Nonnull indexPath);
@property (nonatomic, strong, readonly) UILabel * _Nullable titleLabel;
@property (nonatomic, strong) NSNumber * _Nullable custmizedCornerRadius;
@property (nonatomic, strong) NSNumber * _Nullable custmizedButtonHeight;
@property (nonatomic, strong) id _Nullable sectionInfo;

//如果是 text button生成的section，这些button在这个数组里
@property (nonatomic, strong, readonly) NSArray * _Nullable buttons;

/*
 如果是用contentView生成的section，contentView保存在这个变量
 @Note contentView的宽度会被拉伸，高度保持不变
 */
@property (nonatomic, strong, readonly) UIView * _Nullable contentView;

/**
 快捷生成一个‘取消’section
 */
+ (instancetype _Nonnull)cancelSection;

//icon以UIImage的形式传入
+ (instancetype _Nullable)sectionWithTitle:(NSString *_Nullable)title buttonTitles:(NSArray *_Nullable)buttonTitles iconImages:(NSArray* _Nullable)icons buttonStyle:(AliTRVActionSheetButtonStyle)buttonStyle;

//icon以http url字符串的形式传入
+ (instancetype _Nullable)sectionWithTitle:(NSString * _Nullable)title buttonTitles:(NSArray *_Nonnull)buttonTitles iconURLs:(NSArray* _Nullable)iconURLs buttonStyle:(AliTRVActionSheetButtonStyle)buttonStyle;
/**
 Initializes the section with buttons.
 @param title 整个section的标题. (可选)
 @param buttonTitles 按键title的数组.
 @param iconImages 图标数组 (UIImage) 如果buttonStyle是 WMLActionSheetButtonStyleIconText，这里传入UIImage的数字
 @param iconURLs 如果buttonStyle是 WMLActionSheetButtonStyleIconText，这里传入图片的url. 注意iconImages优先于iconImages
 @param buttonStyle 按键样式
 */
- (instancetype _Nonnull )initWithTitle:(NSString *_Nullable)title buttonTitles:(NSArray *_Nonnull)buttonTitles iconImages:(NSArray* _Nullable)iconImages iconURLs:(NSArray* _Nullable)iconURLs buttonStyle:(AliTRVActionSheetButtonStyle)buttonStyle;


+ (instancetype _Nonnull )sectionWithTitle:(NSString *_Nullable)title contentView:(UIView *_Nonnull)contentView;

/**
 Initializes the section with a custom content view.
 @param title 整个section的标题. (可选)
 @param contentView 自定义的UIView
 */
- (instancetype _Nonnull)initWithTitle:(NSString *_Nullable)title contentView:(UIView *_Nonnull)contentView;


- (void)setButtonStyle:(AliTRVActionSheetButtonStyle)buttonStyle forButtonAtIndex:(NSUInteger)index;

- (CGRect)layoutForWidth:(CGFloat)width;

- (void)setUpForContinuous:(BOOL)continuous;

@end
