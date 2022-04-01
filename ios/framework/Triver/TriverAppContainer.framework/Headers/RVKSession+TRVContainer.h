//
//  RVKSession+TRVContainer.h
//  Triver
//
//  Created by zhongweitao on 2019/6/4.
//

#import <AriverApp/RVKSession+RVA.h>
#import "TRVAppContainer.h"

@interface RVKSession (TRVContainer)

@property (nonatomic, strong) TRVAppContainer *appContainer;

@end
