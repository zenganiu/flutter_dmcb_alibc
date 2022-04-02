//
//  RVKViewDelegate.h
//  AriverKernel
//
//  Created by hua.lu on 2019/3/25.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVKViewDelegate_h
#define RVKViewDelegate_h

// 代理 RVKView 的创建，按照设计是由 AriverEgine 来实现
@protocol RVKViewDelegate <NSObject>

@required
- (RVKView *)createViewWithSceneParam:(RVKSceneParam *)sceneParam parentObject:(RVKKernel *)parentObject;

@end


#endif /* RVKViewDelegate_h */
