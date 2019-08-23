//
//  DCGBannerAd.h
//  DotcAd
//
//  Created by user on 2018/12/20.
//  Copyright © 2018年 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VXProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface VXBannerAd : NSObject

@property (nonatomic, copy, readonly) NSString  *unitId;

@property (nonatomic, strong) UIView *bannerView;
/**
 初始化广告

 @param unitID 广告Id
 @param size 广告位置大小
 @param controller 显示广告的VC
 @param delegate 代理
 @return DCGBannerAd
 */
- (instancetype)initWithUnitID:(NSString *)unitID
            rootViewController:(UIViewController *)controller
                      delegate:(id<VXBannerAdDelegate>)delegate;


- (void)showBanner;

- (void)destroyBanner;


@end

NS_ASSUME_NONNULL_END
