//
//  RVLJSON.h
//  RiverLogger
//
//  Created by lianyu on 2021/4/16.
//  Copyright © 2021 Triver. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 提供 JSON 处理功能。
 */
@interface RVLJSON : NSObject

/**
 将指定的 JSON 对象序列化为二进制。
 */
+ (NSData * _Nullable)dataWithJSONObject:(id _Nullable)object;

/**
 将指定的 JSON 对象序列化为字符串。
 */
+ (NSString * _Nullable)stringWithJSONObject:(id _Nullable)object;

/**
 将指定的二进制反序列化为 JSON 对象。
 */
+ (id _Nullable)JSONObjectWithData:(NSData * _Nullable)data;

/**
 将指定的字符串反序列化为 JSON 对象。
 */
+ (id _Nullable)JSONObjectWithString:(NSString * _Nullable)string;

@end
