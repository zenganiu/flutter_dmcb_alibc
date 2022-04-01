//
//  FontUtils.h
//  JDY
//
//  Created by 连墨 on 16/7/25.
//  Copyright © 2016年 Tmall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface AliTRVASFontUtils : NSObject

//确保这个返回值不会是空的
+ (UIFont *)fontWithName:(NSString *)fontName size:(CGFloat)fontSize;

@end
