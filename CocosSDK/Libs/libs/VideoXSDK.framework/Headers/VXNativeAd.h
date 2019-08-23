//
//  VXNativeAd.h
//  DotcAd
//
//  Created by 乔岩 on 2019/4/18.
//  Copyright © 2019 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VXNativeAd : NSObject

@property (nonatomic, copy, nullable) NSString *unitId;


@property (nonatomic, assign) NSInteger adType;
/**
 adSource
 */
@property (nonatomic, copy, nullable) NSString *adSource;
/**
 ad icon
 */
@property (nonatomic, copy, nullable) NSString *adIconUrlString;
/**
 adMediaUrlString
 */
@property (nonatomic, copy, nullable) NSString *adMediaUrlString;
/**
 Typed access to the headline that the advertiser entered when they created their ad. This is usually the ad's main title.
 */
@property (nonatomic, copy, nullable) NSString *adTitle;
/**
 Typed access to the body text, truncated at length 90, which contains the text that the advertiser entered when they created their ad. This often tells people what the ad is promoting.
 */
@property (nonatomic, copy, nullable) NSString *adBodyText;
/**
 Typed access to the call to action phrase of the ad, for example "Install Now".
 */
@property (nonatomic, copy, nullable) NSString *adActionTitle;
/**
 The aspect ratio of the media view visual content.
 */
@property (nonatomic, assign) CGFloat aspectRatio;
/**
 Call isAdValid to check whether native ad is valid & internal consistent prior rendering using its properties. If
 rendering is done as part of the loadAd callback, it is guarantee to be consistent
 */
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;

@property (nonatomic, getter=isRegistered, readonly) BOOL registered;

- (void)registerViewForAdView:(UIView *)adView
               viewController:(nullable UIViewController *)viewController
               clickableViews:(nullable NSArray<UIView *> *)clickableViews;

- (UIView *)getAdView;

- (__kindof UIView *)getMediaImageView;
- (__kindof UIView *)getIconImageView;
- (UILabel *)getTitleLabel;
- (UILabel *)getBodyLabel;
- (UILabel *)getSourceLabel;
- (UIButton *)getActionButton;

- (void)configMediaImageView:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
