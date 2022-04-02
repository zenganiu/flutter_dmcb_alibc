//
//  RVKViewEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "RVKEvent.h"

typedef enum {
    RVKAlertPanel,
    RVKConfirmPanel,
    RVKPromptPanel
} RVKPanelType;

@interface RVKViewEvent : RVKEvent

@property(nonatomic, readonly, assign) CGRect newFrame;
@property(nonatomic, strong) WKWebViewConfiguration *wkConfiguration;
@property(nonatomic, assign) RVKPanelType panelType;
@property(nonatomic, copy) NSString *panelTitle;
@property(nonatomic, copy) NSString *injctJs;
@property(nonatomic, copy) NSDictionary *expandParams;
@property(nonatomic, weak) RVKKernel *parentObject;


+ (instancetype)allEvent;

+ (instancetype)createEvent;

+ (instancetype)resizeEvent:(CGRect)newFrame;

+ (instancetype)destroyEvent;

+ (instancetype)configEvent;

+ (instancetype)showPanelEvent;

+ (instancetype)injctJSEvent;

+ (instancetype)reloadFailEvent;
@end
