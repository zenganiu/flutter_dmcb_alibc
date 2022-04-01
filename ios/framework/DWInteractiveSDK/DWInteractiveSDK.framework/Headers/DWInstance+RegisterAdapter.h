//
//  DWInstance+RegisterAdapter.h
//  DWInteractiveSDK
//
//  Created by Jyi on 2018/2/5.
//  Copyright © 2018年 alibaba. All rights reserved.
//


#import <DWInteractiveSDK/DWInstance.h>
@interface DWInstance (RegisterAdapter)

#pragma mark - 注册adapter
/**
 * 手淘内不需要注册
 **/
+ (void)registerUserTrackAdapterWithClass:(id)class;

+ (void)registerImgLoaderAdapterWithClass:(id)class;

+ (void)registerNetworkAdapterWithClass:(id)class;

+ (void)registerVideoSourceAdapterWithClass:(id)class;

+ (void)registerFollowBtnAdapterWithClass:(id)class;

+ (void)registerAdd2CardAdapterWithClass:(id)class;

+ (void)registerCellSelectHandlerAdapterWithClass:(id)class;

+ (void)registerEventAdapterWithClass:(id)class;

+ (void)registerShareAdapterWithClass:(id)class;

+ (void)registerLoginStatusAdapterWithClass:(id)class;

+ (void)registerPMesgAdapterWithClass:(id)class;

+ (void)registerComponentName:(NSString*)name withClass:(Class)class;

+ (void)registerLikeServiceAdapterWithClass:(id)class;

+ (void)registerGoodListAdapterWithClass:(id)class;

/**
 *  仅供测试同学跑demo使用
 */
+ (void)registerNewNetworkAdapterWithClass:(id)class;

@end
