//
//  AliTRVAuthUIDialog.h
//  TRiverCore
//
//  Created by AllenHan on 2019/4/20.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AriverKernel/RVKSession.h>
#import <AriverAuth/RVSAuthorizeService.h>


@interface AliTRVAuthInfo : NSObject
@property (nonatomic, copy) NSString *appLogo;
@property (nonatomic, copy) NSString *appFullName;
@property (nonatomic, copy) NSString *appSimpleName;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *confirmTitle;
@property (nonatomic, copy) NSString *cancelTitle;
@property (nonatomic, strong) NSArray *protocolNames;
@property (nonatomic, strong) NSArray *protocolUrls;
@property (nonatomic, strong) NSArray *authHints;
@property (nonatomic, strong) NSDictionary *extraInfo;
@end


@interface AliTRVAuthUIDialog : NSObject <RVSAuthView, RVSAuthorizeDialog>

@property (nonatomic, weak) id<RVSDialogDelegate> delegate;

- (instancetype)initWithParentView:(UIView *)parentView authInfo:(AliTRVAuthInfo *)authInfo;

- (void)showAccountAuth;

- (BOOL)isShowingDialog;

@end


@interface AliTRVAuthUIAdapter : NSObject <RVSAuthorizeService>
@end

