//
//  NXRDefine.h
//  NebulaResource
//
//  Created by 扶瑶 on 16/3/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

@class RVRApp;

#pragma mark - Package Status

typedef NS_ENUM(NSUInteger, NXRAppStatus) {
    NXRAppStatusInstalled = 0,  // Installed
    NXRAppStatusUninstalled,    // Uninstalled
    NXRAppStatusInstalling,     // Installing (include Downloading and UnZipping)
    NXRAppStatusOffline,        // Offline
};

#pragma mark - App Update Source

typedef NS_ENUM(NSUInteger, NXRAppSource) {
    NXRAppSourceRequest = 0,    // http request or rpc
    NXRAppSourceSync,           // sync
    NXRAppSourceBuildIn         // built-in
};

// app update scene
typedef NS_ENUM(NSUInteger, NXRAppAutoScene) {
    NXRAppAutoSceneNormal = 0,      // normal, default
    NXRAppAutoSceneDebug,           // debug
};

/*
 * NXRNOTI_APP_UPDATED
 *
 * app update notification (include update and delete)
 *
 * userinfo params:
 *      NXRNOTI_APP_UPDATED_LIST:    appid list
 *      NXRNOTI_APP_UPDATED_SOURCE:  update source, NSNumber object of NXRAppSource
 */
extern NSString *const NXRNOTI_APP_UPDATED;
extern NSString *const NXRNOTI_APP_UPDATED_LIST;
extern NSString *const NXRNOTI_APP_UPDATED_SOURCE;


#pragma mark - Prepare (include Request & Install)

extern NSString *const NXRPREPARE_OFFTYPE;

typedef NS_ENUM(NSUInteger, NXRAppPrepareStep) {
    NXRAppPrepareStepUnknown,
    NXRAppPrepareStepStart,             // Start
    NXRAppPrepareStepAcquireInfo,       // AcquireInfo
    NXRAppPrepareStepAcquireInfoFinish, // AcquireInfoFinish
    NXRAppPrepareStepDownload,          // Download
    NXRAppPrepareStepDownloadFinish,    // DownloadFinish
    NXRAppPrepareStepUnzip,             // Unzip
    NXRAppPrepareStepUnzipFinish,       // UnzipFinish
    NXRAppPrepareStepFinished,          // Finished
    NXRAppPrepareStepBeforeLaunch,      // Before LaunchPrepare
    NXRAppPrepareStepLaunch             // LaunchPrepare
};

// prepare finish info key
extern NSString *const NXRPreFinishInfoKeyReqType;
extern NSString *const NXRPreFinishInfoKeyOfflineType;

typedef void (^NXRAppPrepareProcess)(NXRAppPrepareStep step, id info);                  // prepare step
typedef void (^NXRAppPrepareFinish)(RVRApp  *app, NSError *error);                       // prepare finished
typedef void (^NXRAppPrepareFinishWithInfo)(RVRApp  *app, NSError *error, id info);      // prepare finished (include info)


/*
 * return: can be interrupt
 * processor-dicInfo:
 *      key      value
 *      'error'  error
 */
typedef void (^NXRFinishBlock)(NSError *error);
typedef void (^NXRAppXFinishBlock)(NSError *error,BOOL updated);
typedef NSError *(^NXRAppPrepareProcessor)(NXRAppPrepareStep step, RVRApp *app, NSDictionary *dicInfo, NXRFinishBlock finish);  // prepare step


// request type
typedef NS_ENUM (NSInteger, NXRActionReqType) {
    NXRActionReqAsync = 0,      // async request
    NXRActionReqSyncTry,        // try sync request
    NXRActionReqSyncForce,       // force sync request
    NXRActionReqIfNoCache      //return cache info if exist, and never send request rpc
};

// request trigger source
typedef NS_ENUM (NSInteger, NXRActionReqTriggerSource) {
    NXRActionReqTriggerSourceNormal = 0,
    NXRActionReqTriggerSourceSideMgw
};

// offline type
typedef NS_ENUM (NSInteger, NXRActionOfflineType) {
    NXRActionOfflineAsync = 0,  // async offline
    NXRActionOfflineSyncForce,  // sync force offline
    NXRActionOfflineSyncTry,    // sync try offline
    NXRActionOfflineNone        // don't download
};


#pragma mark - Install (include Download & Unzip)

typedef NS_ENUM(NSUInteger, NXRAppInstallStep) {
    NXRAppInstallStepDownload,          // Download
    NXRAppInstallStepDownloadFinish,    // DownloadFinish
    NXRAppInstallStepUnzip,             // Unzip
    NXRAppInstallStepUnzipFinish        // UnzipFinish
};

typedef void (^NXRAppInstallProcess)(NXRAppInstallStep step, id info);  // install step
typedef void (^NXRAppInstallFinish)(RVRApp *app, NSError *error);       // install finished


#pragma mark - Acquire PackageInfo (include synchronous rpc)

typedef NS_ENUM(NSUInteger, NXRAcquireAppStep) {
    NXRAcquireAppStepRequesting,        // Requesting
};

typedef void (^NXRAcquireAppProcess)(NXRAcquireAppStep step);
typedef void (^NXRAcquireAppFinish)(RVRApp *app, NSError *error);


#pragma mark - ZipArchive

extern NSString *const NXRNOTI_UNZIP_SUCCESS;

typedef void (^NXRZipArchiveFinish)(RVRApp *app, NSError *error);
typedef void (^NXRZipArchiveProcess)(float percent);   //  percent : 0.0 - 1.0


#pragma mark - Download

extern NSString *const NXRNOTI_DOWNLOAD_FINISHE;

typedef void (^NXRDownloadFinish)(NSString *path, NSError *error);
typedef void (^NXRDownloadProcess)(float percent); // percent : 0.0 - 1.0


#pragma mark - Request

typedef void (^NXRRequestFinish)(NSDictionary *data, NSError *error);

#pragma mark - Verify

extern NSString *const NXRNOTI_VERIFY_FINISHED;

// userinfo key: status, alert
extern NSString *const NXRNOTI_VERIFY_FINISHED_STATUS;
extern NSString *const NXRNOTI_VERIFY_FINISHED_ALERT;


#pragma mark - Network

typedef NS_ENUM (NSUInteger, NXRNetworkStatus) {
    NXRNetworkNotReachable = 0,
    NXRNetworkWWAN         = 1,
    NXRNetworkWiFi         = 2
};


#pragma mark - Notification

extern NSString *const NXRNOTI_USER_UPDATED;
extern NSString *const NXRNOTI_USER_STORAGE_RESET; // 用于内部用户重置通知, 业务不用关注

