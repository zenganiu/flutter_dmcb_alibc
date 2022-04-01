//
//  DWUserTrackMgr.h
//  DWInteractiveSDK
//
//  Created by jyi on 16/8/5.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

//action
#define DWUT_WEEX_RENDER_SUCCESS @"DWUT_WEEX_RENDER_SUCCESS"
#define DWUT_WEEX_RENDER_FAILED @"DWUT_WEEX_RENDER_FAILED"
#define DWUT_H5_LOAD_SUCCESS @"DWUT_H5_LOAD_SUCCESS"
#define DWUT_H5_LOAD_FAILED @"DWUT_H5_LOAD_FAILED"

#define DWUT_COLLECTLOGO_COLLECT @"DWUT_COLLECTLOGO_COLLECT"

#define DWUT_GOSHOP_SHOW @"DWUT_GOSHOP_SHOW"
#define DWUT_GOSHOP_CLICK @"DWUT_GOSHOP_CLICK"

#define DWUT_CONTENTTAG_CLICK @"DWUT_CONTENTTAG_CLICK"
#define DWUT_TRACKERTAG_CLICK @"DWUT_TRACKERTAG_CLICK"

#define DWUT_ADDCARD_CALL @"DWUT_ADDCARD_CALL"

@protocol DWDirectorProtocol<NSObject>

//director
- (void) receive:(NSString*)action error:(NSError*)error arg:(NSObject*)arg;

@end

@protocol DWActorProtocol<NSObject>

//actor
@property (nonatomic, weak) NSObject* director;

@end


@interface DWUserTrackMgr : NSObject

+ (DWUserTrackMgr *) instance;

- (void) notifyDirector:(id)director action:(NSString*)action error:(NSError*)error arg:(NSObject*)arg;

@end
