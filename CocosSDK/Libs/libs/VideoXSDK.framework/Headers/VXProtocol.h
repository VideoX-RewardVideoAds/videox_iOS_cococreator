//
//  VXProtocol.h
//  DotcAd
//
//  Created by 乔岩 on 2019/4/19.
//  Copyright © 2019 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class VXNativeAd;

#pragma mark - Native Delegate
@protocol VXNativeAdDelegate <NSObject>

- (void)nativeAdLoadSuccess:(VXNativeAd *)nativeAd unitID:(NSString *)unitID;
- (void)nativeAdLoadFailedUnitID:(NSString *)unitID error:(NSError *)error;
- (void)nativeAdDidDidClick:(VXNativeAd *)nativeAd unitID:(NSString *)unitID;

@end

#pragma mark - InterstitialAdDelegate
@protocol VXInterstitialAdLoadDelegate <NSObject>
@optional
- (void)interAdLoadSuccessWithUnitID:(NSString *)unitID;
- (void)interAdLoadFailedUnitID:(NSString *)unitID error:(NSError *)error;

@end


@protocol VXInterstitialAdPlayDelegate <NSObject>
@optional
- (void)interAdDidOpen:(NSString *)unitID;
- (void)interAdDidClose:(NSString *)unitID;
- (void)interAdDidClickAd:(NSString *)unitID;
- (void)interAdFailedToOpen:(NSString *)unitID error:(NSError *)errorMsg;
@end

#pragma mark - RewardAdDelegate
@protocol VXRewardAdLoadDelegate <NSObject>
@optional
- (void)adLoadSuccessWithUnitID:(NSString *)unitID;
- (void)adLoadFailedUnitID:(NSString *)unitID error:(NSString *)error;

@end

@protocol VXRewardAdPlayDelegate <NSObject>
@optional
- (void)adDidOpen:(NSString *)unitID;
- (void)adDidClose:(NSString *)unitID reward:(BOOL)shouldReward;
- (void)didClickAd:(NSString *)unitID;
- (void)adFailedToOpen:(NSString *)unitID error:(NSError *)error;
@end


@protocol VXBannerAdDelegate <NSObject>

@optional
- (void)bannerAdLoadSuccess;

- (void)bannerAdShowError:(NSError *)error;

- (void)bannerAdDidClicked;

- (void)bannerAdDidClosed;

//- (void)bannerResume

@end

NS_ASSUME_NONNULL_END


