//
//  WMLURL.h
//  Weaver
//
//  Created by lianyu on 2018/12/10.
//  Copyright © 2018 Windmill. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 包含 URL 相关操作的功能，格式参照 RFC 3986，提供对 Combo 的支持，但不会自动做任何编码、解码操作。
 query = <key1>=<value1> & <key2>=<value2> ...
 url = [<scheme> :] [// <authority>] / <path> [? <query>] [# <fragment>]
 comboPart = <comboPath> [? <query1>]
 url = [<scheme> :] [// <authority>] / <path> ?? <comboPart1> , <comboPart2> , ... [# <fragment>]
 */
@interface WMLURL : NSObject

/**
 检查指定的 URL 是否是空地址，支持 NSURL * 和 NSString *。
 */
+ (BOOL)isBlank:(id _Nullable)url;

#pragma mark - Query

/**
 返回经过 URL 编码后的字符串，供编码查询参数使用。
 */
+ (NSString * _Nonnull)urlEncodedString:(NSString * _Nonnull)urlString;

/**
 向指定 URL 的查询末尾添加指定的查询，支持一次性增加单个或多个查询；如果是 Combo URL，会将参数添加到最后一个 Combo 部分上。
 
 @param urlString 要添加查询的 URL 字符串。
 @param queries   要添加的查询，为 name1=value1&name2=value2 的格式。
 
 @return 已添加查询的 URL。
 */
+ (NSString * _Nullable)url:(NSString * _Nullable)urlString appendQueries:(NSString * _Nullable)queries;

/**
 返回当前 URL 是否包含指定的查询；如果是 Combo URL，只会检查最后一个 Combo 部分的查询参数。
 
 @param urlString 要检查查询的 URL 字符串。
 @param query     要检查的查询，为 name1=value1 的格式。
 */
+ (BOOL)url:(NSString * _Nullable)urlString containsQuery:(NSString * _Nullable)query;

/**
 移除 URL 中的 Query 和 Fragment。
 */
+ (NSString * _Nullable)urlWithoutQueryAndFragment:(NSString * _Nullable)urlString;

#pragma mark - Fragment

/**
 移除 URL 中的 Fragment。
 */
+ (NSString * _Nullable)urlWithoutFragment:(NSString * _Nullable)urlString;

@end
