// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import "MBNNRouterCallback_Internal.h"
#import "MBNNRouterRefreshCallback_Internal.h"

@class MBNNRouteRefreshOptions;

NS_SWIFT_NAME(RouterInterface)
@protocol MBNNRouterInterface
- (uint64_t)getRouteForDirectionsUri:(nonnull NSString *)directionsUri
                            callback:(nonnull MBNNRouterCallback)callback;
- (uint64_t)getRouteRefreshForOptions:(nonnull MBNNRouteRefreshOptions *)options
                                route:(nonnull NSString *)route
                             callback:(nonnull MBNNRouterRefreshCallback)callback;
/**
 * Cancels a specific route request.
 *
 * @see `getRoute` or `getRouteRefresh`. Cancels router requests.
 */
- (void)cancelRequestForToken:(uint64_t)token;
/** Interrupts all in-progress requests. */
- (void)cancelAll;
@end
