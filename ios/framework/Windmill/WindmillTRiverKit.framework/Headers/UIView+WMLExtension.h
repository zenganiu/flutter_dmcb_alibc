//
//  UIView+WMLExtension.h
//  Windmill-Bridge-Weaver
//
//  Created by ali_liuhui on 2018/9/2.
//

#import <UIKit/UIKit.h>

@interface UIView (WMLExtension)

/**
 * Shortcut for frame.origin.x.
 *
 * Sets frame.origin.x = left
 */
@property (nonatomic) CGFloat wml_left;

/**
 * Shortcut for frame.origin.y
 *
 * Sets frame.origin.y = top
 */
@property (nonatomic) CGFloat wml_top;

/**
 * Shortcut for frame.origin.x + frame.size.width
 *
 * Sets frame.origin.x = right - frame.size.width
 */
@property (nonatomic) CGFloat wml_right;

/**
 * Shortcut for frame.origin.y + frame.size.height
 *
 * Sets frame.origin.y = bottom - frame.size.height
 */
@property (nonatomic) CGFloat wml_bottom;

/**
 * Shortcut for frame.size.width
 *
 * Sets frame.size.width = width
 */
@property (nonatomic) CGFloat wml_width;

/**
 * Shortcut for frame.size.height
 *
 * Sets frame.size.height = height
 */
@property (nonatomic) CGFloat wml_height;

/**
 * Shortcut for frame.size.height
 *
 * Sets frame.origin.x = x
 */
@property (nonatomic) CGFloat wml_x;

/**
 * Shortcut for frame.size.height
 *
 * Sets frame.origin.y = y
 */
@property (nonatomic) CGFloat wml_y;
/**
 * Shortcut for center.x
 *
 * Sets center.x = centerX
 */
@property (nonatomic) CGFloat wml_centerX;

/**
 * Shortcut for center.y
 *
 * Sets center.y = centerY
 */
@property (nonatomic) CGFloat wml_centerY;

/**
 * Return the x coordinate on the screen.
 */
@property (nonatomic, readonly) CGFloat wml_ttScreenX;

/**
 * Return the y coordinate on the screen.
 */
@property (nonatomic, readonly) CGFloat wml_ttScreenY;

/**
 * Return the x coordinate on the screen, taking into account scroll views.
 */
@property (nonatomic, readonly) CGFloat wml_screenViewX;

/**
 * Return the y coordinate on the screen, taking into account scroll views.
 */
@property (nonatomic, readonly) CGFloat wml_screenViewY;

/**
 * Return the view frame on the screen, taking into account scroll views.
 */
@property (nonatomic, readonly) CGRect wml_screenFrame;

/**
 * Shortcut for frame.origin
 */
@property (nonatomic) CGPoint wml_origin;

/**
 * Shortcut for frame.size
 */
@property (nonatomic) CGSize wml_size;


/**
 * Removes all subviews.
 */
- (void)wml_removeAllSubviews;

/**
 * Calculates the offset of this view from another view in screen coordinates.
 *
 * otherView should be a parent view of this view.
 */
- (CGPoint)wml_offsetFromView:(UIView*)otherView;


/**
 * The view controller whose view contains this view.
 */
- (UIViewController*)wml_viewController;


- (void)wml_setContentMode:(NSString *)cntMode;

@end
