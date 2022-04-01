//
//  RVAUtils.h
//  RVAService
//
//  Created by chenwenhong on 15/8/21.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RVAMonitor.h"
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <AriverKernel/RVKNode.h>
#import <AriverResource/RVRApp.h>

#define RVALocalizedString(key, value) [RVAUtils localizedStringForKey:key defaultValue:value]

@interface RVAUtils: NSObject

+ (BOOL)isRVKNode:(RVKKernel *)node targetList:(NSArray<RVKNode *> *)targetList;
+ (BOOL)isTinyAppWithSession:(RVKSession*)session;

#pragma mark - Localization

+ (nullable NSString *)localizedStringForKey:(nonnull NSString *)key
                                defaultValue:(nullable NSString *)defaultValue;

@end

#pragma mark - Runtime
/************************************** Runtime ******************************************/

void RVASwizzle(Class c, SEL orig, SEL newSelector);

#pragma mark - URL
/************************************** URL **********************************************/

NSString *RVAURLEncode(NSString *str);
NSString *RVAURLURLDecode(NSString *string);

BOOL RVAURLIsEqualsIgnoreHash(NSString *orig, NSString *dest);

BOOL RVAURLIsValidateUrl(NSString *str); // http、https、file

BOOL RVAURLIsOnlineUrl(NSString *str); // http、https

BOOL RVAURLIsFileUrl(NSString *str); // file

BOOL RVAHostIsAppStore(NSString *host);

NSString *RVAURLString(NSString *urlString, NSURL *baseURL);

NSDictionary *RVAURLGetQuery(NSString *queryString);

#pragma mark - UIImage
/************************************* UIImage ******************************************/

UIImage *RVAImageNamed(NSString *imageName);
UIImage *RVACacheableImageNamed(NSString *imageName);

UIImage *RVAReSizeImage(UIImage *image, CGSize reSize);
UIImage *RVAImageFromColor(UIColor *color, CGSize size);
#pragma mark - Class
/************************************ Class ********************************************/


#pragma mark - NSString
/*********************************** NSString ******************************************/
NSString *RVAString(NSString *str, NSString *defaultValue);

CGRect RVARectForString(NSString * string, UIFont * font, CGRect boundingRect);

#pragma mark - UIColor
/************************************** UIColor ****************************************/
UIColor *RVAColorWithHex(NSInteger hex); // 0xAARRGGBB、0xRRGGBB

UIColor *RVAColorWithWebString(NSString *colorString); // #aarrggbb 、 #rrggbb 、 rgb(rr,gg,bb) 、 argb(aa,rr,gg,bb)

#pragma mark - NSDictionary
/*********************************** NSDictionary **************************************/
NSDictionary *RVAMergeDict(NSDictionary *origDict, NSDictionary *newDict);

//CGFloat RVAFloatValue(id obj, CGFloat defaultValue);

int RVAIntValue(id obj, int defaultValue);

//NSInteger RVAIntegerValue(id obj, NSInteger defaultValue);

BOOL RVABoolValue(id obj, BOOL defaultValue);

NSArray *RVAArray(id obj, NSArray *defaultValue);

NSDictionary *RVADictionary(id obj, NSDictionary *defaultValue);

NSDictionary *RVAOptionsWithURL(NSString *url);

#pragma mark - Device
/************************************** Device ****************************************/
CGFloat RVADeviceSystemVersion();

#pragma mark - Environment
/*********************************** Environment *************************************/
//NSString *RVAEnvironmentName(const NSInteger environment);

//NSString *RVAChannelName(const NSInteger channel);

#pragma mark - Log
/************************************** Log *****************************************/
void RVALog(NSString *logId, NSDictionary *params);

void RVALocalLog(NSString* format,...);

#pragma mark - Encrypt & Decrypt
/********************************** Encrypt & Decrypt ********************************/
NSString *RVAMD5(NSString *string);

//NSString *RVAMD5OfData(NSData *data);

NSString *RVABase64Encode(NSData *data);

NSData *RVABase64Decode(NSString *string);

UIImage *RVABase64Decode2Image(NSString *string);

BOOL RVAIsBase64(NSString *string);

NSString *RVACalculateDigest(NSString *string);
NSString *RVACalculateDigestFromData(NSData *data);

#pragma mark - Other
/************************************** Other *****************************************/
CTTelephonyNetworkInfo *RVATelephonyInfo();
NSString *RVATrimTailingWhiteSpace(NSString *str);
NSURL *RVAURLWithFixedString(NSString *URLString);
BOOL RVARegexTest(NSString *target, NSArray *rules);
//void RVALogInfo(NSString *message);



/************************************** Env *****************************************/
BOOL RVAIsUrlInAliWhitelist(NSURL *url);
BOOL RVAIsUrlInAlipayWhitelist(NSURL *url);
BOOL RVAIsUrlInSeriousAliWhitelist(NSURL *url);
int RVAWKRetryTimes();
BOOL RVAEnableWKFGRefresh();

NSString *RVAUString(id string);
NSNumber *RVAUNumber(id number);
NSArray *RVAUArray(id array);
NSDictionary *RVAUDictionary(id dic);
NSString *RVAUJsonStr(NSDictionary * dic);
NSDictionary *RVAUJsonDic(NSString * jsonStr);
NSDictionary *RVAUJsonDicWithData(NSData *data);

BOOL RVAIsInnerTinyAppWithAppId(NSString *appId);
BOOL RVAIsTinyAppWithSession(RVKSession *session);
BOOL RVAIsTinyAppDebugMode(RVKSession *session, RVRApp *app);

BOOL RVAIsConfigOn(NSString* switchKey, NSString *appId, BOOL defaultValue);
NSString *RAVAppIdGet(RVKSession *session);
