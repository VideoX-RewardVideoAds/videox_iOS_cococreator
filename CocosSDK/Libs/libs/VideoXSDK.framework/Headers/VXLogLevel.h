//
//  VXLogLevel.h
//  VideoXSDK
//
//  Created by chenXu on 2019/1/6.
//  Copyright © 2019 DotC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, VXLogLevel) {
    VXLogLevelAll   = 0,
    VXLogLevelTrace = 10,
    VXLogLevelDebug = 20,
    VXLogLevelInfo  = 30,
    VXLogLevelWarn  = 40,
    VXLogLevelError = 50,
    VXLogLevelOff   = 70
};


