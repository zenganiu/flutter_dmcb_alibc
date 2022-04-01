//
//  DeviceDiagnose.h
//  硬件信息检查
//
//  Created by hansong.lhs on 2017/12/27.
//  Copyright © 2017年 alibaba. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 * evaluation for each target(cpu, memory, storage, display, battery, and the overall device)
 */
typedef NS_ENUM(NSUInteger, AliHADeviceEvaluationLevel) {
    UNKNOW_LEVEL,
    HIGH_END_DEVICE,
    MEDIUM_DEVICE,
    LOW_END_DEVICE
};

/**
 * evaluation for each target(cpu, memory, storage, display, battery, and the overall device) at runtime
 */
typedef NS_ENUM(NSUInteger, AliHARuntimeEvaluationLevel) {
    DEVICE_IS_GOOD,
    DEVICE_IS_NORMAL,
    DEVICE_IS_RISKY,
    DEVICE_IS_FATAL,
};

/**
 * general device info, including device brand and model
 */
@interface AliHADeviceInfo : NSObject

@property (nonatomic, copy) NSString *deviceBrand;
@property (nonatomic, copy) NSString *deviceModel;
@property (nonatomic, copy) NSString *osVersion;

@end

/**
 * cpu info
 */
@interface AliHACPUInfo : NSObject

@property (nonatomic, assign) float frequency;
@property (nonatomic, copy) NSString *model;
@property (nonatomic, assign) NSUInteger numCores;
@property (nonatomic, assign) float cpuUsageOfApp;              // cpu usage of app, percentage * 100
@property (nonatomic, assign) float cpuUsageOfDevice;           // cpu usage of device, percentage * 100
@property (nonatomic, assign) AliHADeviceEvaluationLevel deviceLevel;  // static device level
@property (nonatomic, assign) AliHARuntimeEvaluationLevel runtimeLevel;  // dynamic runtime level

@end

/**
 * memory info
 */
@interface AliHAMemoryInfo : NSObject

@property (nonatomic, assign) unsigned long long totalMemeory;       // total memory in M
@property (nonatomic, assign) float freeMemory;         // free memory in M
@property (nonatomic, assign) float residentMemory;     // resident memory in M
@property (nonatomic, assign) float virtualMemory;      // virtual memory size in M
@property (nonatomic, assign) float internal_plus_compressed; // internal + compressed in M
@property (nonatomic, assign) float physFootprint;      // physical footprint
@property (nonatomic, assign) NSInteger systemMemoryLevel;    // memory level
@property (nonatomic, assign) AliHADeviceEvaluationLevel deviceLevel;  // static device level
@property (nonatomic, assign) AliHARuntimeEvaluationLevel runtimeLevel;  // dynamic runtime level

@end

/**
 * screen display info
 */
@interface AliHADisplayInfo : NSObject

@property (nonatomic, assign) CGSize screenSize;
@property (nonatomic, assign) NSUInteger density;
@property (nonatomic, assign) CGSize resolution;
@property (nonatomic, assign) AliHADeviceEvaluationLevel deviceLevel;  // static device level

@end

/**
 * storage info
 */
@interface AliHAStorageInfo : NSObject

@property (nonatomic, assign) unsigned long long maxStorage;        // max storage in M
@property (nonatomic, assign) unsigned long long freeStorage;       // free storage in M
@property (nonatomic, assign) NSUInteger readSpeed;                 // read speed, M/s
@property (nonatomic, assign) NSUInteger writeSpeed;                // write speed, M/s
@property (nonatomic, assign) AliHADeviceEvaluationLevel deviceLevel;  // static device level

@end

/**
 * battery info
 */
@interface AliHABatteryInfo : NSObject

@end

@interface AliHADeviceEvaluation : NSObject

+ (AliHADeviceInfo *)getDeviceInfo;

/**
 * get memory info(no cache)
 */
+ (AliHAMemoryInfo *)getMemoryInfo;

/**
 * get cpu info(no cache)
 */
+ (AliHACPUInfo *)getCPUInfo;

/**
 * get storage info(cached)
 */
+ (AliHAStorageInfo *)getStorageInfo;

/**
 * get battery info(no cache)
 */
+ (AliHABatteryInfo *)getBatteryInfo;

/**
 * get display info
 */
+ (AliHADisplayInfo *)getDisplayInfo;

/**
 * overall evaluation for device
 */
+ (AliHADeviceEvaluationLevel)evaluationForDeviceLevel;

/**
 * runtime device level
 */
+ (AliHARuntimeEvaluationLevel)evaluationForRuntimeLevel;

@end
