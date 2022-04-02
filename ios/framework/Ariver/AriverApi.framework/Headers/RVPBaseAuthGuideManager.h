//
//  RVPAuthGuideManagerProtocol.h
//  AriverApi
//
//  Created by 张光宇 on 2019/5/5.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RVPAuthGuideManagerAuthType) {
    RVPAuthGuideManagerAuthTypeNone = 0,
    RVPAuthGuideManagerAuthTypePush,
    RVPAuthGuideManagerAuthTypeLocation,
    RVPAuthGuideManagerAuthTypeCamera,
    RVPAuthGuideManagerAuthTypePhotos,
    RVPAuthGuideManagerAuthTypeAddressBook,
    RVPAuthGuideManagerAuthTypeMicroPhone
};

extern NSString * const kRVPAuthGuideShowOptionKeyScene ;

NS_ASSUME_NONNULL_BEGIN

@interface RVPBaseAuthGuideManager : NSObject
/**
 *  子类必须需重写此方法
 * 
 *  尝试提示用户设置定位授权，此方法会结合配置规则和实际情况决定是否展示浮层弹框给用户。
 *
 *  @param authType      业务定制参数，枚举量，授权权限类型，相机、定位等。
 *  @param biz           业务场景标识，必须传入有意义的值，不能为空。
 *  @param options       其他参数。尚未用到，留日后使用使用。
 *
 *  @return 是否符合展示条件，最终真正展示。
 */
-(BOOL)tryToShowGuideWithAuthType:(RVPAuthGuideManagerAuthType)authType
                         business:(NSString *)biz
                          options:(NSDictionary* _Nullable)options;

-(RVPAuthGuideManagerAuthType)typeForAuthCode:(NSString*)authCode;


@end

NS_ASSUME_NONNULL_END
