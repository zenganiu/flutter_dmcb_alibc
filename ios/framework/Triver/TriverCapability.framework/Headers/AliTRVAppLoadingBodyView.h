//
//  WMLAppLoadingBodyView.h
//  AppContainer
//
//  Created by AllenHan on 2018/5/14.
//  Copyright © 2018年 AllenHan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>
#import <WindmillTRiverKit/TRVEnterInfoModel.h>

typedef NS_ENUM(NSInteger, AliTRVLoadingViewType) {
    AliTRVLoadingViewTypeTinyApp,
    AliTRVLoadingViewTypeTinyShop,
    AliTRVLoadingViewTypeTinyAppSecond,
    AliTRVLoadingViewTypeTinyShopSecond
};

typedef void(^AliTRVAppLoadingBodyViewBackAction)(void);

@interface AliTRVAppLoadingBodyView : UIView <TRVLoadingViewProtocol>

- (instancetype)initWithFrame:(CGRect)frame enterInfo:(TRVEnterInfoModel *)enterInfo type:(AliTRVLoadingViewType)type;

- (instancetype)initWithFrame:(CGRect)frame type:(AliTRVLoadingViewType)type;

@end
