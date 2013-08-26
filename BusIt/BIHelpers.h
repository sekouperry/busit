//
//  BIHelpers.h
//  BusStop
//
//  Created by Lolcat on 8/4/13.
//  Copyright (c) 2013 0xC0ffee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@interface BIHelpers : NSObject

+ (void)drawCornersAroundView:(UIView *)view;
+ (void)drawAllCornersAroundView:(UIView *)view;
+ (NSString *)timeWithTimestamp:(NSString *)timestampString;
+ (NSString *)formattedDistanceFromStop:(NSNumber *)distanceFromStop;

@end
