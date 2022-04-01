//
//  RVAPVReporter.h
//  AriverApp
//
//  Created by chenwenhong on 15/10/8.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RVAContentViewPageProfile.h"
#import "RVANebulaViewProtocol.h"

@interface RVAPVReporter : NSObject <RVAContentViewPageDelegate>

@property(nonatomic, copy) NSString *nbl_id;
@property(nonatomic, copy) NSString *entranceUrl;
@property(nonatomic, strong) RVAContentViewPageProfile *lastPage;

- (void)viewWillAppear;

- (void)viewWillDisappear;

- (void)viewWillDestroy;

@end
