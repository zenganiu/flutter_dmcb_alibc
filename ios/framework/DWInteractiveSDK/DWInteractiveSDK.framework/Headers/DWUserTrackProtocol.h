//
//  DWUserTrackProtocol.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/5.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#ifndef DWUserTrackProtocol_h
#define DWUserTrackProtocol_h

typedef enum
{
    DWCommitType_Click = 0,
    DWCommitType_Expose,
//    DWCommitType_UpdateProp,
//    DWCommitType_UpdateNextProp,
    DWCommitType_12002 = 12002,
    DWCommitType_12003 = 12003,
    
} DWCommitType;

@protocol DWUserTrackProtocol <NSObject>

- (void) commit:(DWCommitType)type arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3 args:(NSDictionary *)args;

- (void)commit:(DWCommitType)type name:(NSString*)pageName comName:(NSString*)comName param:(NSDictionary*)params;

- (void)commitAppMonitorArgs:(NSDictionary *)args;

- (void)commitAppMonitorAlarm:(NSString *)pageName monitorPoint:(NSString *)monitorPoint success:(BOOL)success errorCode:(NSString *)errorCode errorMsg:(NSString *)errorMsg arg:(NSString *)arg;

- (void)pageAppear:(NSString *)pageName pageObject:(id)pageObject;
- (void)pageDisAppeaPageObject:(id)pageObject;

- (void)log:(NSString*)module message:(NSString *)message;

- (NSString *) utdid;

- (NSString *)currentPageName;

@end

#endif /* DWUserTrackProtocol_h */
