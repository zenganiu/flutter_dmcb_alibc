//
//  TRVUTUtil.h
//  Triver
//
//  Created by zhongweitao on 2019/9/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AriverResource/RVRApp.h>

UIKIT_EXTERN NSString * const kAppMonitorModule;
UIKIT_EXTERN NSString * const kAppMonitorPointLaunch;
UIKIT_EXTERN NSString * const kAppMonitorPointApi;
UIKIT_EXTERN NSString * const kAppMonitorPointResource;
UIKIT_EXTERN NSString * const kAppMonitorPointCloudFunction;

@interface TRVUTUtil : NSObject

/// @brief 启动总次数打点
+ (void)commitAppLaunchStart:(NSString *)appId
               deployVersion:(NSString *)deployVersion
              developVersion:(NSString *)developVersion
                  templateId:(NSString *)templateId;

/// @brief 用户取消
+ (void)commitUserCancelLaunch:(RVRApp *)app;

/// @brief 包失败（下载失败、解压失败、验签失败都要打点）
+ (void)commitPackageFailed:(RVRApp *)app;

/// @brief AppInfo请求成功失败率
+ (void)commitAppInfoRequest:(NSString *)appId
              deployVersion:(NSString *)deployVersion
             developVersion:(NSString *)developVersion
                 templateId:(NSString *)templateId
					bizType:(NSString *)bizType
				 subBizType:(NSString *)subBizType
					success:(BOOL)success;

/// @brief Worker中Appx框架加载是否成功
+ (void)commitLoadWorkerAppx:(RVRApp *)app
					 success:(BOOL)success;

/// @brief 页面开始渲染总次数打点
+ (void)commitPageStart:(RVRApp *)app
					url:(NSString *)url;

/// @brief 页面渲染完成时的状态打点
+ (void)commitPageLoaded:(RVRApp *)app
					 url:(NSString *)url
				 success:(BOOL)success;

/// @brief 包本地缓存打点
+ (void)commitPackageCache:(RVRApp *)app
				  isPlugin:(BOOL)isPlugin
				  isZCache:(BOOL)isZCache
				 zcacheKey:(NSString *)zcacheKey
				zcacheInfo:(NSString *)zcacheInfo
			   zcacheError:(NSError *)zcacheError
				   success:(BOOL)success;

/// @brief 包加载打点
+ (void)commitLoadPackage:(RVRApp *)app
				 isPlugin:(BOOL)isPlugin
				 isZCache:(BOOL)isZCache
				zcacheKey:(NSString *)zcacheKey
			   zcacheInfo:(NSString *)zcacheInfo
			  zcacheError:(NSError *)zcacheError
				  success:(BOOL)success;

/// @brief render 资源加载总次数
+ (void)commitRenderResourceCount:(RVRApp *)app
							  url:(NSString *)url;

/// @brief render 资源加载错误数
+ (void)commitRenderResourceFailed:(RVRApp *)app
							   url:(NSString *)url;

/// @brief windvane 上报的白屏信息
+ (void)commitWVPageEmptyWithApp:(RVRApp *)app
					   errorCode:(NSString *)errorCode
							 url:(NSString *)url;

/// @brief API 埋点 (无参数)
+ (void)commitApiInvokeWithApp:(RVRApp *)app
					   apiName:(NSString *)apiName
					 isSuccess:(BOOL)isSuccess
					 errorCode:(NSInteger)errorCode
				  errorMessage:(NSString *)errorMessage;

/// @brief API 埋点 (有参数)
+ (void)commitApiInvokeWithApp:(RVRApp *)app
					   apiName:(NSString *)apiName
						params:(NSDictionary *)params
					 isSuccess:(BOOL)isSuccess
					 errorCode:(NSInteger)errorCode
				  errorMessage:(NSString *)errorMessage;

/// @brief 云函数埋点
+ (void)commitCloudFunction:(RVRApp *)app
               functionName:(NSString *)functionName
                    handler:(NSString *)handler
                    success:(BOOL)success
                   timeCost:(NSNumber *)timeCost
                  errorCode:(NSString *)errorCode
               errorMessage:(NSString *)errorMessage;

/// @brief 组件埋点
+ (void)commitComponent:(RVRApp *)app
				   name:(NSString *)name
				   info:(NSString *)info;

