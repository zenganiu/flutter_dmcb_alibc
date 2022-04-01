//
//  RVFPathUtils.h
//  AriverFileManager
//  地址转换类
//  Created by pingyang.yq on 2019/4/30.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RVFConvertFileType) {
    RVFConvertFileTypeImage,
    RVFConvertFileTypeVideo,
    RVFConvertFileTypeAudio,
    RVFConvertFileTypeOther
};

@interface RVFPathUtils : NSObject

/**
 根据文件本地磁盘地址，获取APFilePath

 @param localPath 文件本地磁盘地址
 @param fileType 文件类型
 @return 格式化后的地址
 */
+ (NSString *)getApFilePathFromLocal:(NSString *)localPath fileType:(RVFConvertFileType)fileType;

/**
 根据APFilePath获取本地地址，从DB中读取
 @param apFilePath 虚拟地址
 */
+ (NSString *)getLocalPathFromApFilePath:(NSString *)apFilePath;

/**
 移动文件到小程序临时目录/Library/Caches/H5CustomFiles/tmp/MD5(appId)，返回移动后的地址

 @param fromPath 要移动的文件地址
 @param appId appid
 @return 移动后的地址，移动失败 或者找不到文件 返回  nil
 */
+ (NSString *)moveFileToTinyappFoldFrom:(NSString *)fromPath appId:(NSString *)appId;

/**
 移动文件到小程序临时目录/Library/Caches/H5CustomFiles/tmp/MD5(appId)，返回移动后的地址
 如果是插件，调用此方法，生成的地址会带上插件信息
 @param fromPath 要移动的文件地址
 @param appId appid 宿主id
 @param pluginId pluginId 插件ID
 @return 移动后的地址，移动失败 或者找不到文件 返回  nil
 */
+ (NSString *)moveFileToTinyappFoldFrom:(NSString *)fromPath appId:(NSString *)appId pluginId:(NSString *)pluginId;

@end

