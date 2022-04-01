//
//  TBMPBPlayerManager.h
//  TBMediaPlayerBundle
//
//  Created by qiufu on 11/09/2017.
//  Copyright © 2017 CX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBMediaPlayerBundle/TBMPBPlayerView.h>
#import <TBMediaPlayerBundle/TBMPBPlayerProtocol.h>
#import <TBMediaPlayerBundle/TBMPBPlayerContext.h>

@interface TBMPBPlayerManager : NSObject

#pragma mark - Manager
+ (instancetype)sharedManager;
@property (strong, readonly, nonatomic) NSMutableDictionary<NSString *, UIView<TBMPBPlayerProtocol> *> *playerDictionary; // 使用对象的内存地址作为 key。
- (UIView<TBMPBPlayerProtocol> *)playerForWrapper:(TBMPBPlayerView *)wrapper;
- (void)removePlayerOfWrapper:(TBMPBPlayerView *)wrapper;
- (NSUInteger)getCurrentPlayerCoreCount;


#pragma mark - Util
+ (UIView<TBMPBPlayerProtocol> *)getPlayerInstanceWithMediaURL:(NSString *)url options:(TBMPBPlayerOptions *)options;
@end

