//
//  RVPJSApiResFile.h
//  AriverApi
//
//  Created by lanyao on 2019/4/19.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiResSaveFile : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *apFilePath; // 文件保存路径

@end

@interface RVPJSApiResGetFileInfo : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *size; // 文件大小
@property (nonatomic, strong) NSString *digest; // 摘要结果

@end

/**
 10 无权限访问
 12 文件不存在
 15 文件IO操作失败
 **/
@interface RVPJSApiResGetSavedFileInfo : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *size; // 文件大小
@property (nonatomic, strong) NSNumber *createTime; // 创建时间

@end

@interface RVPJSApiResGetSavedFileList : RVKJSApiResponseBase

@property (nonatomic, strong) NSArray *fileList; // 文件列表
@property (nonatomic, assign) BOOL success;

@end

/*
 10 无权限操作
 12 文件不存在
 15 删除文件失败
 */
@interface RVPJSApiResRemoveSavedFile : RVKJSApiResponseBase
@property (nonatomic, assign) BOOL success; //移除文件是否成功
@end


@interface RVPJSApiResUploadFile : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *data;       // 服务器返回的数据
@property (nonatomic, strong) NSString *statusCode; // HTTP 状态码
@property (nonatomic, strong) NSDictionary *header; // 服务器返回的 header

@end

@interface RVPJSApiResDownloadFile : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *apFilePath; // 文件临时存放的位置

@end

@interface RVPJSApiResChooseFileFromDisk : RVKJSApiResponseBase

@property (nonatomic, strong) NSString *apFilePath; // 文件临时存放的位置

@end

NS_ASSUME_NONNULL_END
