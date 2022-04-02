//
//  NSError+WMLMtop.h
//  AliWindmill
//
//  Created by ali_liuhui on 2019/3/12.
//

#import <Foundation/Foundation.h>

@interface NSError (WMLMtop)
@property (nonatomic, copy) NSString *mtopErrorMsg;
@property (nonatomic, copy) NSString *mtopOriginalMsg;
@property (nonatomic, copy) NSString *mtopErrorCode;

@end
