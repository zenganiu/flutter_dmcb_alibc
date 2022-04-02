//
//  RVKScenePreRenderProtocol.h
//  NebulaKernel
//
//  Created by theone on 2018/9/12.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RVEvent4PreRender <NSObject>
- (RVKScene *)createPreRenderSceneWithSceneParam:(RVKSceneParam *)sceneParam
                         data:(NSDictionary *)data;
@end
