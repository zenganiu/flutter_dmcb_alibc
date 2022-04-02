//
//  TRVDBStorage.h
//  Triver
//
//  Created by zhongweitao on 2019/4/1.
//

#import <Foundation/Foundation.h>
#import <FMDB/FMDatabase.h>
#import <FMDB/FMDatabaseQueue.h>

@interface TRVDBStorage : NSObject

/// @brief 数据库对应的DBQueue动初始化
@property (nonatomic, strong ,readonly) FMDatabaseQueue *dbQueue;

/// @brief 自定义DB文件路径
@property (nonatomic, strong) NSString *dbDirectory;

+ (TRVDBStorage *)sharedInstance;

- (void)setup;

@end
