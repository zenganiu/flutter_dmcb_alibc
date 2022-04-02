//
//  RVPJSApiResTitleView.h
//  Ariver
//
//  Created by zhongweitao on 2019/4/20.
//

#import <AriverKernel/RVKJSApiResponseBase.h>

@interface RVPJSApiResTitleViewGetHeight : RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *density;
@property (nonatomic, strong) NSNumber *titleBarHeight;
@property (nonatomic, strong) NSNumber *statusBarHeight;

@end

@interface RVPJSApiResTitleViewGetTitleColor: RVKJSApiResponseBase

@property (nonatomic, strong) NSNumber *color;

@end




