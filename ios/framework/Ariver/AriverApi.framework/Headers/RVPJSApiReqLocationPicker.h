//
//  RVPJSApiReqLocationPicker.h
//  AriverApi
//
//  Created by 百喻 on 2019/4/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <AriverKernel/RVKJSApiRequestBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface RVPJSApiReqLocationPicker : RVKJSApiRequestBase

@property (nonatomic,copy) NSString *title;
@property (nonatomic,strong) NSString *sendBtnText;
@property (nonatomic,strong) NSNumber *latitude;
@property (nonatomic,strong) NSNumber *longitude;
@property (nonatomic,copy) NSString *mode;
@property (nonatomic,strong) NSNumber *showTab;
@property (nonatomic,strong) NSNumber *coordinateHasConverted;
@property (nonatomic,strong) NSNumber *horizontalAccuracy;
@property (nonatomic,strong) NSDictionary *presetPOI;
@property (nonatomic,strong) NSDictionary *locatePOI;
@property (nonatomic,strong) NSNumber *showHideLocation;
@property (nonatomic,strong) NSNumber *showLocatedCity;
@property (nonatomic,copy) NSString *appKey;
@property (nonatomic,copy) NSString *keyword;
@property (nonatomic,copy) NSString *city;
@property (nonatomic,strong) NSNumber *needReGeocode;
@property (nonatomic,strong) NSNumber *isOversea;
@property (nonatomic,copy) NSString *searchHint;
@property (nonatomic,strong) NSNumber *showPoiDistance;
@property (nonatomic,strong) NSNumber *showPoiActions;
@property (nonatomic,copy) NSString *poiType;
@property (nonatomic,strong) NSNumber *isShowConfirmSelectBtn;
@property (nonatomic,strong) NSNumber *scale;
@property (nonatomic,strong) NSNumber *fullMap;
@property (nonatomic,strong) NSNumber *hideSearch;
@property (nonatomic,copy) NSString *markerTitle;

@end

NS_ASSUME_NONNULL_END
