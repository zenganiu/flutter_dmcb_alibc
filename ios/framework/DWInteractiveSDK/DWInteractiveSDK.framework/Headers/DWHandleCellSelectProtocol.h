//
//  DWHandleCellSelectProtocol.h
//  DWInteractiveSDK
//
//  Created by zzqiltw on 16/4/25.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DWHandleCellSelectProtocol <NSObject>

- (void)handleSelectedCellWithURLString:(NSString *)URLString target:(id)target modelData:(id)modelData;

@end
