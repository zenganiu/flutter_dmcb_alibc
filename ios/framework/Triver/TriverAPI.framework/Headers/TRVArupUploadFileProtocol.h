//
//  TRVArupUploadFileProtocol.h
//  API
//
//  Created by xuyouyang on 2019/7/5.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TRVArupUploadFileError) {
	TRVArupUploadFileErrorNone = 0, // 无失败，即成功
	TRVArupUploadFileErrorFlieNotExist = 11, // 文件不存在
	TRVArupUploadFileErrorFailed = 12, // 上传失败
};

typedef void(^TRVArupUploadFileResultBlock)(NSDictionary * _Nullable headers, TRVArupUploadFileError errorCode);

@protocol TRVArupUploadFileProtocol <NSObject>

@required
/**
 通过 ARUP SDK 上传文件
 
 @param bizType        业务ID
 @param fileLocalPath  文件本地路径
 @param fileName       文件名
 @param resultCallback 结果回调
 */
- (void)uploadFileWithBizType:(NSString *)bizType
				fileLocalPath:(NSString *)fileLocalPath
					 fileName:(NSString *)fileName
					xArupMeta:(NSDictionary *)xArupMeta
			   resultCallback:(TRVArupUploadFileResultBlock _Nullable )resultCallback;

@end

NS_ASSUME_NONNULL_END
