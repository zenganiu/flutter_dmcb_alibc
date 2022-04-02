//
//  TRVVideoFullScreenViewController.h
//  Media
//
//  Created by 岚遥 on 2019/7/25.
//  Copyright © 2019 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const TRVTurnVideoScreenOrientationNotification;

@interface TRVVideoFullScreenViewController : UIViewController


@property (nonatomic, assign) UIInterfaceOrientation interfaceOrientation;

@property (nonatomic, assign) BOOL isVideoAssetvertical;

@end

NS_ASSUME_NONNULL_END
