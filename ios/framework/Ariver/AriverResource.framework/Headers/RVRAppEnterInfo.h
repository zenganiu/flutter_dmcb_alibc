//
//  RVRAppEnterInfo.h
//  Ariver
//
//  Created by zhongweitao on 2019/4/8.
//

#import <Foundation/Foundation.h>

@interface RVRAppEnterInfo : NSObject

@property (nonatomic, copy) NSString *appUrl;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *page;

@property (nonatomic, strong) NSDictionary *enterParams;

@end
