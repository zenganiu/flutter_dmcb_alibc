//
//  WMLAppPageContainerScrollView.h
//  AppContainer
//
//  Created by AllenHan on 2018/12/26.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface WMLAppPageContainerScrollView : UIScrollView

@property (nonatomic, weak) UIScrollView *otherScrollView;
@property (nonatomic, assign) BOOL canScroll;
@property (nonatomic, assign) BOOL hadPullDown;

@end

