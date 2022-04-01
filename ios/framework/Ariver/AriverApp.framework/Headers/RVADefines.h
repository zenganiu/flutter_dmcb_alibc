//
//  RVAServiceDefines.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#ifndef RVAService_RVAServiceDefines_h
#define RVAService_RVAServiceDefines_h

#define kRVABundleName                          @"AriverApp.bundle"

// session expando
#define kRVASessionPopData                       @"kNBSessionPopData"
#define kRVASessionResumeParams                  @"kNBSessionResumeParams"
#define kRVASessionOriginalParams                @"kNBSessionOriginalParams"

//*******************************Notification***************************//
#pragma mark - Notification
// 配置信息更新
#define kRVANotif_Configuration_Update               @"kRVANotif_Configuration_Update"
#define kRVANotif_Configuration_Update_Key_Status    @"status"
// app列表状态
typedef NS_ENUM(NSUInteger, RVAConfigurationUpdateStatus) {
    RVAConfigurationUpdateStatus_Updating = 0, // 更新中
    RVAConfigurationUpdateStatus_Success, // 更新成功
    RVAConfigurationUpdateStatus_Fail, // 更新失败
};


//*******************************Function***************************//
#pragma mark - Function

#define RVA_DEFINE_FUNCTION(returnType, var)               \
- (id)var                                                 \
{                                                         \
if (_##var == nil) {                                  \
_##var = [[returnType alloc] init];               \
}                                                     \
return _##var;                                        \
}

