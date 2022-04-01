//
//  RVEvent4ToolBar.h
//  NebulaApp
//
//  Created by lyusheng on 2018/9/29.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#ifndef RVEvent4ToolBar_h
#define RVEvent4ToolBar_h

@protocol RVEvent4ToolBar <NSObject>

@optional
- (void)pageCreateToolbarBefore:(RVKPage *)page;
- (void)page:(RVKPage *)page toolbarCreateAfter:(id)toolbar;
- (void)page:(RVKPage *)page toolbarDidSelect:(id)toolbar;
- (void)pageShowToolbar:(RVKPage *)page;
- (void)pageHideToolbar:(RVKPage *)page;

@end

#endif /* RVEvent4ToolBar_h */
