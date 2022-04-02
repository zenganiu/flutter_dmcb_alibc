//
//  RVAService+RVAPrivate.h
//  AriverApp
//
//  Created by chenwenhong on 15/10/22.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <AriverApp/AriverApp.h>

@interface RVAService (RVAPrivate)

- (id<RVKViewControllerProtocol>)createRVAViewController:(NSDictionary *)params
                                      currentPsdSession:(RVKSession *)currentPsdSession
                                        currentPsdScene:(RVKScene *)currentPsdScene;

@end
