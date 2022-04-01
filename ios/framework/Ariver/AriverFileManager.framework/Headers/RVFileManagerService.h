//
//  RVFConfigService.h
//  AriverFileManager
//
//  Created by pingyang.yq on 2019/4/29.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>

NS_ASSUME_NONNULL_BEGIN


@protocol RVFileManagerService <RVAServiceProtocol>

@required

//传递userId，用作区分存储
- (NSString *)userId;

//统一存储相关，用来做文件的真实路径和虚拟路径映射
- (void)saveMapRelationToDB:(NSString *)key value:(NSString *)value;
- (NSString *)getMapRelationVal:(NSString *)key;
- (void)removeMapRelationVal:(NSString *)key;
// 解压文件
- (BOOL)UnzipOpenFile:(NSString *)zipFilePath fileTo:(NSString *)path overWrite:(BOOL)overwrite;

@optional

//钱包获取多媒体完整磁盘地址，不包含下载自定义存储在多媒体中的文件
- (NSString *)getMultimediaPath:(NSString *)apFilePath;

//钱包内实现，通过多媒体获取数据
- (NSData *)getMultimediaDataWithApfilePath:(NSString *)apFilePath;

//根据localId 获取到存在多媒体中的绝对路径，下载的文件存储在多媒体中
- (NSString *)getFileAbsolutePathWithLocalId:(NSString *)localId;

//钱包文件埋点  钱包内实现
//ucId  文件调用 file  文件系统调用 fs_file  extParams：如果是写文件，这里传读取当前存储大小的耗时间@{"readCost":'读耗时'}
- (void)writeFileLogWithAppId:(NSString *)appId ucId:(NSString *)ucId jsapiName:(NSString *)jsapiName time:(double)time extParams:(NSDictionary *)extParams;
//错误调用记录 文件系统调用 file_error  extParams: {"errorCode" :  错误code,"errorMessage" :  描述}
- (void)writeErrorLogWithAppId:(NSString *)appId ucId:(NSString *)ucId jsapiName:(NSString *)jsapiName extParams:(NSDictionary *)extParams;

// 判断 tar 路径是否不可访问
- (BOOL)isTarPathInBlackList:(NSString *)path;

#pragma mark - 文件存储  插件ID做隔离，读取不做隔离的白名单,格式为 id,id,id
- (NSString *)closedDistinguishFilePluginIds;
//是否关闭插件和宿主app文件隔离
- (BOOL)closedDistinguishPluginFile;

@end

NS_ASSUME_NONNULL_END
