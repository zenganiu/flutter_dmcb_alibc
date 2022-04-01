//
//  AliRemoteDebugServiceInterface.h
//  AliInfrastructureServiceInterface
//
//  Created by 晨燕 on 2018/1/8.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, AliRemoteDebugLogLevel) {
    AliRemoteDebugLogLevel_Off,
    AliRemoteDebugLogLevel_Error,
    AliRemoteDebugLogLevel_Warn,
    AliRemoteDebugLogLevel_Info,
    AliRemoteDebugLogLevel_Debug,
    AliRemoteDebugLogLevel_Trace // trace log type
};

typedef NS_ENUM (NSInteger, AliRemoteTraceEventType) {
    AliRemoteTraceEventTypeCommon = 0,
    AliRemoteTraceEventTypeClicked,
    AliRemoteTraceEventTypeNet
};

typedef NS_ENUM (NSInteger, AliRemoteSceneType) {
    AliRemoteSceneTypeStartup = 1,
    AliRemoteSceneTypePage
};

@protocol AliRemoteDebugInterface <NSObject>

- (void)debug:(NSString *)message module:(NSString*)module exception:(NSException *)exception;

- (void)info:(NSString *)message module:(NSString*)module exception:(NSException *)exception;

- (void)warn:(NSString *)message module:(NSString*)module exception:(NSException *)exception;

- (void)error:(NSString *)message module:(NSString*)module exception:(NSException *)exception;

@optional
/**
* @desc 在例如 统一导航跳转、小程序启动等场景，开始业务纬度场景类型埋点
*/

- (void)createGlobalSceneIdWithKeyWord:(NSString *)keyword;

/**
* 全链路事件日志
*
* @param cntID     当前事件的关联id
* @param refID     上一级事件的关联id
* @param sceneID   场景Id
* @param eventTime 事件发生的实际时间
* @param event     事件名
* @param eventCode 事件状态(0表示成功)
* @param eventType 时间类型 Common = 0 (默认) ClickEvent = 1 点击事件 NetEvent = 2 网络事件
* @param tag       tag
* @param codeMsg   事件信息
* @param bizCode   业务码
* @param ext       事件附加数据
*/
- (void)trace:(NSString *)cntID
        refID:(NSString *)refID
      sceneID:(NSString *)sceneID
       module:(NSString *)module
    eventTime:(NSTimeInterval)eventTime
        event:(NSString *)event
    eventCode:(NSString *)eventCode
    eventType:(AliRemoteTraceEventType)eventType
          tag:(NSString *)tag
      codeMsg:(NSString *)codeMsg
      bizCode:(NSString *)bizCode
          ext:(NSString *)ext;

- (void)trace:(NSString *)cntID
        refID:(NSString *)refID
       module:(NSString *)module
     eventTime:(NSTimeInterval)eventTime
    event:(NSString *)event
    eventCode:(NSString *)eventCode
    eventType:(AliRemoteTraceEventType)eventType
          tag:(NSString *)tag
      codeMsg:(NSString *)codeMsg
          ext:(NSString *)ext;

- (void)trace:(NSString *)cntID
        refID:(NSString *)refID
       module:(NSString *)module
        event:(NSString *)event
    eventCode:(NSString *)eventCode
      codeMsg:(NSString *)codeMsg
          ext:(NSString *)ext;

- (void)trace:(NSString *)cntID
        refID:(NSString *)refID
       module:(NSString *)module
        event:(NSString *)event;

- (void)trace:(NSString *)cntID
       module:(NSString *)module
        event:(NSString *)event;

#pragma mark - Scene Log Methods
/**
* 父子关联关系 父节点日志 表示类似于页面级别 以及 在当前节点下的所有操作的日志关联
*
* @param sceneType 场景类型 eg : 启动场景 =1 ; 页面场景 =2
* @param sceneUrl  当前场景的url
* @param refUrl    前一个场景的url
* @param ext       同场景的扩展数据
*/

- (void)sceneType:(AliRemoteSceneType)sceneType
          module:(NSString *)module
        sceneUrl:(NSString *)sceneUrl
          refUrl:(NSString *)refUrl
             tag:(NSString *)tag
             ext:(NSString *)ext;

- (void)pageModule:(NSString *)module
            sceneUrl:(NSString *)sceneUrl
              refUrl:(NSString *)refUrl
                 tag:(NSString *)tag
                 ext:(NSString *)ext;

- (void)appModule:(NSString *)module
           sceneUrl:(NSString *)sceneUrl
             refUrl:(NSString *)refUrl
                tag:(NSString *)tag
                ext:(NSString *)ext;

- (void)sceneType:(AliRemoteSceneType)sceneType
          module:(NSString *)module
             tag:(NSString *)tag;



 /**
 *  在某些场景或异常流程下，业务方主动调用，能够直接上传TLog日志，默认上传当天的日志，如果当时客户端的网站环境是非wifi,
 *  会把上传指令存成离线任务。等待切换到wifi再上传。
 *
 *  @param extraInfo 上传成功后附带的业务参数，由调用方自定义传入: @{@"反馈标题":,@"反馈内容":,@"分类名称":,@"昵称":,@"utdid":}
 */
- (void)uploadLogFile:(NSDictionary*)extraInfo;

/**
 * current log level
 */
- (AliRemoteDebugLogLevel)currentLogLevel;

@end


#define AliRemoteDebugService getAliRemoteDebugService()

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    // default get [AliRemoteDebugImp sharedInstance]接口来获取，如果没有的话，就返回nil
    id<AliRemoteDebugInterface> getAliRemoteDebugService(void);
    void setAliRemoteDebugService(id<AliRemoteDebugInterface>);

#ifdef __cplusplus
}
#endif // __cplusplus


