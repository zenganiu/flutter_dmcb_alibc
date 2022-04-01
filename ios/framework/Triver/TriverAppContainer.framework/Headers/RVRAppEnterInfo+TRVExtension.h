//
//  RVRAppEnterInfo+TRVExtension.h
//  Triver
//
//  Created by zhongweitao on 2019/4/16.
//

#import <AriverResource/RVRAppUtils.h>
#import <WindmillTRiverKit/TRVUIProviderProtocol.h>

typedef NS_ENUM(NSInteger, TRVTransitionType) {
    TRVTransitionTypePush,
    TRVTransitionTypePresent,
    TRVTransitionTypeDrop
};

@class TRVAppContainer;
@interface RVRAppEnterInfo (TRVExtension)

@property (nonatomic, copy, readonly) NSString *appName;
@property (nonatomic, copy, readonly) NSString *appLogo;
@property (nonatomic, copy, readonly) NSString *frameTempType;
@property (nonatomic, copy, readonly) NSString *version;
@property (nonatomic, copy, readonly) NSString *debug;
@property (nonatomic, copy, readonly) NSString *loadingType;
@property (nonatomic, copy, readonly) NSString *spmOri;

// 转场类型
@property (nonatomic, assign, readonly) TRVTransitionType transitionType;
// 场景值
@property (nonatomic, copy, readonly) NSString *chInfo;
// 延迟Loading
@property (nonatomic, assign) BOOL superSplash;

@property (nonatomic, strong) NSDictionary *extraEnterParams;
@property (nonatomic, strong) TRVAppContainer *fromAppContainer;

@property (nonatomic, strong) UIView<TRVLoadingViewProtocol> *loadingView;

- (BOOL)isHugeClosedCycle;

- (BOOL)isTinyClosedCycle;

- (BOOL)isTinyTool;

- (NSDictionary *)allEnterParams;

- (NSString *)scene;

- (BOOL)isDebugSource;

- (BOOL)isOnline;

- (BOOL)enableKeepAlive;

+ (BOOL)isOnlineForScene:(NSString *)scene;

- (BOOL)clearCahce;

@end
