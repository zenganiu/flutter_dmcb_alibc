//
//  RVKProxyWKCacheManager.h
//  NebulaPoseidon
//
//  Created by theone on 2017/9/11.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#define KRVKWKCacheSourceTypeOfXMLHTTPREQUEST @"KRVKWKCacheSourceTypeOfXMLHTTPREQUEST"
#define KRVKWKCacheSourceTypeOfForm @"KRVKWKCacheSourceTypeOfForm"

@interface RVKProxyWKCacheManager : NSObject
+ (instancetype)sharedInstance;
- (void)addInfoWithKey:(NSString *)key
               charset:(NSStringEncoding)charset
                  info:(id)info
              dataType:(NSString *)type
            requestUrl:(NSString *)requestUrl
            sourceType:(NSString *)sourceType;
- (id)getInfoWithKey:(NSString *)key;
- (void)removeInfoWithKey:(NSString *)key;
- (void)fillRequest:(NSURLRequest *)request;
- (void)clearWKBodyCache;
@end
