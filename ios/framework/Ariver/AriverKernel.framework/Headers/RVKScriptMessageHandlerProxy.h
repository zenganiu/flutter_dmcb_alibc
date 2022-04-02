//
//  RVKScriptMessageHandlerProxy.h
//  NebulaPoseidon
//
//  Created by theone on 2017/11/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RVKView;

@interface RVKScriptMessageHandlerProxy : NSObject <WKScriptMessageHandler>
@property(nonatomic, weak) RVKView *RVKView;
@end
