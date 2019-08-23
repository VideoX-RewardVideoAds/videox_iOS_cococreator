//
//  DCGInterstitialAd.h
//  DotcAd
//
//  Created by user on 2018/8/2.
//  Copyright © 2018年 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VXProtocol.h"

@interface VXInterstitialAd : NSObject

@property (nonatomic, copy, readonly) NSString *slotId;

- (instancetype)initWithUnitID:(NSString *)unitID adLoadDelegate:(id <VXInterstitialAdLoadDelegate>)loadDelegate;

- (void)playAdWithAdPlayDelegate:(id <VXInterstitialAdPlayDelegate>)playDelegate;

- (BOOL)isAdReady;

@end
