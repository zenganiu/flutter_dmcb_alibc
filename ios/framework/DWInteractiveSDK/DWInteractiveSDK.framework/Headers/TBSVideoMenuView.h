//
//  TBSVideoMenuView.h
//  DWInteractiveSDK
//
//  Created by Sapphire on 2017/9/13.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TBSVideoMenuActionProtocol <NSObject>
@optional
- (void)shareAction;

- (void)reportAction;

@end

@interface TBSVideoMenuView : UIView

@property (nonatomic, strong) NSArray *sourceData;
@property (nonatomic, weak) id<TBSVideoMenuActionProtocol> actionDelegate;

@end

@interface TBSVideoMenuCell : UITableViewCell

@property (nonatomic, strong) UIImageView *icon;

@property (nonatomic, strong) UILabel *label;

@property (nonatomic, strong) UIView *line;

- (void)bindData:(NSDictionary *)data;

@end
