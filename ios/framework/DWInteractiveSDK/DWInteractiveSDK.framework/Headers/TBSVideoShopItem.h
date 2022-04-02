//
//  TBSVideoShopItem.h
//  Pods
//
//  Created by yingfang on 2017/7/25.
//
//

#import <Foundation/Foundation.h>

@interface TBSVideoShopItem : NSObject

@property (strong, nonatomic) NSString* itemId;
@property (strong, nonatomic) NSString* picUrl;
@property (strong, nonatomic) NSString* price;
@property (strong, nonatomic) NSDictionary* promotionInfo;
@property (strong, nonatomic) NSString* promotionTitle;
@property (strong, nonatomic) NSString* targetUrl;
@property (strong, nonatomic) NSString* title;
@property (strong, nonatomic) NSDictionary* promotionPic;
@property (strong, nonatomic) NSDictionary* taokeInfo;

- (void)updateVideoShopItemData:(NSDictionary*)json;

@end
