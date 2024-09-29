// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class MBNNRouteBearing;

NS_SWIFT_NAME(RouteCoordinate)
__attribute__((visibility ("default")))
@interface MBNNRouteCoordinate : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                                   bearing:(nonnull MBNNRouteBearing *)bearing
                                    radius:(float)radius
                                  approach:(nonnull NSString *)approach
                              waypointName:(nonnull NSString *)waypointName;

/** {longitude},{latitude} coordinate */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 * Bearing contains angle and deviation
 * It could be optional. If bearing is not available please pass f32 max values
 */
@property (nonatomic, readonly, nonnull) MBNNRouteBearing *bearing;

/**
 * The maximum distance a coordinate can be moved to snap to the road network in meters.
 * Values can be any number greater than 0.
 */
@property (nonatomic, readonly) float radius;

/**
 * Indicating the side of the road from which to approach waypoints in a requested route.
 * Accepts unrestricted (default, route can arrive at the waypoint from either side of the road)
 * or curb (route will arrive at the waypoint on the driving_side of the region).
 */
@property (nonatomic, readonly, nonnull, copy) NSString *approach;

/**
 * Names for entry in the list of coordinates, used for the arrival instruction in banners and voice instructions.
 * Value can be any string, and the total number of all characters cannot exceed 500.
 */
@property (nonatomic, readonly, nonnull, copy) NSString *waypointName;


- (BOOL)isEqualToRouteCoordinate:(nonnull MBNNRouteCoordinate *)other;

@end
