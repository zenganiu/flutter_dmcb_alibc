//
//  DWGoodListProtocol.h
//  DWInteractiveSDK
//
//  Created by Sapphire on 2018/1/5.
//  Copyright © 2018年 alibaba. All rights reserved.
//

#ifndef DWGoodListProtocol_h
#define DWGoodListProtocol_h

#endif /* DWGoodListProtocol_h */

#import <DWInteractiveSDK/DWContext.h>
@protocol DWGoodListProtocol <NSObject>

- (void)showNewGoodList:(DWContext *)context
                  items:(NSArray *)items
             coverImage:(NSString *)imageUrl
                 onView:(UIView *)view
               delegate:(id)delegate
             completion:(void (^)(void))completion;

- (void)hideNewGoodList;

@end
