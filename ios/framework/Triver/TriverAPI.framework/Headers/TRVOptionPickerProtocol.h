//
//  TRVOptionPickerProtocol.h
//  API
//
//  Created by 岚遥 on 2020/4/7.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol TRVOptionPickerProtocol;

NS_ASSUME_NONNULL_BEGIN

@protocol TRVOptionPickerDelegate <NSObject>

/**
 * 成功选中
 */
- (void)optionsPickerDidClickConfirmButton:(id<TRVOptionPickerProtocol>)optionsPicker;

/**
 * 点击取消按钮
 */
- (void)optionsPickerDidClickCancelButton:(id<TRVOptionPickerProtocol>)optionsPicker;

@end

@protocol TRVOptionPickerProtocol <NSObject>

@property (nonatomic, assign) NSInteger selectedOneIndex;
@property (nonatomic, assign) NSInteger selectedTwoIndex;
@property (nonatomic, strong) NSString *selectedOneOption;
@property (nonatomic, strong) NSString *selectedTwoOption;
@property (nonatomic, weak) id<TRVOptionPickerDelegate> delegate;
/**
 * 配置 optionsPicker
 */
- (void)setupSelectedOneIndex:(NSInteger)oneIndex
             selectedTwoIndex:(NSInteger)twoIndex
                   optionsOne:(NSArray *)optionsOne
                   optionsTwo:(NSArray *)optionsTwo
                        title:(NSString *)title
                  cancelTitle:(NSString *)cancelTitle
                 confirmTitle:(NSString *)confirmTitle;
/**
 * 刷新 optionsPicker
 */
- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