#define RVA_ASSERT(condition) \
if (!condition) {\
NSString *reason = [NSString stringWithFormat:@"\n\n***********************************************************\nNebula抛出的断言（Kernel Assert）:\n函数:%s-%d \ncondition=%s\n\n", __FUNCTION__, __LINE__, #condition];\
NSAssert(condition, reason);\
}

#define RVA_ASSERT2(condition, desc) \
if (!condition) {\
NSString *reason = [NSString stringWithFormat:@"\n\n***********************************************************\nNebula抛出的断言（Kernel Assert）:\n函数:%s-%d \ncondition=%s desc=%@\n\n", __FUNCTION__, __LINE__, #condition, desc];\
NSAssert(condition, reason);\
}


#define kRVAWebView_Options                             @"__webview_options__"

//*******************************Options***************************//
#pragma mark - Options

#define kRVAOptions_RVALId                          @"nbl_id"
#define kRVAOptions_RVALId2                         @"appId"
#define kRVAOptions_Url                            @"url"
#define kRVAOptions_DefaultTitle                   @"defaultTitle"
#define kRVAOptions_ShowTitleBar                   @"showTitleBar"
#define kRVAOptions_ShowStatusBar                  @"showStatusBar"
#define kRVAOptions_ShowLoading                    @"showLoading"
#define kRVAOptions_CloseButtonText                @"closeButtonText"
#define kRVAOptions_ReadTitle                      @"readTitle"
#define kRVAOptions_BizScenario                    @"bizScenario"
#define kRVAOptions_BackBehavior                   @"backBehavior"
#define kRVAOptions_PullRefresh                    @"pullRefresh"
#define kRVAOptions_ToolbarMenu                    @"toolbarMenu"
#define kRVAOptions_ShowProgress                   @"showProgress"
#define kRVAOptions_DefaultSubtitle                @"defaultSubtitle"
#define kRVAOptions_BackgroundColor                @"backgroundColor"
#define kRVAOptions_GestureBack                    @"gestureBack"
#define kRVAOptions_CanPullDown                    @"canPullDown"
#define kRVAOptions_ShowOptionMenu                 @"showOptionMenu"
#define kRVAOptions_ShowTitleLoading               @"showTitleLoading"
#define kRVAOptions_ShowDomain                     @"showDomain"
#define kRVAOptions_PushingURLString               @"pushingURLString"
#define kRVAOptions_Transparent                    @"transparent"

#define kRVAOptions_UrlShort                       @"u"
#define kRVAOptions_DefaultTitleShort              @"dt"
#define kRVAOptions_ShowTitleBarShort              @"st"
#define kRVAOptions_ShowStatusBarShort             @"ss"
#define kRVAOptions_ShowLoadingShort               @"sl"
#define kRVAOptions_CloseButtonTextShort           @"cb"
#define kRVAOptions_ReadTitleShort                 @"rt"
#define kRVAOptions_BizScenarioShort               @"bz"
#define kRVAOptions_BackBehaviorShort              @"bb"
#define kRVAOptions_PullRefreshShort               @"pr"
#define kRVAOptions_ToolbarMenuShort               @"tm"
#define kRVAOptions_ShowProgressShort              @"sp"
#define kRVAOptions_DefaultSubtitleShort           @"ds"
#define kRVAOptions_BackgroundColorShort           @"bc"
#define kRVAOptions_GestureBackShort               @"gb"
#define kRVAOptions_CanPullDownShort               @"pd"
#define kRVAOptions_ShowOptionMenuShort            @"so"
#define kRVAOptions_ShowTitleLoadingShort          @"tl"
#define kRVAOptions_ShowDomainShort                @"sd"
#define kRVAOptions_TransparentShort               @"tt"

// back behavior
#define kRVABackBehaviorPop     @"pop"
#define kRVABackBehaviorBack    @"back"

//*******************************Session Events***************************//
#pragma mark - Session Events

#define kRVAEvent_Session_Pause         @"session.pause"   // 保活功能，退出使用，到后台保活
#define kRVAEvent_Session_Resume        @"session.resume"  // 保活功能，从后台保活恢复使用

//*******************************Scene Events***************************//
#pragma mark - Scene Events

// title View
#define kRVAEvent_Scene_TitleView_Create_Before         @"scene.titleView.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（创建默认的titleView），若要自定义titleView，则设置其`titleView`，自定义的titleView要实现协议RVANavigationTitleViewProtocol
#define kRVAEvent_Scene_TitleView_Create_After          @"scene.titleView.create.after" // 监听该事件，可以获取titleView，并可以改变它的属性
#define kRVAEvent_Scene_TitleView_Title_Set             @"scene.titleView.title.set" // 监听该事件，可以获取或设置title
#define kRVAEvent_Scene_TitleView_Title_Click           @"scene.titleView.title.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是向h5页面发送事件kRVAPageJSApi_TitleClick）
#define kRVAEvent_Scene_TitleView_Subtitle_Click        @"scene.titleView.subtitle.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是向h5页面发送事件kRVAPageJSApi_SubtitleClick）
#define kRVAEvent_Scene_TitleView_RightIcon_Click        @"scene.titleView.righticon.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是向h5页面发送事件kRVAEvent_Scene_TitleView_RightIcon_Click）
#define kRVAEvent_Scene_TitleView_All                   @"scene.titleView.*"


// navitaion item btn
#define kRVAEvent_Scene_NavigationItem_Left_Back_Create_Before   @"scene.navigationItem.left.back.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（创建默认的返回按钮），若要自定义返回按钮，则设置其`customView`
#define kRVAEvent_Scene_NavigationItem_Left_Back_Create_After    @"scene.navigationItem.left.back.create.after" // 监听该事件，可以获取返回按钮，并设置它的属性
#define kRVAEvent_Scene_NavigationItem_Left_Back_Click           @"scene.navigationItem.left.back.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是返回行为），并自己实现返回逻辑
#define kRVAEvent_Scene_NavigationItem_Left_Back_All             @"scene.navigationItem.left.back.*"


#define kRVAEvent_Scene_NavigationItem_Left_Close_Create_Before  @"scene.navigationItem.left.close.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（创建默认的关闭按钮），若要自定义关闭按钮，则设置其`customView`
#define kRVAEvent_Scene_NavigationItem_Left_Close_Create_After   @"scene.navigationItem.left.close.create.after" // 监听该事件，可以获取关闭按钮，并设置其属性
#define kRVAEvent_Scene_NavigationItem_Left_Close_Click          @"scene.navigationItem.left.close.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是关闭行为），并自己实现关闭行为
#define kRVAEvent_Scene_NavigationItem_Left_Close_All            @"scene.navigationItem.left.close.*"


#define kRVAEvent_Scene_NavigationItem_Right_Setting_Create_Before  @"scene.navigationItem.right.setting.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（默认是创建设置按钮），若要自定义设置按钮，则设置其`customView`，自定义的customView要实现协议RVASettingButtonProtocol
#define kRVAEvent_Scene_NavigationItem_Right_Setting_Create_After   @"scene.navigationItem.right.setting.create.after" // 监听该事件，可以获取设置按钮，并设置其属性

#define kRVAEvent_Scene_NavigationItem_Right_Setting_Click          @"scene.navigationItem.right.setting.click" // 监听该事件，可以调用preventDefault阻止默认行为（默认是打开分享等控制面板），并自己实现设置行为

#define kRVAEvent_Scene_NavigationItem_Right_Setting_Change         @"scene.navigationItem.right.setting.change" //

#define kRVAEvent_Scene_NavigationItem_Right_Setting_All            @"scene.navigationItem.right.setting.*"


#define kRVAEvent_Scene_NavigationItem_Right_SubSetting_Create_Before  @"scene.navigationItem.right.subsetting.create.before"
#define kRVAEvent_Scene_NavigationItem_Right_SubSetting_Create_After   @"scene.navigationItem.right.subsetting.create.after"
#define kRVAEvent_Scene_NavigationItem_Right_SubSetting_Click          @"scene.navigationItem.right.subsetting.click"


// toolbar Menu
#define kRVAEvent_Scene_ToolbarMenu_Create_Before           @"scene.toolbarMenu.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（默认是创建toolbarMenu），若要自定义toolbarMenu，则设置其`toolbarMenu`，自定义的toolbarMenu要实现协议RVAToolbarMenuProtocol
#define kRVAEvent_Scene_ToolbarMenu_Create_After            @"scene.toolbarMenu.create.after" // 监听该事件，可以获取toolbarMenu，并设置其属性
#define kRVAEvent_Scene_ToolbarMenu_Select                  @"scene.toolbarMenu.select"
#define kRVAEvent_Scene_ToolbarMenu_Create_All              @"scene.toolbarMenu.*"


// progress View
#define kRVAEvent_Scene_ProgressView_Create_Before          @"scene.progressView.create.before" // 监听该事件，可以调用preventDefault阻止默认行为（默认是创建进度条），若要自定义进度条，则设置其`progressView`，自定义的progressView需要实现协议RVAProgressViewProtocol
#define kRVAEvent_Scene_ProgressView_Create_After           @"scene.progressView.create.after" // 监听该事件，可以获取进度条progressView，并设置其属性
#define kRVAEvent_Scene_ProgressView_Create_All             @"scene.progressView.create.*"

// request
#define kRVAEvent_Scene_LoadRequest_First                   @"scene.loadRequest.first" //
#define kRVAEvent_Scene_LoadRequest_All                     @"scene.loadRequest.*" //


// layout
#define kRVAEvent_Scene_Layout_WebView_Before               @"scene.layout.webview.before"
#define kRVAEvent_Scene_Layout_WebView_After                @"scene.layout.webview.after"
#define kRVAEvent_Scene_Layout_WebView_All                  @"scene.layout.webview.*"

// service发出的事件：scene create event
#define kRVAEvent_Scene_Create_Before                       @"scene.create.before" // 监听该事件，可以获取context
#define kRVAEvent_Scene_ContentView_Fallback                @"scene.ContentView.Fallback" // 监听该事件，可以获取context

//scrollView
#define kRVAEvent_Scene_ScrollView_DidScroll                @"scene.scrollview.didscroll"

//component
#define kRVAEvent_Scene_Component_FullScreen                @"scene.component.fullScreen"
//**********************************JSApis******************************//
#pragma mark - JSApis

// titlebar
#define kRVAJSApi_ShowTitleBar                          @"showTitlebar"
#define kRVAJSApi_HideTitleBar                          @"hideTitlebar"
#define kRVAJSApi_ShowStatusBar                         @"showStatusBar"
#define kRVAJSApi_HideStatusBar                         @"hideStatusBar"

// navigation title view
#define kRVAJSApi_SetTitle                              @"setTitle"
#define kRVAJSApi_ShowTitleLoading                      @"showTitleLoading"
#define kRVAJSApi_HideTitleLoading                      @"hideTitleLoading"

// loadingView
#define kRVAJSApi_ShowLoading                           @"showLoading"
#define kRVAJSApi_HideLoading                           @"hideLoading"

// option Menu
#define kRVAJSApi_SetOptionMenu                         @"setOptionMenu"
#define kRVAJSApi_ShowOptionMenu                        @"showOptionMenu"
#define kRVAJSApi_HideOptionMenu                        @"hideOptionMenu"

// toolbar Menu
#define kRVAJSApi_ShowToolbar                           @"showToolbar"
#define kRVAJSApi_HideToolbar                           @"hideToolbar"
#define kRVAJSApi_SetToolbarMenu                        @"setToolbarMenu"

// monitor
#define kRVAJSApi_H5Monitor                             @"h5Monitor"
#define kRVAJsApi_H5Report                              @"h5Report"

//**********************************Page JSApis******************************//
#define kRVAPageJSApi_OptionMenu                        @"optionMenu"
#define kRVAPageJSApi_TitleClick                        @"titleClick"
#define kRVAPageJSApi_SubtitleClick                     @"subtitleClick"
#define kRVAPageJSApi_AppDidReceiveMemoryWarning        @"appDidReceiveMemoryWarning"
#define kRVAPageJSApi_AppWillResignActive               @"appWillResignActive"
#define kRVAPageJSApi_AppDidBecomeActive                @"appDidBecomeActive"
#define kRVAPageJSApi_ToolbarMenuClick                  @"toolbarMenuClick"

//**********************************Dom Event******************************//
#define kRVADomEvent_AppPause                           @"appPause"
#define kRVADomEvent_AppResume                          @"appResume"
#define kRVADomEvent_PagePause                          @"pagePause"
#define kRVADomEvent_PageResume                         @"pageResume"
#define kRVADomEvent_Pause                              @"pause"
#define kRVADomEvent_Resume                             @"resume"


//**********************************Monitor******************************//
#define kRVAMonitor_LogId_PagePerformance                @"monitor.logId.pagePerformance"
#define kRVAMonitor_PagePerformance_Key_ContentViewPage  @"contentViewPage" // value RVAContentViewPageProfile

//**********************************expandProperty******************************//
#define kRVAViewControllerReadTitle                      @"readTitle"
#define kRVAViewControllerProxyPassData                  @"kRVAViewControllerProxyPassData"


//**********************************Other**************************************//
#pragma mark - Other




#endif


