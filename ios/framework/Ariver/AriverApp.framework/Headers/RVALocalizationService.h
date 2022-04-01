//
//  RVALocalizationService.h
//  AriverApi
//
//  Created by guobing.sgb on 2020/2/20.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RVALocalizationService <RVAServiceProtocol>

@optional

- (nullable NSString *)localizedStringForKey:(nonnull NSString *)key
                                defaultValue:(nullable NSString *)defaultValue;

@end

NS_ASSUME_NONNULL_END
