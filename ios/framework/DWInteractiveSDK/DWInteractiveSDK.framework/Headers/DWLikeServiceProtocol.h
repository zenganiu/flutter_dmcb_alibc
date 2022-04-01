//
//  DWLikeServiceProtocol.h
//  Pods
//
//  Created by yingfang on 2017/7/11.
//
//

#import <Foundation/Foundation.h>

typedef void(^DWLikeServiceComplete)(NSDictionary *responseData,BOOL isSuccess);

@protocol DWLikeServiceProtocol <NSObject>


/**
 点赞.
 
 @param params 赞的字典.
 @param completionBlock @see DWLikeServiceComplete.
 */
- (void) likeWithParamsDictionary:(NSDictionary *) params completion:(DWLikeServiceComplete) completionBlock ;


/**
 取消赞.
 
 @param params 取消赞的参数字典.
 @param completionBlock @see DWLikeServiceComplete.
 */
- (void) cancelLikeWithParamsDictionary:(NSDictionary *) params
                             completion:(DWLikeServiceComplete) completionBlock ;

@end
