//
//  TRVLocalDebug.h


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <TriverRuntime/TRVRemoteLogHandler.h>
#import <TriverAppContainer/TRVAppContainer.h>

@interface TRVLogInfo : NSObject

@property (nonatomic, strong) NSString *eventId;
@property (nonatomic, strong) NSString *stage;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSString *appId;
@property (nonatomic, strong) NSString *pageName;
@property (nonatomic, strong) NSDictionary *info;
@property (nonatomic, strong) NSString *time;
@property (nonatomic, strong) NSDate *date;

@end

@interface TRVLocalDebug : NSObject<TRVLocalLogProtocol>

@property (nonatomic, weak) TRVAppContainer *currentAppContainer;

/// @brief 返回当前类型的共享实例。
+ (TRVLocalDebug *)sharedInstance;

+ (void)setup;

@end
