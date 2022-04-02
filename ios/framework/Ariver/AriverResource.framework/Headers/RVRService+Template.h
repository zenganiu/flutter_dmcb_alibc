//
//  NebulaStartApplicationHandler+TemplateApp.h
//  NebulaAppBiz
//
//  Created by 百喻 on 2018/12/20.
//  Copyright © 2018 Alipay. All rights reserved.
//
#import "RVRService.h"


@interface RVRService (TemplateApp)
- (void)preHandleTemplateApp:(RVRApp *)app readyToLaunch:(BOOL)isReadyToLaunch;
@end

