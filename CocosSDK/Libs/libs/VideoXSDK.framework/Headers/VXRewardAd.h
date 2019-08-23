//
//  DCGRewardAd.h
//  DotcAd
//
//  Created by user on 2018/8/2.
//  Copyright © 2018年 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VXProtocol.h"

@interface VXRewardAd : NSObject

-(instancetype)init NS_UNAVAILABLE;
+(void)initialize NS_UNAVAILABLE;

+ (instancetype) shareInstance;

@property (nonatomic, weak) id<VXRewardAdLoadDelegate> loadDelegate;
@property (nonatomic, weak) id<VXRewardAdPlayDelegate> playDelegate;

+ (void)loadRewardAdWithUnitID:(NSString *)unitId;

+ (void)playAdWithUnitID:(NSString *)unitId;

+ (void)playAdWithUnitID:(NSString *)unitId fromViewController:(nullable UIViewController *)viewController;

+ (BOOL)isAdReady:(NSString *)unitId;

@end



