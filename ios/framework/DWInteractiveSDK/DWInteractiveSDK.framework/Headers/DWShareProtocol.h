//
//  DWShareProtocol.h
//  DWInteractiveSDK
//
//  Created by wentao.wwt on 2017/3/3.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol DWShareProtocol<NSObject>

- (void)shareWithurl:(NSString*)shareUrl
              imgUrl:(NSString*)imgurl
               title:(NSString*)title;

- (void)shareWithurl:(NSString*)shareUrl
              imgUrl:(NSString*)imgurl
               title:(NSString*)title
          businessId:(NSString*)businessId
         description:(NSString*)des;

- (void)shareWithurl:(NSString*)shareUrl
              imgUrl:(NSString*)imgurl
               title:(NSString*)title
          businessId:(NSString*)businessId
         description:(NSString*)des
            delegate:(id)delegate;

@end
