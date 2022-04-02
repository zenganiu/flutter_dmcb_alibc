//
//  RVPJSApiReqFile.h
//  AriverApi
//
//  Created by lanyao on 2019/4/19.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqSaveFile : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *apFilePath; // 文件临时路径，H5和小程序传
@property (nonatomic, strong) NSString *tempFilePath;//用于native调用

@end

@interface RVPJSApiReqGetFileInfo : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *apFilePath; // 文件路径
@property (nonatomic, strong) NSString *digestAlgorithm; // 摘要算法，支持md5和sha1，默认为md5

@end

@interface RVPJSApiReqGetSavedFileInfo : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *apFilePath; // 文件路径

@end

@interface RVPJSApiReqGetSavedFileList : RVKJSApiRequestBase
@end

@interface RVPJSApiReqRemoveSavedFile : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *apFilePath;

@end


@interface RVPJSApiReqUploadFile : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *url;        // 开发者服务器地址
@property (nonatomic, strong) NSString *filePath;   // 要上传文件资源的本地定位符
@property (nonatomic, strong) NSString *name;   // 文件名，即对应的 key, 开发者在服务器端通过这个 key 可以获取到文件二进制内容
@property (nonatomic, strong) NSString *type;   // 文件类型，image / video / audio
@property (nonatomic, strong) NSDictionary *header; // HTTP 请求 Header
@property (nonatomic, strong) NSDictionary *formData;   // HTTP 请求中其他额外的 form 数据

@end



@interface RVPJSApiReqDownloadFile : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *url;        // 下载文件地址
@property (nonatomic, strong) NSDictionary *header; // HTTP 请求 Header

@end

@interface RVPJSApiReqChooseFileFromDisk : RVKJSApiRequestBase

@end

NS_ASSUME_NONNULL_END
