//
//  RVPScreenOrientationAdvisor.h
//  AriverApi
//
//  Created by lyusheng on 2019/7/1.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RVPScreenOrientationType) {
    RVPScreenOrientationTypePortrait,
    RVPScreenOrientationTypeLandscape,
    RVPScreenOrientationTypeOther
};

@interface RVPScreenOrientationAdvisor : NSObject

- (void)setOrientationTo:(RVPScreenOrientationType)orientation fullParam:(NSDictionary *)params page:(RVKScene *)page;

- (RVPScreenOrientationType)getCurrentOrientationType:(RVKScene *)page;

@end

NS_ASSUME_NONNULL_END
