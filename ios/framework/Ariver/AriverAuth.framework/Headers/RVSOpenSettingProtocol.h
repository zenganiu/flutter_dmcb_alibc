//
//  TRVSOpenSettingProtocol.h
//  AriverAuth
//
//  Created by AllenHan on 2019/5/1.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AriverKernel/RVKJsApi.h>

@protocol RVSOpenSettingProtocol <NSObject>
@required
- (void)openAuthSettingPage:(UIViewController *)currentPage
                     params:(NSDictionary *)params
                   callback:(RVKJsApiResponseCallbackBlock)callback;

@end
