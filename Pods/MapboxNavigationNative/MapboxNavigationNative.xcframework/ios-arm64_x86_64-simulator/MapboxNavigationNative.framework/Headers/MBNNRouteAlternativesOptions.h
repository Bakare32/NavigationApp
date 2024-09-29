// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(RouteAlternativesOptions)
__attribute__((visibility ("default")))
@interface MBNNRouteAlternativesOptions : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithRefreshIntervalSeconds:(double)refreshIntervalSeconds
                          minTimeBeforeManeuverSeconds:(double)minTimeBeforeManeuverSeconds
                                      lookAheadSeconds:(double)lookAheadSeconds;

/** Refresh alternative routes interval. 3 minutes by default. Minimum 30 seconds. */
@property (nonatomic, readonly) double refreshIntervalSeconds;

/**
 * Remove routes if travel time to fork point less or equal this time.
 *  0 by default.
 */
@property (nonatomic, readonly) double minTimeBeforeManeuverSeconds;

/**
 * It is used to calculate the position for route requests.
 * For example 0 means that we use the current position.
 * 1 second means that when we request new alternatives we will use currentPosition + 1 second by current route.
 * Not supported at this moment.
 */
@property (nonatomic, readonly) double lookAheadSeconds;


@end
