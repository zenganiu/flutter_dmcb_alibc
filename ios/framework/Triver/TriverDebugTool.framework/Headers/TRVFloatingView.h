//
//  TRVFloatingView.h

#import <UIKit/UIKit.h>

@class TRVFloatingView;
@protocol TRVFloatingViewDelegate <NSObject>

@optional

/// @brief 悬浮窗点击回调
- (void)didTabFloatingView:(TRVFloatingView *)floatingView;

@end;

@interface TRVFloatingView : UIView

+ (TRVFloatingView *)showFloatingInView:(UIView *)superView delegate:(id<TRVFloatingViewDelegate>)delegate;

+ (void)hideFloatingInView:(UIView *)superView;

@end
