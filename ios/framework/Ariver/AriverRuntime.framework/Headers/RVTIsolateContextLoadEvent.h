//
//  RVTIsolateContextLoadEvent.h
//  AriverRuntime
//
//  Created by runfeng.crf on 2019/7/11.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/AriverKernel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVTIsolateContextLoadEvent : RVKEvent

@property (nonatomic, copy) NSString *additionalJS;

+ (instancetype)event;

@end

NS_ASSUME_NONNULL_END
