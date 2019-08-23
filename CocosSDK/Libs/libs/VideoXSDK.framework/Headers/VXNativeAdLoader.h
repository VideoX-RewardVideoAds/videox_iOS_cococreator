//
//  VXNativeAdLoader.h
//  VideoXSDK
//
//  Created by 乔岩 on 2019/4/18.
//  Copyright © 2019 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VXProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface VXNativeAdLoader : NSObject



-(instancetype)init NS_UNAVAILABLE;
+(void)initialize NS_UNAVAILABLE;

+ (instancetype) shareInstance;

+ (void)loadNativeAdWithUnitID:(NSString *)unitId
                      delegate:(id<VXNativeAdDelegate>)delegate
            rootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
