// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRouteAlternative;

NS_SWIFT_NAME(RouteAlternativesObserver)
@protocol MBNNRouteAlternativesObserver
/**
 * This callback is invoked when controller get alternatives from router that changed from alternatives from last callback
 *  or if we pass some route and fork point became behind us.
 *  Discarded routes are not considered by comparison (see @return)
 *  Controller do not make cross-comparison. If route's order will change this callback will be invoked.
 *  @param  routeAlternatives  new list of alternative routes.
 *  @return indexes of dropped routes. If we return [0, 1] it means that alternative routes with indexes 0 and 1 will be dropped.
 */
- (nonnull NSArray<NSNumber *> *)onRouteAlternativesChangedForRouteAlternatives:(nonnull NSArray<MBNNRouteAlternative *> *)routeAlternatives;
@end
