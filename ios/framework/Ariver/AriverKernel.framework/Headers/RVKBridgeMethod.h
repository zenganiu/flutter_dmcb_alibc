//
//  RVKBridgeMethod.h
//  NebulaKernel
//
//  Created by theone on 2018/9/27.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RVKNullability) {
    RVKNullabilityUnspecified,
    RVKNullable,
    RVKNonnullable,
};


@interface RVKMethodArgument : NSObject

@property (nonatomic, copy, readonly) NSString *type;
@property (nonatomic, readonly) RVKNullability nullability;
@property (nonatomic, readonly) BOOL unused;
@property (nonatomic, copy, readonly) NSString *name;

@end

NSString *RVKParseMethodSignature(const char *input, NSArray<RVKMethodArgument *> **arguments);
SEL selectorForType(NSString *type);


