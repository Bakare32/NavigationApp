// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNRerouteState.h"
#import "MBNNRerouteStateCallback.h"

@class MBNNRouteDescription;

NS_SWIFT_NAME(RerouteManager)
@protocol MBNNRerouteManager
/** Reroute state */
- (MBNNRerouteState)state;
/**
 * Invoked whenever re-route is needed. For instance when a driver is off-route. Called just after
 * an off-route event.
 */
- (void)rerouteForDescription:(nonnull MBNNRouteDescription *)description;
/**
 * Invoked when re-route is not needed anymore (for instance when driver returns to previous route).
 * Might be ignored depending on [RerouteState] e.g. if a route has been fetched it does not make sense to interrupt re-routing
 */
- (void)interrupt;
- (void)setRerouteStateCallbackForCallback:(nullable MBNNRerouteStateCallback)callback;
@end
