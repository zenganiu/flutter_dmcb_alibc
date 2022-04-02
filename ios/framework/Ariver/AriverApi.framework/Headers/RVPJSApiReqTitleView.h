//
//  RVPJSApiReqTitleView.h
//  Ariver
//
//  Created by zhongweitao on 2019/4/20.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

@interface RVPJSApiReqTitleViewSetTitle : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subtitle;
@property (nonatomic, strong) NSString *image;

@end

@interface RVPJSApiReqTitleViewSetTitleColor : RVKJSApiRequestBase

@property (nonatomic, strong) NSNumber *color;  //设置标题颜色
@property (nonatomic, strong) NSNumber *reset;  //重置标题颜色
@property (nonatomic, strong) NSNumber *resetTransparent;  //重置为白色透明标题

@end

@interface RVPJSApiReqTitleViewSetBarBottomLineColor : RVKJSApiRequestBase

@property (nonatomic, strong) NSNumber *color;  //设置标题颜色

@end

@interface RVPJSApiReqTitleViewSetTransparentTitle : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *transparentTitle;  //always:永久透明 none:不透明 auto:自动变化模式

@end

@interface RVPJSApiReqTitleViewSetBackButton : RVKJSApiRequestBase

@property (nonatomic, strong) NSString *color;

@end







