//
//  VXJSToNative.m
//  DotcAd
//
//  Created by user on 2018/11/20.
//  Copyright © 2018年 DotC. All rights reserved.
//

#if __has_include("VXReporter.h")
#import "VXReporter.h"
#endif

#import "VXJSToNative.h"
#import <AVFoundation/AVFoundation.h>
#import <VideoXSDK/VideoXSDK.h>
#include <ScriptingCore.h>
#import <cocos/scripting/js-bindings/jswrapper/SeApi.h>
#import <cocos2d.h>

#import "RootViewController.h"

using namespace cocos2d;
@interface VXJSToNative()<VXBannerAdDelegate,
VXRewardAdLoadDelegate,
VXRewardAdPlayDelegate,
VXInterstitialAdLoadDelegate,
VXInterstitialAdPlayDelegate,
VXNativeAdDelegate,
VXSplashAdDelegate>

@property (nonatomic, strong) NSMutableDictionary *interAdsDic;
@property (nonatomic, strong) VXBannerAd *bannerAd;
@property (nonatomic, strong) VXSplashAd *splashAd;

@end

#pragma mark - define

/* 广告SDK初始化参数 */
static NSString * pubId = @"xxxx";
static NSString * pubKey = @"xxxx";

@implementation VXJSToNative

#pragma mark - private api
+(instancetype)shareManager{
    
    static VXJSToNative * manager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[VXJSToNative alloc] init];
        [manager setUpDelegate];
        manager.interAdsDic = [NSMutableDictionary dictionary];
    });
    return manager;
}

-(void)setUpDelegate{
    
    [VXRewardAd shareInstance].loadDelegate = self;
    [VXRewardAd shareInstance].playDelegate = self;
}

#pragma mark - public api
+ (void)initAdsSDK{
    
    [[VXJSToNative shareManager] setUpDelegate];
    [VideoXSDK initWithAppID:pubId pubKey:pubKey];
}

+ (void)showSplashAd:(NSString *)slotId{
    
    VXSplashAd *splash = [[VXSplashAd alloc] initWithAdUnitId:slotId];
    splash.delegate = [VXJSToNative shareManager];
    [VXJSToNative shareManager].splashAd = splash;
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    [splash loadAdAndShowInWindow:window];
}

+ (void)loadRewardsAds:(NSString *)slotId{
    
    [VXRewardAd loadRewardAdWithUnitID:slotId];
    
}

+(void)playRewardsAds:(NSString *)slotId{
    
    [VXRewardAd playAdWithUnitID:slotId];
}

+(BOOL)rewardsAdsReady:(NSString *)slotId{
    
    BOOL result = [VXRewardAd isAdReady:slotId];
    
    [self nativeToJS:@"isRewardAdReady" args:@(result).stringValue arg2:Nil extra:Nil];
    
    return result;
}

+(void)loadInterstitialAds:(NSString *)slotId{
    
    if (slotId.length == 0) {
        return;
    }
    
    VXInterstitialAd *interAds = [[VXInterstitialAd alloc] initWithUnitID:slotId adLoadDelegate:[VXJSToNative shareManager]];
    [[VXJSToNative shareManager].interAdsDic setObject:interAds forKey:slotId];
}

+ (void)playInterstitialAds:(NSString *)slotId{
    
    if (slotId.length == 0) {
        return;
    }
    
    VXInterstitialAd *interAds = [[VXJSToNative shareManager].interAdsDic objectForKey:slotId];
    
    if (!interAds) {
        return;
    }
    
    [interAds playAdWithAdPlayDelegate:[VXJSToNative shareManager]];
}

+(bool)interstitialAdsReady:(NSString *)slotId{
    
    if (slotId.length == 0) {
        return NO;
    }
    
    VXInterstitialAd *interAds = [[VXJSToNative shareManager].interAdsDic objectForKey:slotId];
    
    if (!interAds) {
        return NO;
    }
    
    BOOL result = [interAds isAdReady];
    
    [self nativeToJS:@"isInterstitialAdReady" args:@(result).stringValue arg2:nil extra:nil];
    return result;
}


+(void)showBannerAds:(NSString *)slotId{

    VXBannerAd *banner = [[VXBannerAd alloc] initWithUnitID:slotId rootViewController:[UIApplication sharedApplication].keyWindow.rootViewController delegate:[VXJSToNative shareManager]];
 
    [VXJSToNative shareManager].bannerAd = banner;
    
}

+(void)setDebugMode:(BOOL)isDebug{
    [DUDataReport setDebug:isDebug];
    [DCGAds setLogLevel:DCGLogLevelDebug];
}

#pragma mark - DCGRewardAdLoadDelegate
- (void)adLoadSuccessWithUnitID:(NSString *)unitID{
    
    [VXJSToNative nativeToJS:@"onRewardAdLoadSuccess" args:unitID arg2:nil extra:nil];
}
- (void)adLoadFailedUnitID:(NSString *)unitID error:(NSString *)error{
    
    [VXJSToNative nativeToJS:@"onRewardAdLoadError" args:unitID arg2:error extra:nil];
}

