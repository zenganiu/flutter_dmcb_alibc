//
//  RVAServiceManager.h
//  AriverApp
//
//  Created by theone on 2019/4/8.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVAServiceManager : NSObject
- (id)findServiceByName:(NSString *)name;
@end

NS_ASSUME_NONNULL_END
