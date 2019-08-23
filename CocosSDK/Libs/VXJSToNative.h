//
//  VXJSToNative.h
//  DotcAd
//
//  Created by user on 2018/11/20.
//  Copyright © 2018年 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VXJSToNative : NSObject

#pragma mark - =============初始化=============

/**
 初始化广告SDK
 */
+ (void)initAdsSDK;

/**
 初始化上报
 */
+ (void)initReporterSDK;

#pragma mark - =============广告=============

/**
 加载激励视频广告

 @param slotId 广告id
 */
+ (void)loadRewardsAds:(NSString *)slotId;

/**
 播放激励视频广告

 @param slotId 广告id
 */
+ (void)playRewardsAds:(NSString *)slotId;

/**
 激励视频广告加载状态

 @param slotId 广告id
 @return 加载状态
 */
+ (BOOL)rewardsAdsReady:(NSString *)slotId;

/**
 加载插屏广告

 @param slotId 广告id
 */
+ (void)loadInterstitialAds:(NSString *)slotId;

/**
 播放插屏广告

 @param slotId 广告id
 */
+ (void)playInterstitialAds:(NSString *)slotId;

/**
 插屏广告加载状态

 @param slotId 广告id
 @return 加载状态
 */
+(bool)interstitialAdsReady:(NSString *)slotId;

/**
 banner广告加载

 @param slotId 广告id
 */
+ (void)showBannerAds:(NSString *)slotId;


/**
 设置debug模式

 @param isDebug 是否为debug模式
 */
+ (void)setDebugMode:(BOOL)isDebug;

+ (void)showToast:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
