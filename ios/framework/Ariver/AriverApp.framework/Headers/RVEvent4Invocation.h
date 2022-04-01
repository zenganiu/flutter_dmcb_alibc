//
//  RVEvent4Invocation.h
//  AriverApp
//
//  Created by hua.lu on 2019/8/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#ifndef RVEvent4Invocation_h
#define RVEvent4Invocation_h

#import "RVKJsApi.h"

@protocol RVEvent4Invocation<NSObject>

@optional
// kEvent_Invocation_Invoke
- (void)scene:(RVKScene *)scene
   invokeData:(NSDictionary *)data
         name:(NSString *)name
     callback:(RVKJsApiResponseCallbackBlock)callback
          url:(NSString *)url
        jsApi:(RVKJsApi *)jsApi;

@end


#endif /* RVEvent4Invocation_h */
