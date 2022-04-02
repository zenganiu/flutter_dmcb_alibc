//
//  TRVDarkModeProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/11/29.
//  Copyright © 2019 TaoBao. All rights reserved.
//

@protocol TRVDarkModeProtocol <NSObject>

@required
/// Inside方当前App是否是开启DarkMode
- (BOOL)isDarkMode;

/// 返回原始颜色对应的DarkMode颜色
/// @param defaultColor 原始颜色
- (UIColor *)trv_darkModeColorWithDefaultColor:(UIColor *)defaultColor;

@end
