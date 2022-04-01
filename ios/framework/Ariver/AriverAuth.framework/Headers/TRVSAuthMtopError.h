//
//  TRVSAuthMtopError.h
//  AriverAuth
//
//  Created by AllenHan on 2019/5/8.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TRVSAuthMtopError : NSObject
@property (nonatomic, strong) NSError *oriError;
@property (nonatomic, copy) NSString *mtopErrorMsg;
@property (nonatomic, copy) NSString *mtopOriginalMsg;
@property (nonatomic, copy) NSString *mtopErrorCode;
@end

