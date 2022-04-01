//
//  DWUtility.h
//  DWInteractiveSDK
//
//  Created by jyi on 16/8/29.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define KeyPath(s) NSStringFromSelector(@selector(s))

#define WeakSelf(type)  __weak typeof(type) weak##type = type; // weak
#define StrongSelf(type)  __strong typeof(type) type = weak##type; // strong

#define DWNSLog(fmt,...) NSLog((@"DWHandsome: " fmt), ##__VA_ARGS__)
#define DWNSLogv(fmt,...) NSLogv((@"DWHandsome: " fmt), ##__VA_ARGS__)

typedef NS_ENUM(NSUInteger,DWLogLevel){
    DWLogDebug,
    DWLogWarning,
    DWLogError,
};

void _DWAssert(NSString *func, NSString *file, int lineNum, NSString *format, ...);

#if DEBUG
#define DWAssert(condition, ...) \
do{ \
if(!(condition)){ \
_DWAssert(@(__func__), @(__FILE__), __LINE__, __VA_ARGS__); \
} \
}while(0)
#else
#define DWAssert(condition, ...)
#endif

void _DWLogInternal(DWLogLevel level, const char *file, NSUInteger line, NSString *format, ...);

#if DEBUG
#define DWLogInternal(level, fmt, ...) \
do { \
_DWLogInternal(level, __FILE__, __LINE__, (fmt), ## __VA_ARGS__); \
} while(0)
#else
#define DWLogInternal(level, fmt, ...)
#endif


#define DWLogDebug(format, ...)         DWLogInternal(DWLogDebug, format, ##__VA_ARGS__)
#define DWLogWarning(format, ...)       DWLogInternal(DWLogWarning, format ,##__VA_ARGS__)
#define DWLogError(format, ...)         DWLogInternal(DWLogError, format, ##__VA_ARGS__)

#define RGB(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define RGB_A(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

typedef NS_ENUM(NSInteger, DWViewMode) {
    DWViewModeUnknown = 0,
    DWViewModeNormal,
    DWViewModeFullScreen,
    DWViewModePortraitFullScreen,
    DWViewModeFloatWindow
};

@interface DWUtility : NSObject

+ (NSTimeInterval) dateFrom:(NSString*) str;

+ (BOOL) validString:(NSString*)str;

+ (CGFloat) random_between:(CGFloat)min max:(CGFloat)max;

//判断用户在2G,3G,4G等状态下
+ (NSString *)networkingStatesFromStatebar;

+ (BOOL) iPhoneX;

@end


