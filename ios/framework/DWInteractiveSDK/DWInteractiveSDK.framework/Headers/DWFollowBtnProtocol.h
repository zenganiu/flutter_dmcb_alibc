//
//  DWFollowBtnProtocol.h
//  DWInteractiveSDK
//
//  Created by wentao.wwt on 2017/2/23.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#ifndef DWFollowBtnProtocol_h
#define DWFollowBtnProtocol_h

#import <UIKit/UIKit.h>


typedef void (^DWFollowBtnOprationBlock) (BOOL isSuccess, BOOL isFollow);

@protocol DWFollowBtnProtocol <NSObject>

- (UIButton*)getFollowBtnWithAccountId:(NSString*)accountId
                             originBiz:(NSString*)originBiz
                            originFlag:(NSString*)originFlag
                        originOpration:(DWFollowBtnOprationBlock)block;


- (void)addFollowWithAccountId:(NSString*)accountId
                     originBiz:(NSString*)originBiz
                    originFlag:(NSString*)originFlag
                originOpration:(DWFollowBtnOprationBlock)block;

@end


#endif /* DWFollowBtnProtocol_h */
