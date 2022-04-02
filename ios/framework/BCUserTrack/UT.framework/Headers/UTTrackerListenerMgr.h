//
//  UTTrackerListenerMgr.h
//  miniUTSDK
//
//  Created by ljianfeng on 2019/3/5.
//  Copyright © 2019 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTTracker.h"
NS_ASSUME_NONNULL_BEGIN
@protocol UTTrackerListener <NSObject>
@required
- (NSString *)trackerListenerName;
@optional
- (void)send:(NSDictionary *)logMap tracker:(UTTracker *)tracker;
- (void)updatePageProperties:(id)pPageObject properties:(NSDictionary *)pProperties tracker:(UTTracker *)tracker;
- (void)updatePageName:(id)pPageObject pageName:(NSString *)pPageName tracker:(UTTracker *)tracker;
- (void)updateNextPageProperties:(NSDictionary *)properties tracker:(UTTracker *)tracker;
- (void)pageDisAppear:(id)pPageObject tracker:(UTTracker *)tracker;
- (void)pageAppear:(id)pPageObject withPageName:(NSString *)pPageName tracker:(UTTracker *)tracker;
@end
@interface UTTrackerListenerMgr : NSObject
+ (void)registerTrackerListener:(id<UTTrackerListener> )listener;
+ (void)unregisterTrackerListener:(id<UTTrackerListener> )listener;

+ (NSArray<id<UTTrackerListener> > *)getActiveListeners;
@end

NS_ASSUME_NONNULL_END
