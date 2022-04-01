//
//  AliTRVActionSheetHelper.h
//  JDYUIControls
//
//  Created by 连墨 on 2018/4/19.
//  Copyright © 2018年 连墨. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindmillTRiverKit/TRVBaseViewController.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>

#import "AliTRVActionSheet.h"

#define kKeyMenuList            @"menuList"
#define kKeyList                @"list"

typedef enum : NSUInteger {
    AliTRVActionSheetItemTypeUnknown,
    AliTRVActionSheetItemTypeFeedback,
    AliTRVActionSheetItemTypeShare,
    AliTRVActionSheetItemTypeAbout,
    AliTRVActionSheetItemTypeBackToHome
} AliTRVActionSheetItemType;

@protocol AliTRVActionSheetHelperDelegate <NSObject>

@optional

/// @brief 接入方通过实现该方法，来定制菜单按钮默认项是否添加
- (BOOL)shouldAddDefaultMenuItemType:(AliTRVActionSheetItemType)type inViewController:(TRVBaseViewController *)vc;

/**
 修改页面对应的菜单按钮的actionSheet的默认项（该方法在
 "-shouldAddDefaultMenuItemType:inViewController:"之后调用）

 @param menuItems 当前页面的默认菜单项
 @param vc 当前页面的container
 @return 返回修改后的actionSheet展示项
 */
- (NSArray *)menuItems:(NSArray *)menuItems inViewController:(TRVBaseViewController *)vc;

@end

@interface AliTRVActionSheetHelper : NSObject<AliTRVActionSheetDelegate, TRVActionSheetProtocol>

@property (nonatomic, weak) id<AliTRVActionSheetHelperDelegate> delegate;

+ (instancetype)sharedInstance;

+ (void)showActionSheet:(NSDictionary*)dict inViewController:(TRVBaseViewController *)vc;
+ (void)showActionSheet:(NSDictionary*)dict inViewController:(TRVBaseViewController *)vc delegate:(id<AliTRVActionSheetDelegate>)delegate;

+ (void)openUrl:(NSString *)urlStr
    orFireEvent:(NSString *)eventName
         inPage:(TRVBaseViewController *)page;

/// @brief 打开舆情反馈小程序
+ (void)openFeedbackApp:(TRVBaseViewController *)page;

+ (NSDictionary *)addDefaultMenuItemsIntoMenuInfo:(NSDictionary *)menuInfo inViewController:(TRVBaseViewController *)vc appName:(NSString *)appName;
+ (NSDictionary *)addReturnToHomeMenuItem:(NSDictionary *)menuInfo inViewController:(TRVBaseViewController *)vc;

+ (NSArray *)top4MenuItemsExceptBottomAboutFromMenuInfo:(NSDictionary *)menuInfo;
+ (NSDictionary *)removeMenuItemForAboutFromMenuInfo:(NSDictionary *)menuInfo;

+ (NSDictionary *)defaultAuthSettingMenuItemsInfo;


/**
 actionSheet中的返回item

 @return 返回item
 */
+ (NSDictionary *)backToHomeItem;

/**
 actionSheet中的反馈item

 @return 反馈item
 */
//+ (NSDictionary *)feedbackItem;

/**
 actionSheet中的分享item
 
 @return 分享item
 */
//+ (NSDictionary *)shareItem;

/**
 actionSheet中的关于item
 
 @return 关于item
 */
+ (NSDictionary *)aboutItemForAppName:(NSString *)appName;

/**
 actionSheet中的授权设置item
 
 @return 授权设置item
 */
//+ (NSDictionary *)authSettingItem;

/**
 端容器默认设置项对应的URL
 
 @return 默认设置项URL数组
 */
+ (NSArray<NSString *> *)defaultSettingItemUrls;

@end
