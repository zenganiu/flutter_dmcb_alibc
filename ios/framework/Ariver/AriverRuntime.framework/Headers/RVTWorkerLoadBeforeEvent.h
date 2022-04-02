//
//  RVTWorkerLoadBeforeEvent.h
//  AriverRuntime
//
//  Created by runfeng.crf on 2019/5/22.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/AriverKernel.h>
#import "RVTDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface RVTWorkerLoadBeforeEvent : RVKEvent

@property (nonatomic, copy) NSString *workerJS;

+ (instancetype)eventWithWorkerJS:(NSString *)workerJS;

@end

NS_ASSUME_NONNULL_END
