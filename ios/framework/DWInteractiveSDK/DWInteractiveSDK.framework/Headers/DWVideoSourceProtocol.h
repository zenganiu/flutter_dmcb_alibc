//
//  DWVideoSourceProtocol.h
//  DWInteractiveSDK
//
//  Created by wentao.wwt on 2017/2/17.
//  Copyright © 2017年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DWVideoSourceProtocol <NSObject>

- (void)getVideoInfoWithVideoId:(NSString*)videoId complete:(void(^)(BOOL,NSString*,NSDictionary*))complete;

@end

