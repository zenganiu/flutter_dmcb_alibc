//
//  TRVDatePickerProtocol.h
//  API
//
//  Created by 岚遥 on 2020/4/7.
//  Copyright © 2020 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol TRVDatePickerProtocol;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TRVDatePickerMode) {
    TRVDatePickerModeTime,          // HH:mm
    TRVDatePickerModeDate,          // yyyy-MM-dd
    TRVDatePickerModeDateAndTime,   // yyyy-MM-dd HH:mm
    TRVDatePickerModeYearAndMonth,  // yyyy-MM
    TRVDatePickerModeYear           // yyyy
};

@protocol TRVDatePickerDelegate <NSObject>

/**
 * 成功选中
 */
- (void)datePickerDidClickConfirmButton:(id<TRVDatePickerProtocol>)datePicker;

/**
 * 点击取消按钮
 */
- (void)datePickerDidClickCancelButton:(id<TRVDatePickerProtocol>)datePicker;

@end

@protocol TRVDatePickerProtocol <NSObject>

@property (nonatomic) TRVDatePickerMode datePickerMode;

@property (nonatomic, strong) NSLocale *locale;   // default is [NSLocale currentLocale]
@property (nonatomic, copy) NSCalendar *calendar; // default is [NSLocale localeWithLocaleIdentifier:@"Chinese"].
@property (nonatomic, strong) NSTimeZone *timeZone; // default is nil. use current time zone or time zone from calendar

@property (nonatomic, strong) NSDate *date;        // default is current date when picker created. Ignored in countdown timer mode. for that mode, picker starts at 0:00
@property (nonatomic, strong) NSDate *minimumDate; // default is 2000-1-1
@property (nonatomic, strong) NSDate *maximumDate; // default is 2050-12-31

@property (nonatomic) NSTimeInterval countDownDuration; // for UIDatePickerModeCountDownTimer, ignored otherwise. default is 0.0. limit is 23:59 (86,399 seconds). value being set is div 60 (drops remaining seconds).
@property (nonatomic) NSInteger      minuteInterval;    // display minutes wheel with interval. interval must be evenly divided into 60. default is 1. min is 1, max is 30

@property (nonatomic, strong) NSDictionary<NSNumber *, NSString *> *datePickerModeWithFormatDic;

@property (nonatomic, weak) id<TRVDatePickerDelegate> delegate;

@property (nonatomic, strong) NSDateComponents *startComponents; // 开始日期
@property (nonatomic, strong) NSDateComponents *endComponents; // 结束日期
@property (nonatomic, strong) NSDateComponents *currentComponents; // 当前日期

@property (nonatomic, strong) NSMutableDictionary<NSNumber *, NSValue *> *dateComponentsRangeDict; // 存储了 calendarUnit 所对应的时间范围 NSRange
@property (nonatomic, strong) NSArray *componentModeArray;  // 存储当前的日期格式

@property (nonatomic, strong) NSDateComponents *defaultStartComponents; // 默认开始日期
@property (nonatomic, strong) NSDateComponents *defaultEndComponents; // 默认结束日期

- (void)setDate:(NSDate *)date animated:(BOOL)animated; // if animated is YES, animate the wheels of time to display the new date

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