#pragma mark - AppInfo 单独统计
/// @brief appInfo加载总次数点
+ (void)commitAppInfoStart:(NSString *)appId;
/// @brief appInfo加载失败
+ (void)commitAppInfoFail:(NSString *)appId
                errorCode:(NSString *)errorCode
                 errorMsg:(NSString *)errorMsg;
/// @brief appInfo加载成功
+ (void)commitAppInfoSuccess:(RVRApp *)app;

#pragma mark - 包 单独统计
/// @brief 包请求总次数
+ (void)commitPackageRequestStart:(RVRApp *)app;
/// @brief 包请求成功失败
+ (void)commitPackageRequestFinish:(RVRApp *)app
                         errorCode:(NSString *)errorCode
                          errorMsg:(NSString *)errorMsg
                           success:(BOOL)success;
/// @brief 包加载总次数
+ (void)commitPackageLoadStart:(RVRApp *)app;
/// @brief 包加载成功失败
+ (void)commitPackageLoadFinish:(RVRApp *)app
                      errorCode:(NSString *)errorCode
                       errorMsg:(NSString *)errorMsg
                        success:(BOOL)success;

#pragma mark - AppX 单独统计
/// @brief Appx检查总次数
+ (void)commitAppxCheckStart:(RVRApp *)app;
/// @brief Appx检查成功失败
+ (void)commitAppxCheckFinish:(RVRApp *)app
                    errorCode:(NSString *)errorCode
                     errorMsg:(NSString *)errorMsg
                      success:(BOOL)success;

#pragma mark - Render 单独统计
/// @brief 页面总数埋点
+ (void)commitRenderStart:(RVRApp *)app isFirstPage:(BOOL)isFirstPage;
/// @brief Redner框架加载成功埋点
+ (void)commitRenderFrameworkFinish:(RVRApp *)app isFirstPage:(BOOL)isFirstPage;
/// @brief 页面渲染成功埋点
+ (void)commitRenderPageLoaded:(RVRApp *)app isFirstPage:(BOOL)isFirstPage;
/// @brief snapshot加载成功埋点
+ (void)commitRenderFromSnapshot:(RVRApp *)app;
/// @brief template snapshot加载成功埋点
+ (void)commitRenderFromTemplateSnapshot:(RVRApp *)app;

#pragma mark - Worker 单独统计
/// @brief Worker总次数
+ (void)commitWorkerStart:(RVRApp *)app;
/// @brief Worker总次数
+ (void)commitWorkerFinish:(RVRApp *)app
                 errorCode:(NSString *)errorCode
                  errorMsg:(NSString *)errorMsg
                   success:(BOOL)success;



/// @brief HTTP请求成功
+ (void)commitHttpSuccess:(RVRApp *)app url:(NSString *)url rt:(NSNumber *)rt;
/// @brief HTTP请求失败
+ (void)commitHttpFail:(RVRApp *)app url:(NSString *)url rt:(NSNumber *)rt errorCode:(NSString *)errorCode errorMessage:(NSString *)errorMsg;

/// @brief MTOP请求成功
+ (void)commitMtopSuccess:(RVRApp *)app apiName:(NSString *)apiName rt:(NSNumber *)rt;
/// @brief MTOP请求失败
+ (void)commitMtopFail:(RVRApp *)app
               apiName:(NSString *)apiName
                    rt:(NSNumber *)rt
             errorCode:(NSString *)errorCode
          errorMessage:(NSString *)errorMsg;

/// @brief 分享截屏水印上传成功
+ (void)commitShareCaptureScreenSuccess:(RVRApp *)app url:(NSString *)url rt:(NSNumber *)rt;
/// @brief 分享截屏水印上传失败
+ (void)commitShareCaptureScreenFail:(RVRApp *)app url:(NSString *)url rt:(NSNumber *)rt errorCode:(NSString *)errorCode errorMessage:(NSString *)errorMsg;

#pragma mark - 基础接口
+ (void)commitStatWithAppId:(NSString *)appId
			  deployVersion:(NSString *)deployVersion
			 developVersion:(NSString *)developVersion
				 templateId:(NSString *)templateId
					bizType:(NSString *)bizType
				 subBizType:(NSString *)subBizType
		   customDimensions:(NSDictionary *)customDimensions
			 customMeasures:(NSDictionary *)customMeasures
			   monitorPoint:(NSString *)monitorPoint;

@end
