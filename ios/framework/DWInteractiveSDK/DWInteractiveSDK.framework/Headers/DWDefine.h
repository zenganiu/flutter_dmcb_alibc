//
//  DWDefine.h
//  DWInteractiveSDK
//
//  Created by 凌言 on 16/4/7.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#ifndef DWDefine_h
#define DWDefine_h

#define DWCONFIGADAPTER @"DWCONFIGADAPTER"

#define DWNETWORKADAPTER @"dwnetwork"
#define DWIMGLOADERADAPTER @"dwimgloader"
#define DWUSERTRACKADAPTER @"dwusertrack"
#define DWCELLHANDLERADAPTER @"dwcellhandler"
#define DWEVENTADAPTER @"dwevent"
#define DWVIDEOSOURCEADAPTER @"videosource"
#define DWFOLLOWBTNAPTER @"dwfollowbtn"
#define DWADD2CARDADAPTER @"dwadd2card"
#define DWSHAREADAPTER @"dwshare"
#define DWLOGINSTATUSADAPTER @"dwloginstatus"
#define DWPMESGADAPTER @"dwpowermsg"
#define DWGOODLISTADAPTER @"dwgoodlist"

#define DWLIKESERVICEADAPTER @"likeservice"

#define DWChangePlayModeNotification @"DWChangePlayModeNotification"

//微淘浮层播放消失消息
#define kDWRecieveWeitaoFullScreenPlayViewWillDisappearNotification @"TBSNSFullScreenPlayerViewWillDisAppear"

typedef NS_ENUM(NSInteger, DWHPContentMode) {
    DWHPContentModeNone,
    DWHPContentModeImage,
    DWHPContentModeVideo,
};

typedef NS_ENUM(NSInteger, DWHPEvent) {
    DWHPVideoPlayerPrepared,
    DWHPVideoPlayerStartRendering,
    DWHPVideoPlayerFirstVideoFrameRendered,
    DWHPVideoPlayerTimeupdated,
    DWHPVideoPlayerFailedToStart,
    DWHPVideoPlayerPaused,
    DWHPVideoPlayerEnded,
    DWHPVideoPlayerError,
    DWHPVideoPlayerStalled,
    DWHPVideoPlayerInterrupted,
    DWHPVideoPlayerDataUserSEI,
    DWHPVideoPlayerDataNetworkTraffic,
    DWHPVideoPlayerWillBeRecycled,
    DWHPVideoPlayerException,
    DWHPVideoPlayerSeekingForward,
    DWHPVideoPlayerSeekingBackward,
    DWHPVideoPlayerViewTapped,
    DWHPVideoPlayerUnknown,
    DWHPImageLoadStarted,
    DWHPImageLoadFailed,
    DWHPImageLoadSucceed
};

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))

typedef NS_ENUM(NSInteger, DWHPErrorCode) {
    DWHPQueryVideoResourceFailed = (-(int)MKTAG(0xF8, 'Q', 'U', 'E')), // -1163219448
};



#endif /* DWDefine_h */
