//
//  TRVSSecurityStorageProtocol.h
//  AriverDemo
//
//  Created by AllenHan on 2019/4/30.
//  Copyright © 2019年 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TRVSSecurityStorageProtocol <NSObject>

@required
- (id)getContentWithKey:(NSString *)key baseType:(Class)baseType;
- (void)putContent:(id)content withKey:(NSString *)key baseType:(Class)baseType;
- (void)removeContentWithKey:(NSString *)key baseType:(Class)baseType;

@end
