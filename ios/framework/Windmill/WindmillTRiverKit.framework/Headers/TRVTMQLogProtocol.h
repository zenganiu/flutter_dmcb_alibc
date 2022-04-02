//
//  TRVTMQLogProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/9/17.
//  Copyright © 2019年 TaoBao. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol TRVTMQLogProtocol <NSObject>

@required
- (void)setupLogInfoWithUrl:(NSString *)url pageName:(NSString *)pageName type:(NSString *)type;
- (void)reportTMQStageBegin:(NSString *)stageName;
- (void)reportTMQStageEnd:(NSString *)stageName;
- (void)commitTMQLog;

@end


