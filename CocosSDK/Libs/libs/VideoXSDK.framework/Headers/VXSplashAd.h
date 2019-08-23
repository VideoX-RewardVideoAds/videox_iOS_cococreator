//
//  VXSplashAd.h
//  DotcAd
//
//  Created by 乔岩 on 2019/6/19.
//  Copyright © 2019 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class VXSplashAd;

@protocol VXSplashAdDelegate <NSObject>

@optional
/**
 This method is called when splash ad loaded successfully.
 */
- (void)splashAdDidLoad:(VXSplashAd *)splashAd;

/**
 This method is called when splash ad failed to load.
 @param errorMsg : error message
 */
- (void)splashAd:(VXSplashAd *)splashAd didFailWithError:(NSError *)error;

/**
 This method is called when splash ad slot will be showing.
 */
- (void)splashAdWillShow:(VXSplashAd *)splashAd;

/**
 This method is called when splash ad is clicked.
 */
- (void)splashAdDidClick:(VXSplashAd *)splashAd;

/**
 This method is called when splash ad is closed.
 */
- (void)splashAdDidClose:(VXSplashAd *)splashAd;


@end

@interface VXSplashAd : NSObject

@property (nonatomic, readonly, copy) NSString *adUnitId;

@property (nonatomic, weak, nullable) id<VXSplashAdDelegate> delegate;

- (instancetype)initWithAdUnitId:(NSString *)unitId;

- (void)loadAdAndShowInWindow:(UIWindow *)window;

@end

NS_ASSUME_NONNULL_END