#pragma mark - DCGRewardAdPlayDelegate
- (void)adDidOpen:(NSString *)unitID{
    
    [VXJSToNative nativeToJS:@"onRewardAdLoadOnShow" args:unitID arg2:nil extra:nil];
}
- (void)adDidClose:(NSString *)unitID reward:(BOOL)shouldReward{
    
    [VXJSToNative nativeToJS:@"onRewardAdLoadOnClose" args:unitID arg2:@(shouldReward).stringValue extra:nil];
}
- (void)didClickAd:(NSString *)unitID{
    
    [VXJSToNative nativeToJS:@"onRewardAdLoadClick" args:unitID arg2:nil extra:nil];
}

- (void)adFailedToOpen:(NSString *)unitID error:(NSError *)error{
    
    [VXJSToNative nativeToJS:@"onRewardAdLoadOnShowError" args:unitID arg2:error.description extra:nil];
}

#pragma mark - VXInterstitialAdLoadDelegate
- (void)interAdLoadSuccessWithUnitID:(NSString *)unitID{
    
    [VXJSToNative nativeToJS:@"onInterstitialAdLoadSuccess" args:unitID arg2:nil extra:nil];
}
- (void)interAdLoadFailedUnitID:(NSString *)unitID error:(NSError *)error{
    
    [VXJSToNative nativeToJS:@"onInterstitialAdLoadError" args:unitID arg2:error.description extra:nil];
}

#pragma mark - VXInterstitialAdPlayDelegate

- (void)interAdDidOpen:(NSString *)unitID{
    [VXJSToNative nativeToJS:@"onInterstitialAdOpen" args:unitID arg2:nil extra:nil];
}
- (void)interAdDidClose:(NSString *)unitID{
    
    [VXJSToNative nativeToJS:@"onInterstitialAdClose" args:unitID arg2:nil extra:nil];

    if (unitID.length > 0) {
        [self.interAdsDic removeObjectForKey:unitID];
    }
}

- (void)interAdDidClickAd:(NSString *)unitID{
    [VXJSToNative nativeToJS:@"onInterstitialAdClick" args:unitID arg2:nil extra:nil];
}
- (void)interAdFailedToOpen:(NSString *)unitID error:(NSError *)errorMsg{
    
    [VXJSToNative nativeToJS:@"onInterstitialAdLoadError" args:unitID arg2:errorMsg.description extra:nil];
    
    if (unitID.length > 0) {
        [self.interAdsDic removeObjectForKey:unitID];
    }
}

#pragma mark - VXBannerAdDelegate
-(void)bannerAdLoadSuccess{
    
    [self.bannerAd showBanner];
}


-(void)bannerAdShowError:(NSError *)error{
    
    [VXJSToNative nativeToJS:@"onBannerAdShowError" args:error.description arg2:nil extra:nil];
}

-(void)bannerAdDidClosed{
    [VXJSToNative nativeToJS:@"onBannerAdDidClosed" args:nil arg2:nil extra:nil];
}

-(void)bannerAdDidClicked{
    [VXJSToNative nativeToJS:@"onBannerAdDidClicked" args:nil arg2:nil extra:nil];
}

#pragma mark - VXSplashAdDelegate
-(void)splashAdDidLoad:(VXSplashAd *)splashAd{
    
    [VXJSToNative nativeToJS:@"splashAdDidLoad" args:nil arg2:nil extra:nil];
}

-(void)splashAdDidClick:(VXSplashAd *)splashAd{
    
    [VXJSToNative nativeToJS:@"splashAdDidClick" args:nil arg2:nil extra:nil];
}

-(void)splashAdWillShow:(VXSplashAd *)splashAd{
    [VXJSToNative nativeToJS:@"splashAdWillShow" args:nil arg2:nil extra:nil];
    
}

-(void)splashAdDidClose:(VXSplashAd *)splashAd{
    
    [VXJSToNative nativeToJS:@"splashAdDidClose" args:nil arg2:nil extra:nil];
}

-(void)splashAd:(VXSplashAd *)splashAd didFailWithError:(NSError *)error{
    [VXJSToNative nativeToJS:@"splashAdDidFailWithError" args:error.description arg2:nil extra:nil];
    
}

+ (void)nativeToJS:(NSString *)functionName args:(NSString *)arg1 arg2:(NSString *)arg2 extra:(NSArray<NSString *> *)extra{

    NSMutableString *str = [NSMutableString stringWithFormat:@"%@('%@'",functionName,arg1];
    if (arg2.length > 0) {
        [str appendString:[NSString stringWithFormat:@",'%@'",arg2]];
    }
    
    for (NSString *arg in extra) {
        [str appendString:[NSString stringWithFormat:@",'%@'",arg]];
    }
    
    [str appendString:@")"];
    
    std::string jsCallStr = [str UTF8String];
    se::Value *ret = new se::Value();
    se::ScriptEngine::getInstance()->evalString(jsCallStr.c_str() , -1 , ret);
}

+ (void)showToast:(NSString *)message{

//    NSLog(@"/n");
//    NSLog(@"🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣");
//    NSLog(@"%@",message);
//    NSLog(@"🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣");    
}


@end
