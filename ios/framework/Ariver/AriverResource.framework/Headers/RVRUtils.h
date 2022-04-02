//
//  NXIRUtils.h
//  AriverResource
//
//  Created by nico on 2019/3/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "RVRDefine.h"


/******************************** NSDictionary ************************************/

NSDictionary *NXRDict(NSDictionary *dict, NSDictionary *defaultValue);

#pragma mark - string
/******************************** NSString ****************************************/
NSString *NXRString(NSString *str, NSString *defaultValue);

#pragma mark array
/******************************** NSArray *****************************************/
NSArray *NXRArray(NSArray *arr, NSArray *defaultValue);



void NXRPostNotification(NSString *name, id obj, NSDictionary *userinfo);


/******************************** Transfer ************************************/
NSString *NXRJsonObjToString(id object);
NSData *NXRJsonObjToData(id object);

BOOL NXRRequestExpired(NSTimeInterval lastRefreshDate, BOOL limited, NSNumber *preferUpdateRate);

NSString *NXRMD5OfString(NSString *string);

BOOL NXRBoolValue(id obj, BOOL defaultValue);

NSString *NXRMimeType(NSString *pathExtension);
id NXRDataToJsonObj(NSData *data);
NSDictionary *RVRDictionary(id obj, NSDictionary *defaultValue);
NSURL *RVRURLWithFixedString(NSString *URLString);
BOOL RVRBoolValue(id obj, BOOL defaultValue);
NSURL *NXRURLWithFixedString(NSString *URLString);
NSString *NXRTrimTailingWhiteSpace(NSString *str);
void RVRLogInfo(NSString *message);
double NXRDoubleValue(id obj, double defaultValue);
CGFloat NXRFloatValue(id obj, CGFloat defaultValue);
int NXRIntValue(id obj, int defaultValue);
NXRAppAutoScene NXRSceneType(NSString *scene);

