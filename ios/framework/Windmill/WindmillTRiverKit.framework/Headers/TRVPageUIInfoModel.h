//
//  TRVPageUIInfoModel.h
//  AppContainer
//
//  Created by AllenHan on 2019/3/28.
//  Copyright © 2019年 AllenHan. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TRVAppInfoModel.h"
#import "TRVWindowInfoModel.h"
#import "TRVEnterInfoModel.h"

@interface TRVPageUIInfoModel : NSObject
@property (nonatomic, strong) TRVAppInfoModel *appInfo;
@property (nonatomic, strong) TRVEnterInfoModel *enterInfo;
@property (nonatomic, strong) TRVWindowInfoModel *windowInfo;
@property (nonatomic, strong) TRVTabBarInfoModel *tabBarInfo;
@end

