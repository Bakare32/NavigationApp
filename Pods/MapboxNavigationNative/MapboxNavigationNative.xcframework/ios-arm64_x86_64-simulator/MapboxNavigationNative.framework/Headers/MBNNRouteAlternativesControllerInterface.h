// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRouteAlternativesOptions;
@class MBNNRoutingProfile;
@protocol MBNNRouteAlternativesObserver;

NS_SWIFT_NAME(RouteAlternativesControllerInterface)
@protocol MBNNRouteAlternativesControllerInterface
/** Start controller. If started RouteAlternative's events will be emitted. Started by default. */
- (void)start;
/** Stop controller. If stopped RouteAlternative's events will not be emitted. Started by default. */
- (void)stop;
/** Set `RoutingProfile` (Driving, Walking, Cycling, DrivingTraffic). */
- (void)setRouteProfileForProfile:(nonnull MBNNRoutingProfile *)profile;
/** Set RouteAlternativesOptions. */
- (void)setRouteAlternativesOptionsForOptions:(nonnull MBNNRouteAlternativesOptions *)options;
/** Add observer. Requests will not be sent if no one observer present. */
- (void)addObserverForObserver:(nonnull id<MBNNRouteAlternativesObserver>)observer;
/** Remove observer. Requests will not be sent if no one observer present. */
- (void)removeObserverForObserver:(nonnull id<MBNNRouteAlternativesObserver>)observer;
/** Remove all observers. Requests will not be sent if no one observer present. */
- (void)removeAllObservers;
/** Make alternative route request immediately. Has no effect if the controller is stopped. */
- (void)refreshImmediately;
/**
 * Enable polling alternative routes if no one alternative exist.
 *  This will help avoid a situation when server has not returned any alternatives, but may return them later during the ride.
 *  Now it can consume a lot of traffic!
 */
- (void)enableEmptyAlternativesRefreshForEnable:(BOOL)enable;
@end
