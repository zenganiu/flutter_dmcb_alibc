//
//  NBTUtils.h
//  NebulaTinyapp
//
//  Created by theone on 2017/12/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>
#import <AriverApp/AriverApp.h>
#import <AriverResource/RVRApp.h>

@interface RVTUtils : NSObject
+ (void)reportJSExecuteError:(NSError *)error;
+ (NSString *)JSONString:(id)object;
+ (id)JSONObjct:(NSData *)data;
+ (NSData *)getSourceDataFromCacheWithUrl:(NSURL *)url session:(RVASession *)session;
+ (RVKScene *)getSceneWithViewId:(NSString *)viewId withSession:(RVKSession *)session;
+ (NSString *)getFallbackUrlWithApp:(RVKSession *)session url:(NSURL *)url;
+ (NSString *)getAppLaunchValWithApp:(RVRApp *)app params:(NSDictionary *)params key:(NSString *)key;
+ (BOOL)regexTestWithStr:(NSString *)str  patterns:(NSArray *)patterns;
+ (NSString *)getUrlFromScene:(RVKScene *)scene;
@end

NSDictionary * RVTJsonDicWithData(NSData *data);
NSDictionary * RVTDictionary(id dic);
NSString * RVTString(id string);
NSArray * RVTArray(id array);
