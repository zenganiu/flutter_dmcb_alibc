//
//  FastUntar.h
//  FastUntar
//
//  Created by qiwei on 30/09/2017.
//  Copyright © 2017 everettjf. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RVRFastUntar : NSObject

+ (NSDictionary *)readTar:(NSString *)tarPath error:(NSError **)error;

+ (NSDictionary *)readTar:(NSString *)tarPath error:(NSError **)error filesize:(size_t*)filesize;

@end
