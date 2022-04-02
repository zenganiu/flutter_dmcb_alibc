// Copyright 2019 Taobao (China) Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WMixViewParam : NSObject <NSFastEnumeration>

@property (nonatomic, copy, readonly) NSString* name;
@property (nonatomic, copy, readonly) NSString* value;

+ (instancetype)paramWithDicitonary:(NSDictionary<NSString*, NSString*>*)dictionary;

- (NSString*)objectForKeyedSubscript:(NSString*)name;

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(NSString* _Nonnull __unsafe_unretained[_Nonnull])buffer count:(NSUInteger)len;

@end

NS_ASSUME_NONNULL_END
