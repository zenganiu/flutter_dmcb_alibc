//
//  TKCpsManage.h
//  MunionBcAdSDK
//
//  Created by 江滔 on 2019/11/27.
//  Copyright © 2019 江滔. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <mtopext/MtopError.h>



typedef void (^ successBlock)(NSDictionary *result);
typedef void (^ failBlock)(MtopError *  error);

@interface TKCpsManage : NSObject
+(instancetype)shareInstance;

/*
 *  手淘/天猫 detail/shop页面直接调用广告sdk上传cps日志
 *  @param url          落地url
 *  @param extPrams
 *  返回预留字段
 */
-(void)uploadCpsTrack:(NSString *)url
               extParams:(NSDictionary *)extParams
             onSuccessBlock:(successBlock)successBlock
                onFailBlock:(failBlock)failBlock;

@end

