//
//  TRVMonitorProtocol.h
//  Runtime
//
//  Created by xuyouyang on 2019/8/15.
//  Copyright © 2019 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TRVMonitorProtocol <NSObject>

- (void)performanceWithType:(NSString *)type
				commonDatas:(NSDictionary *)commonDatas
				 properties:(NSDictionary *)properties
					 stages:(NSDictionary *)stages
					 events:(NSDictionary *)events;

- (void)errorWithType:(NSString *)type
				 code:(NSString *)code
				  msg:(NSString *)msg
		  commonDatas:(NSDictionary *)commonDatas
			 extDatas:(NSDictionary *)extDatas;

- (void)appMonitorAlarm:(BOOL)success
               pageName:pageName
           monitorPoint:pointName
              errorCode:strErrorCode
               errorMsg:errorMsg
                    arg:argsString;

- (void)appMonitorPerformance:(NSString *)module
                 monitorPoint:(NSString *)monitorPoint
              dimensionValues:(NSDictionary *)dictDimensionValues
                measureValues:(NSDictionary *)dictMeasureValues;

@end

NS_ASSUME_NONNULL_END
