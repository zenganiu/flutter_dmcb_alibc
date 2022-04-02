//
//  DWVideoFrontModel.h
//  Pods
//
//  Created by 南知 on 16/12/28.
//
//

#import <Foundation/Foundation.h>
#import <DWInteractiveSDK/DWTimeLineModel.h>
@interface DWVideoADInterModel : NSObject

@property (nonatomic, copy) NSString *jsTemplate;
@property (nonatomic, copy) NSString *jsUrl;
@property (nonatomic, strong) DWTimeLineModel *begin;
@property (nonatomic, strong) DWTimeLineModel *pause;
@property (nonatomic, strong) DWTimeLineModel *end;

+ (instancetype)modelWithJSONDictionary:(NSDictionary *)dict;

@end

@interface DWVideoFrontModel : NSObject

@property (nonatomic, strong) DWVideoADInterModel*  ad;
@property (nonatomic, copy) NSString*               coverUrl;
@property (nonatomic, assign) CGFloat               duration;
@property (nonatomic, assign) CGFloat               videoPlayTimes;
//@property (nonatomic, assign) CGFloat               videoSize4G;
//@property (nonatomic, assign) CGFloat               videoSize3G;
//@property (nonatomic, assign) CGFloat               videoSize2G;


+ (instancetype)modelWithJSONDictionary:(NSDictionary *)dict;

@end
