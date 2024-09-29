// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRouteCoordinate;

NS_SWIFT_NAME(RouteDescription)
__attribute__((visibility ("default")))
@interface MBNNRouteDescription : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithCoordinates:(nonnull NSArray<MBNNRouteCoordinate *> *)coordinates
                                  waypoints:(nonnull NSArray<NSNumber *> *)waypoints;

/**
 * List of {longitude},{latitude} coordinate pairs to visit in order.
 * There can be between two and 25 coordinates for most requests, or up to three coordinates for driving-traffic requests.
 */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNRouteCoordinate *> *coordinates;

/** List indicating which input coordinates should be treated as waypoints */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *waypoints;


- (BOOL)isEqualToRouteDescription:(nonnull MBNNRouteDescription *)other;

@end
