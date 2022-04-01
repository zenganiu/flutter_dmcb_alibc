//
//  RVAServicePrivateDefines.h
//  RVAService
//
//  Created by chenwenhong on 15/8/25.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#ifndef RVAService_RVAServicePrivateDefines_h
#define RVAService_RVAServicePrivateDefines_h

#define kRVADefaultSDKVersion                           @"1.0.0.0"

#define kRVAService_ChannelId                    @"ChannelId"

// jsapi
#define kRVAError_JSApi_Error                    @"error"
#define kRVAError_JSApi_ErrorMessage             @"errorMessage"
#define kRVASuccess_JSApi_Success                @"success"

#define kRVAErrorCode_JSApi_InvalidApi           1
#define kRVAErrorCode_JSApi_InvalidParams        2
#define kRVAErrorCode_JSApi_UnknowError          3
#define KRVAErrorCode_JSApi_Cancel               11

// session expando
#define kRVASessionExpando_AssociateRVASession    @"kRVASessionExpando_AssociateRVASession"

// scene expando
#define kRVASceneOptionsParam                    @"kNBSceneOptionsParam"


//*******************************Scene Events***************************//
// toolbar Menu
#define kRVAPrivateEvent_Scene_ToolbarMenu_Show       @"private.scene.toolbarMenu.show"
#define kRVAPrivateEvent_Scene_ToolbarMenu_Hide       @"private.scene.toolbarMenu.hide"

#endif
