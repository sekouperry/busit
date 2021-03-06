//
//  BIRest.h
//  BusStop
//
//  Created by Chris Woodard on 4/12/13.
//  Copyright (c) 2013 0xC0ffee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BIRest : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate> {
    BOOL isFinished;
    BOOL isScrewed;
}

@property (nonatomic, strong) NSMutableData *cumulativeData;
@property BOOL offlineMode;

typedef void (^ProgressUpdateBlock) (float newDownloadProgress);
@property (nonatomic, assign) long long downloadSize;
@property (nonatomic, assign) float downloadProgress;
/** Define this block to receive progress updates */
@property (nonatomic, copy) ProgressUpdateBlock progressUpdateBlock;


-(NSDictionary *)restToJSON:(NSString *)jsonURL paramStr:(NSString *)paramStr;
-(NSString *)strDataForURL:(NSString *)urlStr paramStr:(NSString *)paramStr;

// One Bus Away API
-(NSDictionary *)agencies;
-(NSDictionary *)agency;
-(NSDictionary *)routesForAgency;
-(NSDictionary *)stopsForRoute:(NSString *)routeId;
-(NSDictionary *)stop:(NSString *)stopId;   
-(NSDictionary *)scheduleForStop:(NSString *)stopId;
-(NSDictionary *)tripsForRoute:(NSString *)routeId;
-(NSDictionary *)tripDetailsForTrip:(NSString *)tripId;
-(NSDictionary *)vehiclesForAgency:(NSString *)agencyId;
-(NSDictionary *)stopsForLocationLat:(NSNumber *)lat Lon:(NSNumber *)lon;
-(NSDictionary *)arrivalsAndDeparturesForStop:(NSString *)stopId;

// One Bus Away API Helpers
/** The timestamps returned by the OBA API are not directly usable and must be divided by 1000 first. */
+(NSDate *)dateFromObaTimestamp:(NSString *)timestamp;

@end

