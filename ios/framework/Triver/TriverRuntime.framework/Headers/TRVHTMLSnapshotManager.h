//
//  TRVHTMLSnapshotManager.h
//  Runtime
//
//  Created by xuyouyang on 2019/8/19.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverKernel/AriverKernel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TRVHTMLSnapshotManager : NSObject

#pragma mark - ”普通“snapshot
/**
 保存 ”普通“ snapshot
 */
+ (BOOL)saveHTMLSnapshot:(NSString *)snapshot appId:(NSString *)appId appVersion:(NSString *)appVersion;

/**
 加载 ”普通“ snapshot
 */
+ (NSData *)loadHTMLSnapshotWithRVKContext:(RVKContext *)rvkContext;

/**
 是否允许 “普通” snapshot
 */
+ (BOOL)enableSnapshot:(NSString *)appId templateId:(NSString *)templateId;

#pragma mark - ”模板“snapshot

/**
 读取包内 template snapshot 文件
*/
+ (NSData *)loadPkgTemplateHTMLSnapshotWithRVKContext:(RVKContext *)rvkContext;

/**
 读取包内 template js 文件，并且拼接了 prefetch 的数据
*/
+ (NSData *)loadPkgTemplateJSWithRVKContext:(RVKContext *)rvkContext;

/**
 是否允许 “模板” snapshot
 */
+ (BOOL)enableTemplateSnapshot:(NSString *)appId templateId:(NSString *)templateId;

@end

NS_ASSUME_NONNULL_END

