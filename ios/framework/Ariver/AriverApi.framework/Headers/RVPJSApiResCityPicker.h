//
//  RVPJSApiResCityPicker.h
//  AriverApi
//
//  Created by 百喻 on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiResponseBase.h>


@interface RVPJSApiResCityPicker : RVKJSApiResponseBase

@property (nonatomic,copy) NSString *city;
@property (nonatomic,copy) NSString *adCode;

@end

