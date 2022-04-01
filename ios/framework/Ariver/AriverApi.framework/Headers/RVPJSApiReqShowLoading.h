//
//  RVPJSApiReqShowLoading.h
//  AriverApi
//
//  Created by lanyao on 2019/4/15.
//

#import <AriverKernel/RVKJSApiRequestBase.h>
#import <AriverKernel/RVKPage.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqShowLoading : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *text; // 文本内容；如需设为无文案，需传入一个空格，默认值：‘加载中’
@property (nonatomic, strong) NSNumber *delay; // 延迟显示，单位 ms，默认 0。如果在此时间之前调用了 my.hideLoading 则不会显示

@end

@interface RVPJSApiReqHideLoading : RVKJSApiRequestBase

@property (nonatomic, strong) RVKPage *page;

@end

NS_ASSUME_NONNULL_END
