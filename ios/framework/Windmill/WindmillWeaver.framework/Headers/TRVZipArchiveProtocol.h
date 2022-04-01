//
//  TRVZipArchiveProtocol.h
//  Windmill
//
//  Created by zhongweitao on 2020/2/18.
//

#import <Foundation/Foundation.h>
#import "WMLBaseProtocol.h"

@protocol TRVZipOperationProtocol <WMLBaseProtocol>

@required
- (BOOL)UnzipOpenFile:(NSString *)zipFile;

- (BOOL)UnzipCloseFile;

- (BOOL)UnzipFileTo:(NSString *)path overWrite:(BOOL)overwrite;

@optional

@end


@protocol TRVZipArchiveProtocol <WMLBaseProtocol>

@required
- (id<TRVZipOperationProtocol>)zipArchiverInstance;

@end
