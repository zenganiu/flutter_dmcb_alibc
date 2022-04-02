//
//  RVEvent4ProgressView.h
//  NebulaApp
//
//  Created by lyusheng on 2018/9/29.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#ifndef RVEvent4ProgressView_h
#define RVEvent4ProgressView_h

#import <AriverApp/RVAProgressView.h>

@protocol RVEvent4ProgressView<NSObject>
@optional
- (void)pageCreateProgressViewBefore:(RVKPage *)page;
- (void)page:(RVKPage *)page progressViewCreateAfter:(id<RVAProgressViewProtocol>)progressView;
@end

#endif /* RVEvent4ProgressView_h */
