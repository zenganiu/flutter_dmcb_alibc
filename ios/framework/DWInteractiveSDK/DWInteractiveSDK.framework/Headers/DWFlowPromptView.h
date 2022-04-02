//
//  DWFlowPromptView.h
//  Pods
//
//  Created by wentao.wwt on 2017/4/5.
//
//

#import <UIKit/UIKit.h>


@interface DWFlowPromptView : UIView

- (void) setUpView;

@property (nonatomic, strong) NSString *titleText;
@property (nonatomic, strong) NSString *btnText;

@property (nonatomic, assign) BOOL btnHidden;

@property (nonatomic, copy) dispatch_block_t btnClickBlock;


@end
