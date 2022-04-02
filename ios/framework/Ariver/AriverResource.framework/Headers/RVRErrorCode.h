//
//  RVRErrorCode.h
//  AriverResource
//
//  Created by nico on 2019/4/12.
//
// 错误域
extern NSString *const NXR_ERROR_DOMAIN;
extern NSString *const NXR_ERROR_OPTIONS;

/**
 NXRErrorUnknown =           10000,
 NXRErrorCanNotOpenApp =     10001,
 NXRErrorUnzipFailed =       10003,
 NXRErrorRPCException =      10004,
 NXRErrorRPCCalling =        10005,
 NXRErrorRPCNoExpired =      10006,
 NXRErrorVerifyFailed =      10007,
 NXRErrorPatchFailed =       10008,
 NXRErrorAppCacheNotExist =  10009,
 NXRErrorDownloadFailed =    10010
 */
typedef NS_ENUM(NSUInteger, NXRErrorCode) {
    
    NXRErrorUnknown = 10000,    //  未知错误
    NXRErrorCanNotOpenApp,      //  无法打开包, appId异常
    NXRErrorUnzipFailed,        //  解压包失败
    NXRErrorRPCException,       //  rpc异常, 无应用
    NXRErrorRPCCalling,         //  上一个请求尚未结束
    NXRErrorRPCNoExpired,       //  请求的app未过期
    NXRErrorVerifyFailed,       //  验签失败
    NXRErrorPatchFailed,        //  增量更新失败
    NXRErrorAppCacheNotExist,   //  应用本地缓存不存在 (e.g. 请求失败,本地无应用缓存)
    NXRErrorDownloadFailed,     //  下载失败
    NXRErrorPrepareTimeOut,     //  准备超时
    NXRErrorOpenAppBreak,       //  启动应用打断
    NXRErrorSDKVersionError     //  支持最低AppxSDK版本过低
};

