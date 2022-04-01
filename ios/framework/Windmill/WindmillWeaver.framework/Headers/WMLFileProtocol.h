//
//  WMLFileProtocol.h
//  Weaver
//
//  Created by lianyu on 2018/7/17.
//  Copyright © 2018年 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 表示文件的相关接口。
 */
@protocol WMLFileProtocol <NSObject>

@required

/**
 根据相对路径获取绝对路径
 */
- (NSString * _Nullable)absoluteFilePath:(NSString * _Nonnull)relativeFilePath;

/**
 返回指定文件是否存在。
 */
- (BOOL)fileExistsAtPath:(NSString * _Nonnull)path;

/**
 返回指定文件是否存在，以及是否是目录。
 */
- (BOOL)fileExistsAtPath:(NSString * _Nonnull)path isDirectory:(BOOL * _Nullable)isDirectory;

/**
 创建指定的目录。
 */
- (BOOL)createDirectoryAtPath:(NSString * _Nonnull)path error:(NSError * _Nullable * _Nullable)error;

/**
 移除指定文件或目录。
 */
- (BOOL)removeItemAtPath:(NSString * _Nonnull)path error:(NSError * _Nullable * _Nullable)error;

/**
 复制指定的文件。
 */
- (BOOL)copyItemAtPath:(NSString * _Nonnull)srcPath toPath:(NSString * _Nonnull)dstPath error:(NSError * _Nullable * _Nullable)error;

/**
 移动指定的文件。
 */
- (BOOL)moveItemAtPath:(NSString * _Nonnull)srcPath toPath:(NSString * _Nonnull)dstPath error:(NSError * _Nullable * _Nullable)error;

/**
 获取 document 目录中全部文件的信息
 */
- (nullable NSDictionary<NSString *, NSDictionary *> *)attributesOfAllDocumentFiles;

/**
 获取指定文件的信息
  */
- (nullable NSDictionary<NSFileAttributeKey, id> *)attributesOfItemAtPath:(NSString * _Nonnull)path error:(NSError * _Nullable * _Nullable)error;

/**
 移动指定的绝对路径文件到 temp 目录中，返回值为相对路径。
 */
- (NSString * _Nullable)moveItemToTempDirectoryAtAbsolutePath:(NSString * _Nonnull)absolutePath error:(NSError * _Nullable * _Nullable)error;

/**
 读取指定相对路径的文件内容。
 */
- (NSData * _Nullable)contentsAtPath:(NSString * _Nonnull)path;

@end
