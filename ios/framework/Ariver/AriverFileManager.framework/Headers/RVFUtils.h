//
//  RVFUtils.h
//  AriverFileManager
//
//  Created by pingyang.yq on 2019/4/29.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJsApi.h>

extern NSString *const RVFCommonUserId;
extern NSString *const RVFH5CustomFolderName;

@class RVKSession;

void RVFSafeCallback(RVKJsApiResponseCallbackBlock callback, id responseData);

@interface RVFUtils : NSObject

#pragma mark - 获取appid，如果是小程序直接读取appid，如果是插件，appid=pluginId+appId
+ (NSString *)appIdForPluginAndTinyApp:(NSDictionary *)originParam originAppId:(NSString *)originAppId;

/// 根据插件ID和appID。获取用作当前文件存储的隔离ID
/// @param pluginId 插件ID
/// @param appId appID
+ (NSString *)appIdForPluginAndTinyAppWithPluginId:(NSString *)pluginId appId:(NSString *)appId;

//获取H5主存储目录 H5CustomFiles
+ (NSString *)getCustomMainFlodPath;

// 根据appId获取小程序用户目录
+ (NSString *)getAppPathWithAppId:(NSString *)appId;
// 根据appId获取小程序或H5存储目录
+ (NSString *)getAppSavedFlodNameWithAppId:(NSString *)appId;

//获取根据appid获取小程序或H5 temp 目录
+ (NSString *)getAppTempFlodNameWithAppId:(NSString *)appId;

+ (NSString *)createApFilePathWithFileName:(NSString *)fileName
                                  fileType:(NSString *)fileType;
//根据文件名称，type，fold生成文件本地地址
+ (NSString *)createLocalFilePathWithFileName:(NSString *)fileName fileType:(NSString *)fileType foldName:(NSString *)foldName;

// 单个文件的大小
+ (float)fileSizeAtPath:(NSString *)path;
// 是否可读
+ (BOOL)canReadWithWithAppId:(NSString *)appId path:(NSString *)path session:(RVKSession *)session;
// 是否可写
+ (BOOL)canWriteWithWithAppId:(NSString *)appId path:(NSString *)path;
// 防止穿越
+ (BOOL)hasDirTraversalWithPath:(NSString *)path;
// 获取tarPath
+ (NSString *)getAppTarPathWithSession:(RVKSession *)session;


+ (NSData *)fileDataWithTempFilePath:(NSString *)tempFilePath appId:(NSString*)appId;
+ (NSData *)fileDataWithApFilePath:(NSString *)apFilePath appId:(NSString*)appId;
+ (NSString *)fileTypeWithApFilePath:(NSString *)apFilePath appId:(NSString *)appId;//仅针对需要在本地存储video的实际格式时调用
+ (float)folderSizeAtPath:(NSString *)path;

// 获取物理地址用户文件虚拟地址
+ (NSString *)getLocalURLWithAppId:(NSString *)appId path:(NSString *)path session:(RVKSession *)session;
#pragma mark - 统一存储相关
+ (NSString *)getMapRelationVal:(NSString *)formalUrl;
+ (void)saveMapRelationToDB:(NSString *)key value:(NSString *)value;

#pragma mark - 编码
// 字符串转16进制字符串
+ (NSString *)stringToHexStr:(NSString *)string;
// 16进制字符串转字符串
+ (NSString *)hexStrToString:(NSString *)hexStr;
// NSData实例转化为hex string
+ (NSString *)dataToHexStr:(NSData *)data;
// 编码映射
+ (NSStringEncoding)getEncodingType:(NSString *)encoding;
// 支持自定义默认编码的映射关系
+ (NSStringEncoding)getEncodingType:(NSString *)encoding
                    defaultEncoding:(NSStringEncoding)defaultEncoding;

#pragma mark - 日志
+ (void)writeLogWithAppId:(NSString *)appId jsapiName:(NSString *)jsapiName time:(double)time isError:(BOOL)isError extParams:(NSDictionary *)extParams;

#pragma mark - 工具
// 获取map中对应的string值
+ (NSString *)RVFStringForKey:(id)aKey dic:(NSDictionary *)dic;
// 获取map中对应的BOOL值
+ (BOOL)RVFBoolForKey:(id)aKey dic:(NSDictionary *)dic;
// 获取imageData的contentType
+ (NSString *)contentTypeForImageData:(NSData *)data;



@end

