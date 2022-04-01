//
//  WMLIconfontProtocol.h
//  AppContainer
//
//  Created by Jason Lee on 2018/7/30.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol WMLIconfontProtocol <NSObject>

@required

- (UIFont *)fontWithSize:(NSInteger)fontSize;

- (NSString *)unicodeWithName:(NSString *)name;

@end
