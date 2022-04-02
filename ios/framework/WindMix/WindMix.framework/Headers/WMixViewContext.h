//
//  WMixViewContext.h
//  WindMix
//
//  Created by lianyu on 2020/12/8.
//  Copyright © 2020 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 同层渲染组件的上下文信息。
 */
@interface WMixViewContext : NSObject

/**
 当前同层渲染组件关联到的 UIViewController。
 */
@property (nonatomic, weak, nullable) UIViewController * viewController;

@end
