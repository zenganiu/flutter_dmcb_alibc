//
//  DWComponent.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/6.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <DWInteractiveSDK/DWInteractiveModel.h>
#import <DWInteractiveSDK/DWUserTrackMgr.h>
#import <DWInteractiveSDK/DWContext.h>
typedef NS_ENUM(NSInteger, DWComponentRenderState)
{
    DWRenderState_None        = 1,        //未开始
    DWRenderState_Rendering   = 2,        //渲染中
    DWRenderState_Success     = 3,        //渲染成功
    DWRenderState_Failure     = 4,        //渲染失败
};

@interface DWComponentWrapView : UIView
@property (nonatomic, strong) DWInteractiveModel* model;
- (void)startAnimation:(BOOL)animated;
- (void)removeFromSuperviewAnimated:(BOOL)animated;
@end

typedef void(^DWComponentRenderFinishBlock)(UIView *view);
@protocol DWComponentProtocol <NSObject>

- (void)renderView;

- (void)refreshComponent:(NSDictionary*)params;

- (BOOL)isRenderFinished;

- (UIView*)getView;

- (void)onShow;

- (void)onHidden;

- (void)onFullScreen;

- (void)onNormalScreen;

@end

@interface DWComponent : UIView<DWComponentProtocol,DWActorProtocol>

@property (nonatomic, strong) DWContext *context;

@property (nonatomic, assign) BOOL portrait;
@property (nonatomic, assign) BOOL staredRender;

@property (nonatomic, assign) CGRect instanceFrame;
@property (nonatomic, strong) DWInteractiveModel* model;
@property (nonatomic, strong) NSDictionary* utParams;
@property (nonatomic, strong) NSDictionary  *outBizData;

@property (nonatomic,   copy) DWComponentRenderFinishBlock finishBlock;
@property (nonatomic, assign) DWComponentRenderState  renderState;

@end








