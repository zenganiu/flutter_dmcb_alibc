//
//  TRVConfigProtocol.h
//  TRiverKit
//
//  Created by AllenHan on 2019/4/9.
//  Copyright © 2019年 TaoBao. All rights reserved.
//

typedef void (^TRVConfigUpdateBlock)(NSDictionary *groupConfig);

@protocol TRVConfigProtocol <NSObject>

@optional

/**
 是否开启用户足迹
 */
- (BOOL)needOpenUserFootprint;

/// @brief 是否降级舆情反馈小程序
- (BOOL)downgradeFeedbackApp;

- (void)trv_registerListenerForGroupName:(NSString *)groupName updateBlock:(TRVConfigUpdateBlock)updateBlock;

@required
- (id)trv_getConfigByGroupName:(NSString *)groupName key:(NSString *)key defaultConfig:(id)defaultConfig isDefault:(BOOL *)isDefault;

@end
