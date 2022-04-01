//
//  TRVAppContainerProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/6/4.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRVDefines.h"

@protocol TRVAppContainerProtocol <NSObject>

@property (nonatomic, assign) WMLAppInfoViewFollowStyle followStyle;

@property (nonatomic, strong) NSDictionary *extraMenuData;

@end
