//
//  RVSSandBoxService.h
//  AriverDemo
//
//  Created by theone on 2019/4/12.
//  Copyright © 2019 alipay.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AriverApp/RVAContext.h>

NS_ASSUME_NONNULL_BEGIN

#define RVASandBoxAppIDKey @"_RVA_APPID"

@protocol RVSStorageManagerDelegate <NSObject>

@required

/**
 存储数据，如果有登陆态概念请区分uid维度进行存储
 
 @param obj
 @param key
 @return 是否成功
 */
-(BOOL)setObject:(id)obj forKey:(NSString *)key;


/**
 读取数据，如果有登陆态概念请区分uid维度进行存储
 
 @param key
 @return obj支持数据类型NSNumber、NSString、NSData、NSDate、NSArray、NSDictionary，NSArray和NSDictionary
 */
-(id)objectForKey:(NSString*)key;

/**
 remove缓存，如果有登陆态概念请区分uid维度进行存储
 
 @param key
 @return 是否成功
 */
-(BOOL)removeObject:(NSString *)key;

/**
 清空缓存，如果有登陆态概念请区分uid维度进行存储
 
 @return 是否成功
 */
-(BOOL)clearStorage;

/**
 返回所有缓存的key，如果有登陆态概念请区分uid维度进行存储
 
 @return 返回所有缓存的key
 */
-(NSArray*)allStorageKeys;

/**
 缓存已用的大小，如果有登陆态概念请区分uid维度进行存储
 
 @return 缓存已用的大小
 */
-(NSUInteger)storageSize;

/**
 path为小程序缓存的路径，缓存实现类必须支持在指定文件目录下存储数据，从而保证数据隔离
 
 @param path path为小程序缓存的路径
 @return
 */
-(instancetype)initWithPath:(NSString*)path;

@optional

/**
 限制单条数据存储大小上限
 
 @return
 */
- (NSUInteger)itemLimitSize;

/**
 限制整体存储数据大小上限
 
 @return
 */
- (NSUInteger)storageLimitSize;

@end


@protocol RVSSandBox <NSObject>
@property (nonatomic,strong) NSString * appId;
@property (nonatomic,strong) NSArray * allStorageKeys;
@property (nonatomic,assign) NSUInteger storageSize;
@property (nonatomic,assign) NSUInteger itemLimitSize;
@property (nonatomic,assign) NSUInteger storageLimitSize;

-(instancetype)initWith:(NSString*)appId storageManager:(id<RVSStorageManagerDelegate>)storageManager;
-(BOOL)setObject:(id)obj forKey:(NSString *)key checkSize:(BOOL)checkSize;
-(id)objectForKey:(NSString*)key;
-(BOOL)removeObject:(NSString*)key;
-(BOOL)clearStorage;

@end


#define RVS_TINY_APP_AUTHORIZE_STORAGE @"TINY_APP_AUTHORIZE_STORAGE"

@protocol RVSSandBoxService <RVAServiceProtocol>
-(id<RVSSandBox>)sandBox4AppId:(NSString*)appId;
@end


NS_ASSUME_NONNULL_END
