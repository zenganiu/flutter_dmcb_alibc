//
//  RVKEvent+RVAAdaptar.h
//  AriverApp
//
//  Created by hua.lu on 2019/4/23.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/AriverKernel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVKEvent (RVAAdapter)

@property(nonatomic, assign) BOOL isDispatchFromExtension;

- (void)setValue:(id)value forUndefinedKey:(NSString *)key;
- (id)valueForUndefinedKey:(NSString *)key;

@end


NS_ASSUME_NONNULL_END
