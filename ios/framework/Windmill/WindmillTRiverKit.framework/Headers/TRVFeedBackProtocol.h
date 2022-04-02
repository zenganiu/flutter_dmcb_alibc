//
//  TRVFeedBackProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/10.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TRVAppInfoModel.h"

@protocol TRVFeedBackProtocol <NSObject>

@optional
- (void)trv_feedBackWithAppInfo:(TRVAppInfoModel *)appInfo
                   feedBackInfo:(NSDictionary *)feedBackInfo
                         appUrl:(NSString *)appUrl
           sourceViewController:(UIViewController *)sourceVC;

@end
