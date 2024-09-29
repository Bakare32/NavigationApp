// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRouteIntersection;

/** New route with additional information about where this route first deviates from the current route. */
NS_SWIFT_NAME(RouteAlternative)
__attribute__((visibility ("default")))
@interface MBNNRouteAlternative : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithRoute:(nonnull NSString *)route
                     currentRouteFork:(nonnull MBNNRouteIntersection *)currentRouteFork
                 alternativeRouteFork:(nonnull MBNNRouteIntersection *)alternativeRouteFork;

/** New alternative route */
@property (nonatomic, readonly, nonnull, copy) NSString *route;

/**
 * Current route's segment and leg where alternative route first deviates from the current route.
 * Can be used to find the moment when the puck is near the fork route point.
 */
@property (nonatomic, readonly, nonnull) MBNNRouteIntersection *currentRouteFork;

/**
 * Alternative route's segment and leg where alternative route first deviates from the current route.
 * Can be used to skip the common part of the alternative route when drawing an alternate route.
 */
@property (nonatomic, readonly, nonnull) MBNNRouteIntersection *alternativeRouteFork;


@end
